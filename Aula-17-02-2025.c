#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
/*
Par�metro por valor alimenta fun��o;
Par�metro por refer�ncia(ponteiro) retorna valores;
*/
void geraNumeros(int f, int *r1, int *r2);

main(){
    int faixa, n1, n2;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite a faixa de valores:");
    scanf("%d", &faixa);

    geraNumeros(faixa, &n1, &n2);
    printf("Primeiro n�mero gerado: %d \n", n1);
    printf("Segundo n�mero gerado: %d \n", n2);
}

void geraNumeros(int f, int *r1, int *r2){
    srand(time(NULL));
    *r1 = rand() % f;
    *r2 = rand() % f;
}
