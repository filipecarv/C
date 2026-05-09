/*Alunos: Luiz Filipe e Mara Rúbia*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "receitas.txt"

typedef struct Receita {
    int id;
    char nome[50];
    float tempo_preparo; // tempo em minutos
    char dificuldade;    // F, M ou D (facil, medio ou difecil)
    int porcoes;
    float custo;         // custo em reais
    struct Receita *proximo;
} Receita;

typedef struct {
    Receita *inicio;
    Receita *fim;
    int tamanho;
} Lista;

/* Funções Prototipadas */
Lista *criarLista();
void inserirElemento(Lista *lista, Receita receita);
void inserirElementoID(Lista *lista, Receita receita, int posicao);
void inserirElementoInicio(Lista *lista, Receita receita);
void listarElementos(Lista *lista);
void removerElemento(Lista *lista, int posicao);
void atualizar(Lista *lista, int id);
void buscarElemento(Lista *lista, int id);
int tamanho(Lista *lista);
void excluirLista(Lista *lista);
void carregarDados(Lista *lista);
void salvarDados(Lista *lista);

/* Funções Implementadas */
Lista *criarLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return NULL;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    printf("Lista de receitas.\n");
    return lista;
}

void inserirElemento(Lista *lista, Receita receita) {
    Receita *novo = (Receita *)malloc(sizeof(Receita));
    if (novo == NULL) {
        printf("Erro ao inserir elemento.\n");
        return;
    }
    *novo = receita;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->proximo = lista->inicio; // circular
    } else {
        lista->fim->proximo = novo;
        lista->fim = novo;
        lista->fim->proximo = lista->inicio; // circular
    }
    lista->tamanho++;
    printf("Elemento inserido no final da lista.\n");
}

void inserirElementoID(Lista *lista, Receita receita, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("Posicao invalida.\n");
        return;
    }

    Receita *novo = (Receita *)malloc(sizeof(Receita));
    if (novo == NULL) {
        printf("Erro ao inserir elemento.\n");
        return;
    }
    *novo = receita;

    if (posicao == 1) {
        inserirElementoInicio(lista, receita);
        return;
    }

    Receita *atual = lista->inicio;
    Receita *anterior = NULL;
    int i; // Declarando a variável fora do loop
    for (i = 1; i < posicao; i++) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = novo;
    novo->proximo = atual;

    if (posicao == lista->tamanho + 1) {
        lista->fim = novo;
    }
    lista->tamanho++;
    printf("Elemento inserido na posicao %d.\n", posicao);
}

void inserirElementoInicio(Lista *lista, Receita receita) {
    Receita *novo = (Receita *)malloc(sizeof(Receita));
    if (novo == NULL) {
        printf("Erro ao inserir elemento.\n");
        return;
    }
    *novo = receita;
    novo->proximo = lista->inicio;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->proximo = lista->inicio; // circular
    } else {
        lista->fim->proximo = novo;
        lista->inicio = novo;
    }
    lista->tamanho++;
    printf("Elemento inserido no inicio da lista.\n");
}

void listarElementos(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Receita *atual = lista->inicio;
    do {
        printf("ID: %d\n", atual->id);
        printf("Nome: %s\n", atual->nome);
        printf("Tempo de preparo: %.2f minutos\n", atual->tempo_preparo);
        printf("Dificuldade: %c\n", atual->dificuldade);
        printf("Porcoes: %d\n", atual->porcoes);
        printf("Custo: R$ %.2f\n\n", atual->custo);
        atual = atual->proximo;
    } while (atual != lista->inicio);
}

void removerElemento(Lista *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posicao invalida.\n");
        return;
    }

    Receita *atual = lista->inicio;
    Receita *anterior = NULL;
    int i; // Declarando a variável fora do loop
    for (i = 1; i < posicao; i++) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) { // Remoção no início
        lista->inicio = atual->proximo;
        lista->fim->proximo = lista->inicio;
    } else {
        anterior->proximo = atual->proximo;
        if (atual == lista->fim) {
            lista->fim = anterior;
        }
    }
    free(atual);
    lista->tamanho--;
    printf("Elemento removido da posicao %d.\n", posicao);
}

void atualizar(Lista *lista, int id) {
    Receita *atual = lista->inicio;
    do {
        if (atual->id == id) {
            printf("Atualize os dados da receita.\n");
            printf("Nome: ");
            scanf("%s", atual->nome);
            printf("Tempo de preparo: ");
            scanf("%f", &atual->tempo_preparo);
            printf("Dificuldade (F, M, D): ");
            scanf(" %c", &atual->dificuldade);
            printf("Porcoes: ");
            scanf("%d", &atual->porcoes);
            printf("Custo: ");
            scanf("%f", &atual->custo);
            printf("Receita atualizada com sucesso.\n");
            return;
        }
        atual = atual->proximo;
    } while (atual != lista->inicio);
    printf("Receita com ID %d nao encontrada.\n", id);
}

