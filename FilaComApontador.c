/*Alunos: Luiz Filipe e Mara Rúbia*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FilaNo filaNo;

typedef struct {
    int id;
    char nome[50];
    int tempo_preparo;
    char dificuldade;
    int porcoes;
    float custo;
} Receita;

typedef struct {
    filaNo *inicio;
    filaNo *fim;
} Fila;

struct FilaNo {
    Receita novaReceita;
    filaNo *prox;
};

/* Função para criar uma fila*/
Fila *Criar() {
    Fila *novaFila = (Fila *)malloc(sizeof(Fila));
    if (novaFila == NULL) {
        printf("Erro na alocacao de memoria meu bom!\n");
        return NULL;
    }
    novaFila->inicio = NULL;
    novaFila->fim = NULL;
    return novaFila;
}

/* Função para inserir receitas*/
int Enqueue(Fila *fila, Receita novaReceita) {
    filaNo *novoEspaco = (filaNo *)malloc(sizeof(filaNo));
    if (fila == NULL) {
        printf("A fila nao foi criada meu bom!\n");
        return 0;
    }
    novoEspaco->novaReceita = novaReceita;
    novoEspaco->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novoEspaco;
        fila->fim = novoEspaco;
    } else {
        fila->fim->prox = novoEspaco;
        fila->fim = novoEspaco;
    }
    return 1;
}

/* Função para ver receitas no início*/
void VerReceitaInicio(Fila *fila) {
    if (fila == NULL || fila->inicio == NULL) {
        printf("A fila esta vazia meu bom!\n");
        return;
    }

    Receita receitaInicio = fila->inicio->novaReceita;
    printf("\n|Elemento no inicio da fila:");
    printf("\n|ID: %d\n", receitaInicio.id);
    printf("|Nome: %s\n", receitaInicio.nome);
    printf("|Tempo de Preparo: %d\n", receitaInicio.tempo_preparo);
    printf("|Dificuldade: %c\n", receitaInicio.dificuldade);
    printf("|Porcoes: %d\n", receitaInicio.porcoes);
    printf("|Custo: %.2f\n", receitaInicio.custo);
}

/* Função para excluir receitas*/
Receita Dequeue(Fila *fila) {
    Receita receitaRemovida;
    filaNo *ref;

    if (fila == NULL || fila->inicio == NULL) {
        printf("A fila esta vazia meu bom!\n");
        return receitaRemovida;
    }

    ref = fila->inicio;
    receitaRemovida = ref->novaReceita;
    fila->inicio = fila->inicio->prox;
    free(ref);
    return receitaRemovida;
}

/* Função para excluir uma fila*/
Fila *Excluir(Fila *fila) {
    filaNo *ref;

    if (fila == NULL) {
        printf("A fila nao existe meu bom!\n");
        return NULL;
    }

    while (fila->inicio != NULL) {
        ref = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(ref);
    }
    free(fila);
    printf("Fila excluida com sucesso meu bom!\n");
    return NULL;
}

/*Função para carregar dados de receitas*/
void CarregarDados(Fila *fila, const char *recetas) {
    FILE *file = fopen(recetas, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo meu bom!\n");
        return;
    }

    Receita receita;
    while (fscanf(file, "%d;%49[^;];%d;%c;%d;%f\n", &receita.id, receita.nome, &receita.tempo_preparo, &receita.dificuldade, &receita.porcoes, &receita.custo) == 6) {
        Enqueue(fila, receita);
    }
    fclose(file);
    printf("Dados carregados com sucesso meu bom!\n");
}

/*Função para salvar dados em receitas*/
void SalvarDados(Fila *fila, const char *receitas) {
    FILE *file = fopen(receitas, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo meu bom!\n");
        return;
    }

    filaNo *atual = fila->inicio;
    while (atual != NULL) {
        fprintf(file, "%d;%s;%d;%c;%d;%.2f\n", atual->novaReceita.id, atual->novaReceita.nome, atual->novaReceita.tempo_preparo, atual->novaReceita.dificuldade, atual->novaReceita.porcoes, atual->novaReceita.custo);
        atual = atual->prox;
    }
    fclose(file);
    printf("\nDados salvos com sucesso meu bom!\n");
}

int main() {
    Fila *fila = Criar();
    if (fila == NULL) return 1;

    int opcao;
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
            {
                Receita novaReceita;
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
            }
            case 2: /*Ver Receita no Início*/
                VerReceitaInicio(fila);
                break;
            case 3: /*Remover Receitas*/
                printf("\n---Remover Receitas---\n");
                Dequeue(fila);
                printf("Receita removida com sucesso meu bom!");
                break;
            case 4: /*Carregar Dados*/
                CarregarDados(fila, "receitas.txt");
                break;
            case 5: /*Salvar Dados*/
                SalvarDados(fila, "receitas.txt");
                break;
            case 6: /*Excluir Fila*/
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