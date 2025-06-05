#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){
    int tam;
    char texto[100];
    char filename[50] = "../Downloads/teste.txt";
    setlocale(LC_ALL, "Portuguese");

    FILE *f;
    f = fopen(filename, "a");
    if(f == NULL){
        printf("Problemas ao abrir o arquivo. \n");
        exit(0);
    }


    printf("Digite a primeiro mensagem desejeda no arquivo. \n");
    fgets(texto, 100, stdin);

    tam = strlen(texto);
    if(texto[tam - 1] == '\n' && tam > 0){
        texto[tam - 1] = '\0';
    }

    for(int i = 0; i < strlen(texto); i++){
        fputc(texto[i], f);
    }
    fputc('\n', f);

    printf("Digite uma segunda mensagem desejeda no arquivo. \n");
    fgets(texto, 100, stdin);

    tam = strlen(texto);
    if(texto[tam - 1] == '\n' && tam > 0){
        texto[tam - 1] = '\0';
    }
    fputs(texto, f);
    fputc('\n', f);

    fclose(f);
    return 1;
}
