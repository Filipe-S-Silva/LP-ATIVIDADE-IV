#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

struct informacoesAluno {
    char nome[200];
    char dataDeNascimento[200];
    float nota[2];
    float media;
};

void limpatela(){
    system("cls || clear");
}

void resultado(float media){
    if (media >= 7)
    {
        printf("APROVADO\n");
    } else {
        printf("REPROVADO\n");
    }       
}

void calcularMedia(){
 struct informacoesAluno aluno[5];
 float soma = 0;
 int i;
 int j;

 for (i = 0; i < 5; i++)
 {
    printf("Informe o nome do %d aluno: ", i + 1);
    gets(aluno[i].nome);
    
    printf("Informe a data de nascimento: ");
    gets(aluno[i].dataDeNascimento);
    for (j = 0; j < 2; j++)
    {
        do
        {
        printf("Informe a %d nota: ", j + 1);
        scanf("%f", &aluno[i].nota[j]);
        if (aluno[i].nota[j] >= 0 && aluno[i].nota[j] <= 10)
        {
        soma += aluno[i].nota[j];
        }         
        } while (aluno[i].nota[j] > 10 || aluno[i].nota[j] < 0);
        
    }

    //calculando media   
    aluno[i].media = soma / j;

    soma = 0;
    
    fflush(stdin);

 }

    printf("ALUNOS CADASTRADOS..........\n");
    sleep(2);
    limpatela();

    for (i = 0; i < 5; i++)
    {
        printf("Nome: %s\n", aluno[i].nome);
        printf("Data nascimento: %s\n", aluno[i].dataDeNascimento);
        for (j = 0; j < 2; j++)
        {
            printf("%dº nota: %.2f\n", j + 1, aluno[i].nota[j]);
        }
        printf("Média: %.2f\n", aluno[i].media);
        resultado(aluno[i].media);
        printf("\n");
    }
 
}

int main(){

//variaveis
setlocale(LC_ALL, "portuguese");


//funcao
calcularMedia();

getchar();
return 0;

}
