#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

struct representacaoConta
{
    char numeroDaConta[200];
    
    char nomeTitular[200];

    float saldo;

    char tipoConta[200];
};

void limpatela()
{
    system("cls || clear");
}

void acao()
{
    printf("conta cadastrada......\n");
    sleep(3);
    limpatela();
}

void menu()
{
    printf("1 --------- DEPÓSITO\n");
    printf("2 ---------   SAQUE\n");
    printf("3 ------ CONSULTAR SALDO\n");
    printf("4 --------- FINALIZAR\n");
    printf("\n");
}

int main()
{

    // variaveis
    setlocale(LC_ALL, "portuguese");
    
    struct representacaoConta conta;

    float acoesNaConta = 0;

    int codigo;

    // usuario
    printf("Informe o número da conta: ");
    gets(conta.numeroDaConta);

    printf("Informe o nome do(a) titular: ");
    gets(conta.nomeTitular);

    fflush(stdin);

    printf("Informe o valor do deposito: R$");
    scanf("%f", &conta.saldo);

    fflush(stdin);

    printf("Informe o tipo de conta: ");
    gets(conta.tipoConta);

    acao();
    // mostrar
    do
    {
        menu();

        printf("Informe o código desejado: ");
        scanf("%d", &codigo);

        fflush(stdin);
        switch (codigo)
        {
        case 1:
            sleep(1);
            limpatela();
            printf("Informe o valor do deposito: R$");
            scanf("%f", &acoesNaConta);
            conta.saldo += acoesNaConta;
            printf("Valor depósitado com sucesso.......\n");
            sleep(2);
            limpatela();
            break;
        case 2:
            sleep(1);
            limpatela();
            printf("Informe o valor do saque: R$");
            scanf("%f", &acoesNaConta);
            conta.saldo -= acoesNaConta;
            printf("Buscando saldo disponivel.......\n");
            sleep(2);
            printf("Retire o valor no local indicado.......\n");
            sleep(2);
            limpatela();
            break;
        case 3:
            sleep(1);
            limpatela();
            printf("Buscando saldo disponivel.......\n");
            sleep(2);
            printf("Valor disponivel: R$ %.2f", conta.saldo);
            sleep(5);
            limpatela();
            break;
        case 4:
            sleep(2);
            printf("Finalizando o sistema......\n");
            sleep(2);
            printf("Encerrando o sistema............\n");
            sleep(2);
            limpatela();
            printf("Sistema encerrado............\n");
            break;
        default:
            sleep(1);
            printf("CÓDIGO INVÁLIDO\nTENTE NOVAMENTE\n");
            break;
        }

        fflush(stdin);
    } while (codigo != 4);

    getchar();
    return 0;
}
