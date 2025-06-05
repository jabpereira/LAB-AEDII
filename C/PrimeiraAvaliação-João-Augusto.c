#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void geraNumeros(int vet[], int tam);
void bubbleSort(int vet[], int tam);
int  retornaSomatorioParesVetor(int vet[], int tam);

main()
{
    int numeros[100], i, somatorio;
    setlocale(LC_ALL, "portuguese");

    geraNumeros(numeros, 100);
    printf("Numeros gerados...\n\n");
    for (i=0; i < 100; i++)
    {
        printf("%4d", numeros[i]);
    }

    bubbleSort(numeros, 100);

    somatorio = retornaSomatorioParesVetor(numeros, 100);

    printf("\n A soma dos números pares armazenados é: %d \n\n", somatorio);
}

void geraNumeros(int vet[], int tam)
{
    int i;

    srand(time(NULL));
    for (i=0; i < tam; i++)
    {
        vet[i] = rand() % 31;
    }
}

void bubbleSort(int vet[], int tam)
{
    int i,j,aux;

    for(i=0; i < tam-1; i++)
    {
        for(j = tam-1; j > i; j--)
        {
            if (vet[j] < vet[j-1])
            {
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux;
            }
        }
    }
}

int retornaSomatorioParesVetor(int vet[], int tam)
{
    int joaosoma = 0;
    int joaoi;
    for (joaoi = 0; joaoi < tam; joaoi++){
        if(vet[joaoi] % 2 == 0){
            joaosoma = joaosoma + vet[joaoi];
        }
    }
    return joaosoma;
}
