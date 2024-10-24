
/****************************************************************** 
 * Nome: Lista encadeada                                          *
 * Descricao: Implementacao de lista encadeada. Esse codigo possui*
 *            as principais operacoes da lista, como:             *
 *            criar lista,                                        *
 *            inserir elemento,                                   *
 *            remover elemento,                                   *
 *            buscar elemento,                                    *
 *            mostrar elementos,                                  *
 *            atualizar elementos,                                *
 *            excluir lista.                                      *
 * Autor: Luiz Filipe e Mara Rubia                                *
 * Ultima alteracao: 08/10/2024                                   *
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char nome[50];
    int tempo_preparo;
    char dificuldade; // F, M ou D
    int porcoes;
    float custo;
} Receita;

typedef struct {
    Receita receitas[MAX];
    int tamanho;
} Lista;

struct lista{
    Receita *prim;
};

struct Receita{
    int valor;
    Receita *prox;
};

/* Funcões implementadas */
int atualizarReceita(Lista *, int, Receita);
int buscarReceita(Lista *, int);
Lista *criar();
Lista *excluir(Lista *);
void imprimirReceita(Lista *);
int inserirReceita(Lista *, Receita);
int removerReceita(Lista *, int);

/* Funcao principal */
int main()
{
    Lista *lista = criar();
    if (lista == NULL)
    {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    Receita Rec1 = {1, "Bolo de Chocolate", 45, 'M', 12, 35};
    Receita Rec2 = {2, "Bolo de Morango", 45, 'M', 12, 35};
    Receita Rec3 = {3, "Torta de Limão", 30, 'M', 10, 28};
    Receita Rec4 = {4, "Cupcake de Bauniha", 20, 'F', 1, 22};
    Receita Rec5 = {5, "Pudim", 30, 'M', 10, 34};

    /*exemplo de chamada da funcoes*/

    inserirReceita(lista, Rec1);
    inserirReceita(lista, Rec2);
    inserirReceita(lista, Rec3);
    inserirReceita(lista, Rec4);
    inserirReceita(lista, Rec5);
    imprimirReceita(lista);

    buscarReceita(lista, 2);


    removerReceita(lista, 5);
    imprimirReceita(lista);

    printf("\n---Atualizando receitas---\n");
    Receita ReceitaAtualizada = {3, "Torta de Maçã", 30, 'M', 10, 28};
    atualizarReceita(lista, 3, ReceitaAtualizada);

    lista = excluir(lista);
    if (lista == NULL)
    {
        printf("Lista excluida com sucesso meu bom.\n");
    }

    return 0;
}

/* Função para criar uma lista*/

Lista* criar(Lista* lista) {
    lista->tamanho = 0;
    printf("Lista Receitas\n");
}


/* Função para excluir uma lista*/
Lista *excluir(Lista *lista)
{
    if (lista == NULL)
    {
        printf("A lista nao foi criada.\n");
        return NULL;
    }
    free(lista->receitas); 
    free(lista);    
    return NULL;
}

/*Função para imprimir as receitas*/

void imprimirReceita(Lista* lista) {
	int i;
    if (lista->tamanho == 0) {
        printf("Lista de receitas vazia.\n");
    } else {
        printf("ID\tNome\t\tTempo (min)\tDificuldade\tPorções\tCusto (R$)\n");
        for (i = 0; i < lista->tamanho; i++) {
            printf("%d\t%s\t\t%d\t\t%c\t\t%d\t%.2f\n", 
                lista->receitas[i].id, 
                lista->receitas[i].nome, 
                lista->receitas[i].tempo_preparo, 
                lista->receitas[i].dificuldade, 
                lista->receitas[i].porcoes, 
                lista->receitas[i].custo);
        }
    }
}

/* Função Para inserir Receitas*/

void inserirReceita(Lista* lista, Receita receita) {
    if (lista->tamanho < MAX) {
        lista->receitas[lista->tamanho] = receita;
        lista->tamanho++;
        printf("Receita adicionada com sucesso!\n");
    } else {
        printf("Lista cheia. Não é possível adicionar a receita.\n");
    }
}

/*Função para remover receitas*/

int removerReceita(Lista *lista, int id)
{
    if (lista == NULL)
    {
        printf("A lista nao foi criada.\n");
        return 0;
    }

    for (int i = 0; i < lista->tamanho; ++i)
    {
        if (lista->receitas[i].id == id)
        {
            for (int j = i; j < lista->tamanho - 1; ++j)
            {
                lista->receitas[j] = lista->receitas[j + 1];
            }
            lista->tamanho--;
            return 1;
        }
    }

    printf("Receita nao encontrada meu bom.\n");
    return 0;
}

/*Função para buscar receitas*/

int buscarReceita(Lista *lista, int id)
{
    if (lista == NULL)
    {
        printf("A lista nao foi criada.\n");
        return -1;
    }

    for (int i = 0; i < lista->tamanho; ++i)
    {
        if (lista->receitas[i].id == id)
        {
            return i;
        }
    }

    printf("receita nao encontrada meu bom.\n");
    return -1;
}

/*Função para atualizar receitas*/

int atualizarReceita(Lista *lista, int id, Receita receitaAtualizada)
{
    int index = buscarReceita(lista, id);
    if (index == -1)
    {
        printf("receita nao encontrada meu bom.\n");
        return 0;
    }

    lista->receitas[index] = receitaAtualizada;
    return 1;
}