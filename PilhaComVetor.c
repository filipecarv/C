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
    int topo;
    Receita *elementos;
} Pilha;

/* Funções implementadas */
Pilha *Criar();
Pilha *Excluir(Pilha *);
int Push(Pilha *, Receita);
void VerTopo(Pilha *);
int Pop(Pilha *);
int EhVazia(Pilha *);
void CarregarDados(Pilha *);
void SalvarDados(Pilha *);

/* Função para criar uma pilha*/
Pilha *Criar() {
    Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));
    if (novaPilha == NULL) {
        printf("Erro na alocacao de memoria meu bom!\n");
        return NULL;
    }
    novaPilha->topo = 0;
    novaPilha->elementos = (Receita *)malloc(TAM * sizeof(Receita));
    if (novaPilha->elementos == NULL) {
        printf("Erro na alocacao de memoria meu bom!\n");
        free(novaPilha);
        return NULL;
    }
    printf("\nPilha criada com sucesso meu bom!\n");
    return novaPilha;
}

/* Função para ver se a pilha esta vazia */
int EhVazia(Pilha *pilha) {
    return pilha->topo == 0;
}

/*Função para carregar dados de receitas*/
void CarregarDados(Pilha *pilha) {
    FILE *file = fopen(ARQUIVO, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo meu bom!\n");
        return;
    }

    Receita receita;
    while (fscanf(file, "%d %49s %d %c %d %f", &receita.id, receita.nome, &receita.tempo_preparo, &receita.dificuldade, &receita.porcoes, &receita.custo) == 6) {
        if (Push(pilha, receita) == 0) {
            printf("Pilha cheia, nao foi possivel carregar todas as receitas meu bom!\n");
            break;
        }
    }

    fclose(file);
    printf("Dados carregados com sucesso meu bom!\n");
}

/*Função para salvar dados em receitas*/
void SalvarDados(Pilha *pilha) {
    FILE *file = fopen(ARQUIVO, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo meu bom!\n");
        return;
    }

    for (int i = 0; i < pilha->topo; i++) {
        Receita receita = pilha->elementos[i];
        fprintf(file, "%d %s %d %c %d %.2f\n", receita.id, receita.nome, receita.tempo_preparo, receita.dificuldade, receita.porcoes, receita.custo);
    }

    fclose(file);
    printf("Dados salvos com sucesso meu bom!\n");
}

/* Função para excluir uma pilha*/
Pilha *Excluir(Pilha *pilha) {
    if (pilha == NULL) {
        printf("A pilha nao existe meu bom!\n");
        return NULL;
    }
    free(pilha->elementos);
    free(pilha);
    printf("Pilha excluida com sucesso meu bom!\n");
    return NULL;
}

/* Função para inserir receitas*/
int Push(Pilha *pilha, Receita novaReceita) {
    if (pilha == NULL) {
        printf("\nA pilha nao foi criada.\n");
        return 0;
    }
    if (pilha->topo < TAM) {
        pilha->elementos[pilha->topo] = novaReceita;
        pilha->topo++;
        return 1;
    } else {
        printf("Pilha cheia meu bom!\n");
        return 0;
    }
}

/* Função para ver uma pilha*/
void VerTopo(Pilha *pilha) {
    if (pilha == NULL) {
        printf("A pilha nao foi criada meu bom!\n");
        return;
    }
    if (pilha->topo == 0) {
        printf("Pilha vazia meu bom!\n");
        return;
    }
    Receita topo = pilha->elementos[pilha->topo - 1];
    printf("\n|Topo da pilha:");
    printf("\n|ID: %d", topo.id);
    printf("\n|Nome: %s", topo.nome);
    printf("\n|Tempo de Preparo: %d minutos", topo.tempo_preparo);
    printf("\n|Dificuldade: %c", topo.dificuldade);
    printf("\n|Porcoes: %d", topo.porcoes);
    printf("\n|Custo: %.2f\n", topo.custo);
}

/* Função para excluir receitas*/
int Pop(Pilha *pilha) {
    if (pilha == NULL) {
        printf("A pilha nao foi criada meu bom!\n");
        return 0;
    }
    if (pilha->topo == 0) {
        printf("Pilha vazia meu bom!\n");
        return 0;
    }
    pilha->topo--;
    return 1;
}

int main() {
    Pilha *minhaPilha = Criar();
    int opcao;
    Receita novaReceita;

    do {
        printf("\n---Menu---\n");
        printf("[1] Inserir Receita\n");
        printf("[2] Ver Receita no Topo\n");
        printf("[3] Ver se a Pilha esta Vazia\n");
        printf("[4] Remover Receita do Topo\n");
        printf("[5] Carregar Dados\n");
        printf("[6] Salvar Dados\n");
        printf("[7] Excluir Pilha\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: /*Inserir Receitas*/
                printf("\n---Inserir Receitas---\n");
                if (minhaPilha->topo < TAM) {
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
                    Push(minhaPilha, novaReceita);
                } else {
                    printf("Pilha cheia meu bom!\n");
                }
                break;
            case 2: /*Ver Receitas*/
                printf("\n---Ver Receitas---\n");
                VerTopo(minhaPilha);
                break;
            case 3: /*Ver se a Pilha está Vazia*/
                printf("\n---Ver se a Pilha esta Vazia---\n");
                if (EhVazia(minhaPilha)) {
                    printf("A pilha esta vazia meu bom!\n");
                } else {
                    printf("A pilha nao esta vazia meu bom!\n");
                }
                break;
            case 4: /*Remover Receitas*/
                printf("\n---Remover Receitas---\n");
                if (Pop(minhaPilha)) {
                    printf("Receita removida do topo meu bom!\n");
                }
                break;
             case 5: /*Carregar Dados*/
                printf("\n---Carregar Dados---\n");
                CarregarDados(minhaPilha);
                break;
            case 6: /*Salvar Dados*/
                printf("\n---Salvar Dados---\n");
                SalvarDados(minhaPilha);
                break;
            case 7: /*Excluir Pilha*/
                printf("\n---Excluir Pilha---\n");
                Excluir(minhaPilha);
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