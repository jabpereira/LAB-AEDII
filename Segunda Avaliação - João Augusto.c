#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    int   codigo;
    char  descricao[30];
    float preco;
} produto;

typedef struct no
{
    produto   dado;
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
int  insereOrdenado(ListaCDE *l, produto dado);
int  retira(ListaCDE *l, int d);

//funcoes de visualizacao
int     estaVazia(ListaCDE l);
produto getInicio(ListaCDE l);
produto getFim(ListaCDE l);
int     getTamanho(ListaCDE l);
void    mostra(ListaCDE, int sentido);

main()
{
    ListaCDE lista;
    produto p;

    setlocale(LC_ALL, "Portuguese");

    cria(&lista);

    //Produto nº 1
    p.codigo = 19;
    strcpy(p.descricao, "Camisa de botões branca.");
    p.preco = 69.99;
    //Insere ordenadamente os produtos na lista
    insereOrdenado(&lista, p);

    //Produto nº 2
    p.codigo = 67;
    strcpy(p.descricao, "Calça de alfaiataria marrom.");
    p.preco = 89.99;
    //Insere ordenadamente os produtos na lista
    insereOrdenado(&lista, p);

    //Produto nº 3
    p.codigo = 43;
    strcpy(p.descricao, "Blazer riscado preto e branco.");
    p.preco = 94.99;
    //Insere ordenadamente os produtos na lista
    insereOrdenado(&lista, p);

    //Produto nº 4
    p.codigo = 13;
    strcpy(p.descricao, "Camisa de botões preta.");
    p.preco = 69.99;
    //Insere ordenadamente os produtos na lista
    insereOrdenado(&lista, p);

    //Produto nº 5
    p.codigo = 58;
    strcpy(p.descricao, "Calça de alfaiataria preta.");
    p.preco = 89.99;
    //Insere ordenadamente os produtos na lista
    insereOrdenado(&lista, p);

    if(!estaVazia(lista)){
        //mostra do 1º ao último
        mostra(lista, 1);
        //mostra do último ao primeiro
        mostra(lista, 0);

        //mostrando qual o primeiro e o último nó
        printf("\nID do primeiro: %d", getInicio(lista));
        printf("\nID do segundo: %d \n", getFim(lista));
        printf("Removendo os nós...\n");

        //remove primeiro elemento
        retira(&lista, 13);
        //remove ultimo elemento
        retira(&lista, 67);

        //mostra do 1º ao último
        mostra(lista, 1);
        //mostra do último ao primeiro
        mostra(lista, 0);
    }
}

void cria(ListaCDE *l)
{
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insereOrdenado(ListaCDE *l, produto dado)
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
    if (dado.codigo < l->inicio->dado.codigo)
    {
        aux->ant = l->fim; //ant do novo inicio aponta para fim
        aux->prox = l->inicio; //prox do novo inicio aponta para antigo inicio
        l->inicio->ant = aux; // anterior do antigo inicio aponta para novo inicio
        l->inicio = aux; //l->inicio aponta para novo inicio
        l->fim->prox = l->inicio; //proximo do fim aponta para novo inicio

        return 1;
    }

    /* 3o caso: dado maior que o dado do fim, insere no fim */
    if (dado.codigo > l->fim->dado.codigo)
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

    while (dado.codigo > atual->dado.codigo)
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
    if ((d == l->inicio->dado.codigo) && (l->inicio == l->fim))
    {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = NULL; //inicio aponta pra null
        l->fim = NULL; // fim aponta pra null
        free(aux); // libero a memoria
        l->tam--;

        return 1;
    }

    // 2o caso: removendo primeiro elemento
    if (d == l->inicio->dado.codigo)
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
    if (d == l->fim->dado.codigo)
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
    while ((d != aux->dado.codigo) && (aux != l->fim))
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

produto getInicio(ListaCDE l)
{
    return l.inicio->dado;
}


produto getFim(ListaCDE l)
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
                printf("Dado: %d %s %5.2f\n",
                       aux->dado.codigo, aux->dado.descricao, aux->dado.preco);
                aux = aux->prox;
            } while(aux != l.inicio);
        }
        else
        { // percorrendo do fim ao inicio

            printf("\nExibindo lista do fim ao inicio:\n\n");
            aux = l.fim;
            do
            {
                printf("Dado: %d %s %5.2f\n",
                       aux->dado.codigo, aux->dado.descricao, aux->dado.preco);
                aux = aux->ant;
            } while(aux != l.fim);
        }
    }
}
