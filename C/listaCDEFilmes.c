#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int  id;
    char nome[30];
    int  ano;
} filme;

typedef struct no
{
    filme  dado;
    struct no *ant;
    struct no *prox;

} No;

typedef struct
{
    No *inicio;
    No *fim;
    int tam;

} ListaCDE;

//funcoes de manipulacao
void cria(ListaCDE *l);
int  insereOrdenado(ListaCDE *l, filme dado);
int  retira(ListaCDE *l, int d);

//funcoes de visualizacao
int  estaVazia(ListaCDE l);
filme  getInicio(ListaCDE l);
filme  getFim(ListaCDE l);
int  getTamanho(ListaCDE l);
void mostra(ListaCDE, int sentido);

main()
{
    ListaCDE lista;
    filme f;

    cria(&lista);

    // Inserindo um dado, do tipo filme, na lista
    f.id = 10;
    strcpy(f.nome, "Vingadores");
    f.ano = 2020;
    insereOrdenado(&lista, f);

    f.id = 20;
    strcpy(f.nome, "Homem-Aranha");
    f.ano = 2022;
    insereOrdenado(&lista, f);

    f.id = 30;
    strcpy(f.nome, "O Ultimo Samurai");
    f.ano = 2004;
    insereOrdenado(&lista, f);

    if (!estaVazia(lista))
    {
        mostra(lista, 1);
        retira(&lista, 20);
        mostra(lista, 1);
    }
}

void cria(ListaCDE *l)
{
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insereOrdenado(ListaCDE *l, filme dado)
{
    // alocando no na memoria e checando se deu certo
    No *aux = (No *) malloc(sizeof(No));
    if (aux == NULL)
        return 0;

    // guardando o dado e incrementando o tamanho da lista
    aux->dado = dado;
    l->tam++;

    /* 1o caso: primeiro elemento */
    if (l->inicio == NULL)
    {
        //todos apontam para o unico no existente
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;

        return 1;
    }

    /* 2o caso: dado menor que o dado do inicio, insere no inicio */
    if (dado.ano < l->inicio->dado.ano)
    {
        aux->ant = l->fim; //ant do novo inicio aponta para fim
        aux->prox = l->inicio; //prox do novo inicio aponta para antigo inicio
        l->inicio->ant = aux; // anterior do antigo inicio aponta para novo inicio
        l->inicio = aux; //l->inicio aponta para novo inicio
        l->fim->prox = l->inicio; //proximo do fim aponta para novo inicio

        return 1;
    }

    /* 3o caso: dado maior que o dado do fim, insere no fim */
    if (dado.ano > l->fim->dado.ano)
    {
        aux->ant = l->fim; //ant do novo fim aponta para antigo fim
        aux->prox = l->inicio; //prox do novo fim aponta pra inicio
        l->fim->prox = aux; //prox do antigo fim aponta para novo fim
        l->fim = aux; //l->fim aponta para novo fim
        l->inicio->ant = l->fim; //ant do inicio aponta para novo fim

        return 1;
    }

    /* 4o caso: insercao ordenada no meio */

    // inicializa-se dois nos no comeco da lista, que serao responsaveis por percorre-la
    No *anterior = l->inicio;
    No *atual = anterior->prox;

    while (dado.ano > atual->dado.ano)
    {

        // percorro a lista ate achar a posicao certa
        anterior = atual;
        atual = atual->prox;
    }
    // insiro o no entre anterior e atual
    aux->ant = anterior; // ant do novo no aponta para anterior
    aux->prox = atual; // prox do novo no aponta para atual
    anterior->prox = aux; // prox do anterior aponta para o novo no
    atual->ant = aux; // ant do atual aponta para o novo no

    return 1;
}

int retira(ListaCDE *l, int d)
{
    No *aux;

    if (l->inicio == NULL)
    {
        printf("Lista vazia\n");
        return 0;
    }

    // 1o caso: lista unitaria
    if ((d == l->inicio->dado.id) && (l->inicio == l->fim))
    {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = NULL; //inicio aponta pra null
        l->fim = NULL; // fim aponta pra null
        free(aux); // libero a memoria
        l->tam--;

        return 1;
    }

    // 2o caso: removendo primeiro elemento
    if (d == l->inicio->dado.id)
    {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = aux->prox; //inicio aponta para o novo inicio (o segundo elemento)
        l->inicio->ant = l->fim; // o anterior do novo inicio aponta para o fim
        l->fim->prox = l->inicio; // o proximo do fim aponta para o novo inicio
        free(aux); //libero memoria
        l->tam--;

        return 1;
    }

    // 3o caso: removendo ultimo elemento
    if (d == l->fim->dado.id)
    {
        aux = l->fim; // aux aponta para o no que vou remover
        l->fim = aux->ant; //fim aponta para o novo fim (penultimo elemento)
        l->fim->prox = l->inicio; // o proximo do novo fim aponta para o inicio
        l->inicio->ant = l->fim; // o anterior do inicio aponta para o novo fim
        free(aux); //libero a memoria
        l->tam--;

        return 1;
    }

    // 4o caso: removendo um elemento no meio
    aux = l->inicio->prox; // aux aponta para o segundo elemento

    //percorro a lista ate achar o elemento, ou chegar no fim
    while ((d != aux->dado.id) && (aux != l->fim))
            aux = aux->prox;

    if (aux == l->fim)
    {  // se cheguei ao fim, nao encontrei o elemento
        printf("O elemento %d nao esta na lista.\n", d);
        return 0;
    }

    //se encontrei o elemento, removo ele
    aux->prox->ant = aux->ant; // o anterior do proximo a aux aponta para o elemento anterior a aux
    aux->ant->prox = aux->prox; // o proximo do anterior a aux aponta para o proximo elemento em relacao a aux
    free(aux); //libero a memoria
    l->tam--;

    return 1;
}

int estaVazia(ListaCDE l)
{
    if (l.inicio == NULL)
        return 1;

    return 0;
}

filme getInicio(ListaCDE l)
{
    return l.inicio->dado;
}


filme getFim(ListaCDE l)
{
    return l.fim->dado;
}

int getTamanho(ListaCDE l)
{
    return l.tam;
}

/*
    Exibe os elementos da lista, dependendo do sentido:
    1 - exibe do inicio ao fim
    2 - exibe do fim ao inicio
*/
void mostra(ListaCDE l, int sentido)
{
    No *aux;

    if (l.inicio == NULL) // lista vazia, nao mostra nada
        printf("Lista vazia!\n");

    else
    { // lista possui elementos, mostra dependendo do sentido
        if(sentido == 1)
        { // percorrendo do inicio ao fim

            printf("\nExibindo lista do inicio ao fim:\n\n");
            aux = l.inicio;
            do
            {
                printf("Dado: %d %s %d\n",
                       aux->dado.id, aux->dado.nome, aux->dado.ano);
                aux = aux->prox;
            } while(aux != l.inicio);
        }
        else
        { // percorrendo do fim ao inicio

            printf("\nExibindo lista do fim ao inicio:\n\n");
            aux = l.fim;
            do
            {
                printf("Dado: %d %s %d\n",
                       aux->dado.id, aux->dado.nome, aux->dado.ano);
                aux = aux->ant;
            } while(aux != l.fim);
        }
    }
}
