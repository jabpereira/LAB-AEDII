#include <stdio.h>

main(){
    FILE * arquivo;

    int caractere;
    char nome[10];
    int i;

    printf("Abrindo o arquivo nomes.txt\n");
    arquivo = fopen("nomes.txt", "rt");

    if(arquivo == NULL){
        printf("Arquivo nao encontrado!");
        exit(1);
    }

    i = 0;
    while(!feof(arquivo))
    {
        caractere = fgetc(arquivo);
        //printf("%c", caractere);
        if(caractere != 10){
            nome[i] = (char) caractere;
            i++;
        }
        else{
            nome[i] = '\0';
            i = 0;
            printf("Nome lido = %s\n", nome);
        }
    }
    fclose(arquivo);
}
