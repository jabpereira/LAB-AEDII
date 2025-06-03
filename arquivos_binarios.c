#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// arquivo binário salva o byte do tipo de dado


typedef struct{
    int id;
    char nome[20];
    char raca[20];
    int idade;
    float peso;
}Cao;

Cao registraCao();
void escreveArquivo(char *filename, Cao *v, int n);
int leArquivo(char *filename, Cao *v, int n);


int main()
{
    Cao v[10];
    int n;

    char filename[20] = "caes.b";

    n = leArquivo(filename, v, 10);

    for(int i = 0; i < n; i++)
    {
        printf("ID: %d\n", v[i].id);
        printf("Nome: %s", v[i].nome);
        printf("Raca: %s", v[i].raca);
        printf("Idade: %d\n", v[i].idade);
        printf("Peso: %f\n\n", v[i].peso);
    }

    printf("Digite quantos caes quer cadastrar(max. 10):\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        v[i] = registraCao();
    }

    escreveArquivo(filename, v, n);

    return(0);
}

Cao registraCao()
{
    Cao c;

    printf("Registrando um cao...\n");
    printf("ID: ");
    scanf("%d", &c.id);
    getchar();

    printf("Nome: ");
    fgets(c.nome, 20, stdin);

    printf("Raca: ");
    fgets(c.raca, 20, stdin);

    printf("Idade: ");
    scanf("%d", &c.idade);
    getchar();

    printf("Peso: ");
    scanf("%f", &c.peso);
    getchar();

    return c;
}

void escreveArquivo(char *filename, Cao *v, int n)
{
    FILE *f = fopen(filename, "wb");
    if(f == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(0);
    }

    fwrite(v, sizeof(Cao), n, f);

    fclose(f);
}

int leArquivo(char *filename, Cao *v, int n)
{

    FILE *f = fopen(filename, "rb");
    if(f == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(0);
    }

    n = fread(v, sizeof(Cao), n, f);

    fclose(f);
    return n;
}
