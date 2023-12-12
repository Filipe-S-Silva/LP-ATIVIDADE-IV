#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

struct informacoesProduto
{
    char nome[200];
    float preco;
    int quantidadeEstoque;
    float valorTotal;
};

void menu()
{
    printf("CÓDIGO -------------------- AÇÃO\n");
    printf("\n");
    printf("  1 ----------------- REALIZAR UMA COMPRA\n");
    printf("  2 ----------------- CONSULTAR ESTOQUE\n");
    printf("  3 -----------------  SAIR DO PROGRAMA\n");
}

int valorTotal(int quantidadeEstoque, float preco)
{
    float valorAPagar;
    return valorAPagar = quantidadeEstoque * preco;
}

void limpatela()
{
    system("cls || clear");
}

int main()
{

    // variaveis
    setlocale(LC_ALL, "portuguese");
    int codigo;
    int posicao = 0;
    struct informacoesProduto produto[999];
    int quantidadeTotal = 0;
    int i;
    float valorAPagar = 0;

    // usuario

    do
    {

        menu();

        printf("Informe o código desejado: ");
        scanf("%d", &codigo);

        sleep(1);

        fflush(stdin);

        switch (codigo)
        {
        case 1:
            printf("Informe o nome do produto: ");
            gets(produto[posicao].nome);

            fflush(stdin);

            printf("Informe o preço: R$");
            scanf("%f", &produto[posicao].preco);

            printf("Informe a quantidade estoque: ");
            scanf("%d", &produto[posicao].quantidadeEstoque);

            produto[posicao].valorTotal = valorTotal(produto[posicao].quantidadeEstoque, produto[posicao].preco);

            valorAPagar += produto[posicao].valorTotal;

            quantidadeTotal += produto[posicao].quantidadeEstoque;

            posicao++;

            printf("PRODUTO REGISTRADO\n");
            sleep(2);
            limpatela();

            break;

        case 2:
            limpatela();
            printf("ESTOQUE\n");

            printf("Quantidade total de produtos: %d\n", quantidadeTotal);
            printf("Valor Total a pagar pelo estoque: R$%.2f\n", valorAPagar);
            for (i = 0; i < posicao; i++)
            {
                printf("Quantidade do produto %s: %d\n", produto[i].nome, produto[i].quantidadeEstoque);
                printf("Valor total a pagar do produto: %.2f\n", produto[i].valorTotal);
            }
            break;
            sleep(2);
            printf("\n");
        case 3:
            sleep(2);
            printf("Finalizando o sistema......\n");
            sleep(2);
            printf("Encerrando o sistema............\n");
            sleep(2);
            limpatela();
            printf("Sistema encerrado............\n");
            break;

        default:
            printf("código inválido\ntente novamente");
            sleep(2);
            limpatela();
            break;
        }
    } while (codigo != 3);
    getchar();
    return 0;
}
