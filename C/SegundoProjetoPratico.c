#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado[10];
    struct no *esq;
    struct no *dir;
} No;

//funcoes de manipulacao
void cria(No **t);
int insere(No **t, char nome[10]);

//funcoes de exibicao
void exibeEmOrdem(No *t);

int main(){
    FILE * arquivo;
    No *arvore;

    int caractere;
    char nome[10];
    int i;

    cria(&arvore);

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
            insere(&arvore, nome);
            i = 0;
            printf("Nome inserido = %s\n", nome);
        }
    }
    fclose(arquivo);

    printf("\n\nNomes em ordem alfabetica:\n");
    exibeEmOrdem(arvore);

    return 0;
}

void cria(No **t){
    *t = NULL;
}

int insere(No **t, char nome[10]){
    if(*t == NULL) { //cheguei na posicao certa, devo inserir
        *t = (No *) malloc(sizeof(No)); //aloco um No na memoria e devolvo seuendereco para o conteudo de t
        if(*t == NULL) //falha na alocacao
            return 0;
        strcpy((*t)->dado, nome); //atribuo o dado ao novo No
        (*t)->esq = NULL; // esq do meu novo No eh NULL
        (*t)->dir = NULL; // dir do meu novo No eh NULL
        return 1;
    }
    if (strcmp(nome, (*t)->dado) < 0)
        return insere(&(*t)->esq, nome);
    else
        return insere(&(*t)->dir, nome);
}
void exibeEmOrdem(No *t) {
    if(t != NULL) {
        exibeEmOrdem(t->esq);
        printf("%s\n", t->dado);
        exibeEmOrdem(t->dir);
    }
}


