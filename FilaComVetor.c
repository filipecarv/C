/*Alunos: Luiz Filipe e Mara Rúbia*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define ARQUIVO "receitas.txt"

typedef struct {
    int id;
    char nome[50];
    int tempo_preparo;
    char dificuldade;
    int porcoes;
    float custo;
} Receita;

typedef struct {
    int inicio;
    int fim;
    Receita *elementos;
} Fila;

/* Funções implementadas */
Fila *Criar();
int Enqueue(Fila *, Receita);
int Dequeue(Fila *);
void VerReceitaInicio(Fila *);
Fila *Excluir(Fila *);
void CarregarDados(Fila *);
void SalvarDados(Fila *);

/* Função para criar uma fila*/
Fila *Criar() {
    Fila *novaFila = (Fila *)malloc(sizeof(Fila));
    if (novaFila == NULL) {
        printf("Erro na alocacao de memoria meu bom!\n");
        return NULL;
    }

    novaFila->inicio = 0;
    novaFila->fim = 0;
    novaFila->elementos = (Receita *)malloc(TAM * sizeof(Receita));
    if (novaFila->elementos == NULL) {
        printf("\nErro na alocacao das receitas emu bom!\n");
        free(novaFila);
        return NULL;
    }

    printf("Fila criada com sucesso meu bom!\n");
    return novaFila;
}

/* Função para inserir receitas*/
int Enqueue(Fila *fila, Receita novaReceita) {
    if (fila == NULL) {
        printf("A fila nao foi criada meu bom!\n");
        return 0;
    }

    if ((fila->fim + 1) % TAM == fila->inicio) {
        printf("Fila cheia meu bom!\n");
        return 0;
    }

    fila->elementos[fila->fim] = novaReceita;
    fila->fim = (fila->fim + 1) % TAM;
    return 1;
}

/* Função para excluir receitas*/
int Dequeue(Fila *fila) {
    if (fila == NULL) {
        printf("A fila nao foi criada meu bom!\n");
        return 0;
    }

    if (fila->inicio == fila->fim) {
        printf("Fila vazia meu bom!\n");
        return 0;
    }

    fila->inicio = (fila->inicio + 1) % TAM;
    return 1;
}

/* Função para ver receitas no início*/
void VerReceitaInicio(Fila *fila) {
    if (fila == NULL) {
        printf("A fila nao foi criada meu bom!\n");
        return;
    }

    if (fila->inicio == fila->fim) {
        printf("Fila vazia meu bom!\n");
        return;
    }

    Receita inicio = fila->elementos[fila->inicio];
    printf("\n|Elemento no inicio da fila:");
    printf("\n|ID: %d", inicio.id);
    printf("\n|Nome: %s", inicio.nome);
    printf("\n|Tempo de preparo: %d minutos", inicio.tempo_preparo);
    printf("\n|Dificuldade: %c", inicio.dificuldade);
    printf("\n|Porcoes: %d", inicio.porcoes);
    printf("\n|Custo: %.2f\n", inicio.custo);
}

/* Função para excluir uma fila*/
Fila *Excluir(Fila *fila) {
    if (fila == NULL) {
        printf("A fila nao existe meu bom!\n");
        return NULL;
    }

    free(fila->elementos);
    free(fila);

    printf("Fila excluida com sucesso meu bom!\n");
    return NULL;
}

/*Função para carregar dados de receitas*/
void CarregarDados(Fila *fila) {
    if (fila == NULL) {
        printf("A fila nao foi criada meu bom!\n");
        return;
    }

    FILE *file = fopen(ARQUIVO, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo meu bom!\n");
        return;
    }

    Receita receita;
    while (fscanf(file, "%d;%49[^;];%d;%c;%d;%f", &receita.id, receita.nome, &receita.tempo_preparo, &receita.dificuldade, &receita.porcoes, &receita.custo) == 6) {
        if (!Enqueue(fila, receita)) {
            break;
        }
    }

    fclose(file);
    printf("Dados carregados com sucesso meu bom!\n");
}

/*Função para salvar dados em receitas*/
void SalvarDados(Fila *fila) {
    if (fila == NULL) {
        printf("A fila nao foi criada meu bom!\n");
        return;
    }

    FILE *file = fopen(ARQUIVO, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo meu bom!\n");
        return;
    }

    int i = fila->inicio;
    while (i != fila->fim) {
        Receita receita = fila->elementos[i];
        fprintf(file, "%d;%s;%d;%c;%d;%.2f\n", receita.id, receita.nome, receita.tempo_preparo, receita.dificuldade, receita.porcoes, receita.custo);
        i = (i + 1) % TAM;
    }

    fclose(file);
    printf("\nDados salvos com sucesso meu bom!\n");
}

int main() {
    Fila *fila = Criar();
    if (fila == NULL) return 1;

    int opcao;
    Receita novaReceita;

    do {
        printf("\n---Menu---\n");
        printf("[1] Inserir Receita\n");
        printf("[2] Ver Receita no Inicio\n");
        printf("[3] Remover Receita\n");
        printf("[4] Carregar Dados\n");
        printf("[5] Salvar Dados\n");
        printf("[6] Excluir Fila\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: /*Inserir Receitas*/
                printf("\n---Inserir Receitas---\n");
                printf("|ID: ");
                scanf("%d",&novaReceita.id);
                printf("|Nome: ");
                scanf("%s",novaReceita.nome);
                printf("|Tempo de preparo: ");
                scanf("%d",&novaReceita.tempo_preparo);
                printf("|Dificuldade: ");
                scanf(" %c",&novaReceita.dificuldade);
                printf("|Porcoes: ");
                scanf("%d",&novaReceita.porcoes);
                printf("|Custo: ");
                scanf("%f",&novaReceita.custo);
                Enqueue(fila, novaReceita);
                break;
            case 2: /*Ver Receitas No Início*/
                printf("\n---Ver Receitas No Inicio---\n");
                VerReceitaInicio(fila);
                break;
            case 3: /*Remover Receitas*/
                printf("\n---Remover Receitas---\n");
                Dequeue(fila);
                break;
            case 4: /*Carregar Dados*/
                printf("\n---Carregar Dados---\n");
                CarregarDados(fila);
                break;
            case 5: /*Salvar Dados*/
                printf("\n---Salvar Dados---\n");
                SalvarDados(fila);
                break;
            case 6: /*Excluir Fila*/
                printf("\n---Excluir Fila---\n");
                fila = Excluir(fila);
                break;
            case 0: /*Sair*/
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida meu bom!\n");
        }
    } while (opcao != 0);
    return 0;
}