void buscarElemento(Lista *lista, int id) {
    Receita *atual = lista->inicio;
    do {
        if (atual->id == id) {
            printf("Receita encontrada:\n");
            printf("ID: %d\n", atual->id);
            printf("Nome: %s\n", atual->nome);
            printf("Tempo de preparo: %.2f minutos\n", atual->tempo_preparo);
            printf("Dificuldade: %c\n", atual->dificuldade);
            printf("Porcoes: %d\n", atual->porcoes);
            printf("Custo: R$ %.2f\n", atual->custo);
            return;
        }
        atual = atual->proximo;
    } while (atual != lista->inicio);
    printf("Receita com ID %d nao encontrada.\n", id);
}

int tamanho(Lista *lista) {
    return lista->tamanho;
}

void excluirLista(Lista *lista) {
    while (lista->inicio != NULL) {
        removerElemento(lista, 1);
    }
    free(lista);
    printf("Lista excluida com sucesso.\n");
}

void carregarDados(Lista *lista) {
    FILE *file = fopen(ARQUIVO, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Receita receita;
    while (fscanf(file, "%d %49s %f %c %d %f", &receita.id, receita.nome, &receita.tempo_preparo, &receita.dificuldade, &receita.porcoes, &receita.custo) == 6) {
        inserirElemento(lista, receita);
    }
    fclose(file);
    printf("Dados carregados com sucesso.\n");
}

void salvarDados(Lista *lista) {
    FILE *file = fopen(ARQUIVO, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Receita *atual = lista->inicio;
    do {
        fprintf(file, "%d %s %.2f %c %d %.2f\n", atual->id, atual->nome, atual->tempo_preparo, atual->dificuldade, atual->porcoes, atual->custo);
        atual = atual->proximo;
    } while (atual != lista->inicio);
    fclose(file);
    printf("Dados salvos com sucesso.\n");
}

/* Fun��o principal */
int main() {
    Lista *lista = criarLista();
    int opcao, id;
    Receita receita;

    do {
        printf("\n--- Menu ---\n");
        printf("[1] Inserir Receita no Final\n");
        printf("[2] Inserir Receita por Posicao\n");
        printf("[3] Inserir Receita no Inicio\n");
        printf("[4] Listar Receitas\n");
        printf("[5] Remover Receita por Posicao\n");
        printf("[6] Atualizar Receita por ID\n");
        printf("[7] Buscar Receita por ID\n");
        printf("[8] Exibir Tamanho da Lista\n");
        printf("[9] Carregar Dados do Arquivo\n");
        printf("[10] Salvar Dados no Arquivo\n");
        printf("[11] Excluir Lista e Sair\n"); printf("Escolha uma opcao: "); scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        printf("Informe os dados da receita:\n");
        printf("ID: ");
        scanf("%d", &receita.id);
        printf("Nome: ");
        scanf("%s", receita.nome);
        printf("Tempo de preparo (min): ");
        scanf("%f", &receita.tempo_preparo);
        printf("Dificuldade (F, M, D): ");
        scanf(" %c", &receita.dificuldade);
        printf("Porcoes: ");
        scanf("%d", &receita.porcoes);
        printf("Custo (R$): ");
        scanf("%f", &receita.custo);
        inserirElemento(lista, receita);
        break;
    case 2:
        printf("Informe os dados da receita:\n");
        printf("ID: ");
        scanf("%d", &receita.id);
        printf("Nome: ");
        scanf("%s", receita.nome);
        printf("Tempo de preparo (min): ");
        scanf("%f", &receita.tempo_preparo);
        printf("Dificuldade (F, M, D): ");
        scanf(" %c", &receita.dificuldade);
        printf("Porcoes: ");
        scanf("%d", &receita.porcoes);
        printf("Custo (R$): ");
        scanf("%f", &receita.custo);
        printf("Posicao: ");
        int posicao;
        scanf("%d", &posicao);
        inserirElementoID(lista, receita, posicao);
        break;
    case 3:
        printf("Informe os dados da receita:\n");
        printf("ID: ");
        scanf("%d", &receita.id);
        printf("Nome: ");
        scanf("%s", receita.nome);
        printf("Tempo de preparo (min): ");
        scanf("%f", &receita.tempo_preparo);
        printf("Dificuldade (F, M, D): ");
        scanf(" %c", &receita.dificuldade);
        printf("Porcoes: ");
        scanf("%d", &receita.porcoes);
        printf("Custo (R$): ");
        scanf("%f", &receita.custo);
        inserirElementoInicio(lista, receita);
        break;
    case 4:
        listarElementos(lista);
        break;
    case 5:
        printf("Informe a posicao para remocao: ");
        scanf("%d", &posicao);
        removerElemento(lista, posicao);
        break;
    case 6:
        printf("Informe o ID da receita para atualizar: ");
        scanf("%d", &id);
        atualizar(lista, id);
        break;
    case 7:
        printf("Informe o ID da receita para buscar: ");
        scanf("%d", &id);
        buscarElemento(lista, id);
        break;
    case 8:
        printf("Tamanho da lista: %d\n", tamanho(lista));
        break;
    case 9:
        carregarDados(lista);
        break;
    case 10:
        salvarDados(lista);
        break;
    case 11:
        excluirLista(lista);
        printf("Programa encerrado.\n");
        return 0;
    default:
        printf("Opcao invalida.\n");
    }
} while (opcao != 11);

return 0;
}
