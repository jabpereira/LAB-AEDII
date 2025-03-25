#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
/*
Parâmetro por valor alimenta função;
Parâmetro por referência(ponteiro) retorna valores;
*/
void geraNumeros(int f, int *r1, int *r2);

main(){
    int faixa, n1, n2;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite a faixa de valores:");
    scanf("%d", &faixa);

    geraNumeros(faixa, &n1, &n2);
    printf("Primeiro número gerado: %d \n", n1);
    printf("Segundo número gerado: %d \n", n2);
}

void geraNumeros(int f, int *r1, int *r2){
    srand(time(NULL));
    *r1 = rand() % f;
    *r2 = rand() % f;
}
