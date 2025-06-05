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

    printf("Código em execução...\n\n");
    printf("Alocando memória na área de heap...\n\n");

    p = (pessoa*) malloc(sizeof(pessoa));
    if(p == NULL){
        printf("Sem memória! Alocação não realizada...\n\n");
        exit(1);
    }

    printf("Armazenando dados na área de heap. \n\n");
    p -> codigo = 100;
    strcpy(p -> nome, "Maria");
    p -> salario = 10000;

    printf("Nome = %s \n\n", p -> nome);
    printf("Código = %d \n\n", p -> codigo);
    printf("Salário = %0.2f \n\n", p -> salario);

    free(p);
    return 0;
}
