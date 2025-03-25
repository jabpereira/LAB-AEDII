#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char nome[30];
    float salario;
} pessoa;

int main(){
    pessoa *p;
    setlocale(LC_ALL, "portuguese");

    printf("C�digo em execu��o...\n\n");
    printf("Alocando mem�ria na �rea de heap...\n\n");

    p = (pessoa*) malloc(sizeof(pessoa));
    if(p == NULL){
        printf("Sem mem�ria! Aloca��o n�o realizada...\n\n");
        exit(1);
    }

    printf("Armazenando dados na �rea de heap. \n\n");
    p -> codigo = 100;
    strcpy(p -> nome, "Maria");
    p -> salario = 10000;

    printf("Nome = %s \n\n", p -> nome);
    printf("C�digo = %d \n\n", p -> codigo);
    printf("Sal�rio = %0.2f \n\n", p -> salario);

    free(p);
    return 0;
}
