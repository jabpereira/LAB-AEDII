#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// ___________________________________________

typedef struct noF {
    int dado;
    struct noF *prox;
} noFila;

typedef struct {
    noFila  *inicio;
    noFila  *fim;
    int     tamFila;
} fila;

void criaFila(fila *q);
int  insereFila(fila *q, int dado);
int  retiraFila(fila *q, int *dado);
int  filaEstaVazia(fila q);
int  getInicioFila(fila q);
int  getFimFila(fila q);
int  getTamanhoFila(fila q);
void mostraFila(fila q);

// __________________________________________

typedef struct noP {
    int dado;
    struct noP *prox;
} noPilha;

typedef struct {
    noPilha *topo;
    int     tamPilha;
} pilha;

void criaPilha(pilha *s);
int  empilha(pilha *s, int dado);
int  desempilha(pilha *s, int *dado);
int  pilhaEstaVazia(pilha s);
int  getTopoPilha(pilha s);
int  getTamanhoPilha(pilha s);
void mostraPilha(pilha s);

// __________________________________________

int main() {
    fila f;
    pilha p;
    char produto;
    int i, dado;


    setlocale(LC_ALL, "Portuguese");

    criaFila(&f);
    criaPilha(&p);

    printf("Bem vindo ao sistema de cadastro de produtos da loja Diversidade Modas. \n");
    printf("Faça o registro de 10 produtos.");
    for(i = 0; i < 10; i++){
        printf("Selecione aqui qual produto deseja cadastrar, V para vestuário e C para calçados. \n");
        printf("Qual produto deseja cadastrar? \n\n");
        scanf(" %c", &produto);  // Note o espaço antes do %c
        produto = tolower(produto);
        if(produto != 'v' && produto != 'c'){
            return(-1);
        }
        if(produto == 'v'){
            printf("Digite o código desse produto: \n");
            scanf("%d", &dado);
            printf("Fila <- %d\n", dado);
            insereFila(&f, dado);
        }

        else if(produto == 'c'){
            printf("Digite o código desse produto: \n");
            scanf("%d", &dado);
            printf("Pilha <- %d\n", dado);
            empilha(&p, dado);
        }
    }

    printf("\n--- Códigos de produtos de vestuário ---\n");
    mostraFila(f);
    printf("\n--- Código de produtos de calçado ---\n");
    mostraPilha(p);

    return 0;
}

// __________________________________________

void criaFila(fila *q) {
    q->inicio = NULL;
    q->fim = NULL;
    q->tamFila = 0;
}

int insereFila(fila *q, int dado) {
    noFila *aux = (noFila *) malloc(sizeof(noFila));
    if (!aux) return 0;

    aux->dado = dado;
    aux->prox = NULL;
    q->tamFila++;

    if (q->inicio == NULL) {
        q->inicio = aux;
        q->fim = aux;
    } else {
        q->fim->prox = aux;
        q->fim = aux;
    }

    return 1;
}

int retiraFila(fila *q, int *dado) {
    noFila *aux = q->inicio;
    if (!aux) return 0;

    *dado = aux->dado;
    q->inicio = aux->prox;
    if (!q->inicio) q->fim = NULL;
    q->tamFila--;
    free(aux);
    return 1;
}

int filaEstaVazia(fila q) {
    return q.inicio == NULL;
}

int getInicioFila(fila q) {
    return q.inicio ? q.inicio->dado : -1;
}

int getFimFila(fila q) {
    return q.fim ? q.fim->dado : -1;
}

int getTamanhoFila(fila q) {
    return q.tamFila;
}

void mostraFila(fila q) {
    noFila *aux = q.inicio;
    if (!aux) {
        printf("Fila vazia...\n");
        return;
    }
    while (aux) {
        printf("Fila: %d\n", aux->dado);
        aux = aux->prox;
    }
}

// __________________________________________

void criaPilha(pilha *s) {
    s->topo = NULL;
    s->tamPilha = 0;
}

int empilha(pilha *s, int dado) {
    noPilha *aux = (noPilha *) malloc(sizeof(noPilha));
    if (!aux) return 0;

    aux->dado = dado;
    aux->prox = s->topo;
    s->topo = aux;
    s->tamPilha++;

    return 1;
}

int desempilha(pilha *s, int *dado) {
    noPilha *aux = s->topo;
    if (!aux) return 0;

    *dado = aux->dado;
    s->topo = aux->prox;
    s->tamPilha--;
    free(aux);

    return 1;
}

int pilhaEstaVazia(pilha s) {
    return s.topo == NULL;
}

int getTopoPilha(pilha s) {
    return s.topo ? s.topo->dado : -1;
}

int getTamanhoPilha(pilha s) {
    return s.tamPilha;
}

void mostraPilha(pilha s) {
    noPilha *aux = s.topo;
    if (!aux) {
        printf("Pilha vazia...\n");
        return;
    }
    while (aux) {
        printf("Pilha: %d\n", aux->dado);
        aux = aux->prox;
    }
}
