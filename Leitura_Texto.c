#include <stdio.h>
#include <stdlib.h>
#include <locale.h>>

typedef struct {
    int id;
    char cor[20];
    float coordX;
    float coordY;
}Ponto;

Ponto registraPonto();
void escrevePonto(FILE *f, Ponto p);

int main(){
    char filename[50] = "pontos.abacate";
    Ponto p;
    int n;
    setlocale(LC_ALL, "Portuguese");

    FILE *f;
    f = fopen(filename, "w+");
    if(f == NULL){
        printf("Problemas ao abrir o arquivo. \n");
        exit(0);
    }

    printf("Exibindo pontos registrados: ");
    while(fscanf(f, "%d %s %f %f", &p.id, p.cor, &p.coordX, &p.coordY) > 0){
                printf("%d %s %f %f\n", p.id, p.cor, p.coordX, &p.coordY);
    }
    printf("\nRegistrando pontos... \n");
    printf("Quantos pontos quer registrar?");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        p = registraPonto();
        escrevePonto(f, p);
    }

    fclose(f);
    return 1;
}

Ponto registraPonto(){
    Ponto p;

    printf("Digite as informações do ponto. \n");

    printf("ID:");
    scanf("%d", &p.id);
    getchar();

    printf("\nCOR:");
    scanf("%s", p.cor);
    getchar();

    printf("\nCOORDENADA X:");
    scanf("%f", &p.coordX);
    getchar();

    printf("\nCOORDENADA Y:");
    scanf("%f", &p.coordY);
    getchar();

    return p;
}

void escrevePonto(FILE *f, Ponto p){
    fprintf(f, "%d %s %f %f \n", p.id, p.cor, p.coordX, p.coordY);
}
