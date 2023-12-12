#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

struct InformacoesContato
{
    char nome[200];
    char numero[200];
    char email[200];
};

char *retorno(struct InformacoesContato contato[], int posicao, char *teste){

    int i;

    for (i = 0; i < posicao; i++)
    {
        if (strcmp(contato[i].nome, teste) == 0)
        {
            return contato[i].numero;
        }
    }
    return "Contato não registrado";
}

void limpatela()
{
    system("cls || clear");
}

int main()
{

    // variaveis
    setlocale(LC_ALL, "portuguese");
    struct InformacoesContato contato[3];
    int i;
    char nomeTeste[200];
    char agenda[200];

    // usuario
    for (i = 0; i < 3; i++)
    {
        printf("Informaçõees do %dº contato\n", i + 1);

        printf("Informe o nome do contato: ");
        gets(contato[i].nome);

        printf("Informe o número do contato: ");
        gets(contato[i].numero);

        printf("Informe o email do contato: ");
        gets(contato[i].email);

        printf("\n");
    }

    printf("Contatos salvos.....\n");
    sleep(1);

    limpatela();

    // mostrar
    printf("Informe o nome do contato desejado: ");
    gets(nomeTeste);

    char *agenda = retorno(contato, 3, nomeTeste);

    printf("Buscando contato.....\n");
    sleep(1);
    limpatela();

    if (agenda != "Contato não registrado")
    {
        printf("Número do %s: %s", nomeTeste, agenda);
    }
    else
    {
        printf("Contato não registrado");
    }

    getchar();
    return 0;
}
