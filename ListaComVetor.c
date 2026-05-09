/*Alunos: Luiz Filipe e Mara Rúbia*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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

void criarLista(Lista* lista) {
    lista->tamanho = 0;
    printf("Lista Receitas\n");
}

void inserirElemento(Lista* lista, Receita receita) {
    if (lista->tamanho < MAX) {
        lista->receitas[lista->tamanho] = receita;
        lista->tamanho++;
        printf("Receita adicionada com sucesso!\n");
    } else {
        printf("Lista cheia. Não é possível adicionar a receita.\n");
    }
}

void inserirElementoID(Lista* lista, Receita receita, int posicao) {
	int i;
    if (posicao < 0 || posicao > lista->tamanho || lista->tamanho >= MAX) {
        printf("Posição inválida ou lista cheia.\n");
    } else {
        for (i = lista->tamanho; i > posicao; i--) {
            lista->receitas[i] = lista->receitas[i - 1];
        }
        lista->receitas[posicao] = receita;
        lista->tamanho++;
        printf("Receita adicionada na posição %d com sucesso!\n", posicao);
    }
}

void inserirElementoInicio(Lista* lista, Receita receita) {
    inserirElementoID(lista, receita, 0);
}

void listarElementos(const Lista* lista) {
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

void removerElemento(Lista* lista, int posicao) {
	int i;
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida.\n");
    } else {
        for (i = posicao; i < lista->tamanho - 1; i++) {
            lista->receitas[i] = lista->receitas[i + 1];
        }
        lista->tamanho--;
        printf("Receita removida com sucesso!\n");
    }
}

void atualizar(Lista* lista, int posicao, Receita receita) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida.\n");
    } else {
        lista->receitas[posicao] = receita;
        printf("Receita atualizada com sucesso!\n");
    }
}

int buscarElemento(const Lista* lista, int id) {
	int i;
    for (i = 0; i < lista->tamanho; i++) {
        if (lista->receitas[i].id == id) {
            return i; // Retorna a posição
        }
    }
    return -1; // Não encontrado
}

int tamanho(const Lista* lista) {
    return lista->tamanho;
}

void excluirLista(Lista* lista) {
    lista->tamanho = 0;
    printf("Lista excluída com sucesso!\n");
}

void carregarDados(Lista* lista) {
    FILE* file = fopen("receitas.txt", "r");
    if (file == NULL) {
        printf("Gerenciador de Receitas 2.0\n");
        return;
    }

    while (fscanf(file, "%d;%49[^;];%d;%c;%d;%f",
                  &lista->receitas[lista->tamanho].id,
                  lista->receitas[lista->tamanho].nome,
                  &lista->receitas[lista->tamanho].tempo_preparo,
                  &lista->receitas[lista->tamanho].dificuldade,
                  &lista->receitas[lista->tamanho].porcoes,
                  &lista->receitas[lista->tamanho].custo) == 6) {
        lista->tamanho++;
    }

    fclose(file);
    printf("Gerenciador de Receitas Plus\n");
}

void salvarDados(const Lista* lista) {
	int i;
    FILE* file = fopen("receitas.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    for (i = 0; i < lista->tamanho; i++) {
        fprintf(file, "%d;%s;%d;%c;%d;%.2f\n", 
                lista->receitas[i].id, 
                lista->receitas[i].nome, 
                lista->receitas[i].tempo_preparo, 
                lista->receitas[i].dificuldade, 
                lista->receitas[i].porcoes, 
                lista->receitas[i].custo);
    }

    fclose(file);
    printf("Dados salvos com sucesso!\n");
}

int main() {
    setlocale(LC_ALL, ""); // Adicione esta linha
    Lista lista;
    criarLista(&lista);
    carregarDados(&lista);

    int opcao;
    do {
        printf("\n=== Gerenciador de Receitas ===\n");
        printf("1. Adicionar Receita\n");
        printf("2. Adicionar Receita na Posição\n");
        printf("3. Adicionar Receita no Início\n");
        printf("4. Listar Receitas\n");
        printf("5. Remover Receita pela Posição\n");
        printf("6. Atualizar Receita pela Posição\n");
        printf("7. Buscar Receita pelo ID\n");
        printf("8. Tamanho da Lista\n");
        printf("9. Excluir Lista\n");
        printf("10. Salvar Dados\n");
        printf("11. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Receita receita;
                printf("ID: ");
                scanf("%d", &receita.id);
                printf("Nome: ");
                scanf(" %[^\n]", receita.nome);
                printf("Tempo de Preparo (min): ");
                scanf("%d", &receita.tempo_preparo);
                printf("Dificuldade (F - Facil, M - Media, D - Dificil): ");
                scanf(" %c", &receita.dificuldade);
                printf("Porções: ");
                scanf("%d", &receita.porcoes);
                printf("Custo (R$): ");
                scanf("%f", &receita.custo);
                inserirElemento(&lista, receita);
                break;
            }
            case 2: {
                Receita receita;
                int posicao;
                printf("Posição para adicionar: ");
                scanf("%d", &posicao);
                printf("ID: ");
                scanf("%d", &receita.id);
                printf("Nome: ");
                scanf(" %[^\n]", receita.nome);
                printf("Tempo de Preparo (min): ");
                scanf("%d", &receita.tempo_preparo);
                printf("Dificuldade (F - Facil, M - Media, D - Dificil): ");
                scanf(" %c", &receita.dificuldade);
                printf("Porções: ");
                scanf("%d", &receita.porcoes);
                printf("Custo (R$): ");
                scanf("%f", &receita.custo);
                inserirElementoID(&lista, receita, posicao);
                break;
            }
            case 3: {
                Receita receita;
                printf("ID: ");
                scanf("%d", &receita.id);
                printf("Nome: ");
                scanf(" %[^\n]", receita.nome);
                printf("Tempo de Preparo (min): ");
                scanf("%d", &receita.tempo_preparo);
                printf("Dificuldade (F - Facil, M - Media, D - Dificil): ");
                scanf(" %c", &receita.dificuldade);
                printf("Porções: ");
                scanf("%d", &receita.porcoes);
                printf("Custo (R$): ");
                scanf("%f", &receita.custo);
                inserirElementoInicio(&lista, receita);
                break;
            }
            case 4:
                listarElementos(&lista);
                break;
            case 5: {
                int posicao;
                printf("Posição da receita a remover: ");
                scanf("%d", &posicao);
                removerElemento(&lista, posicao);
                break;
            }
            case 6: {
                int posicao;
                Receita receita;
                printf("Posição da receita a atualizar: ");
                scanf("%d", &posicao);
                printf("ID: ");
                scanf("%d", &receita.id);
                printf("Nome: ");
                scanf(" %[^\n]", receita.nome);
                printf("Tempo de Preparo (min): ");
                scanf("%d", &receita.tempo_preparo);
                printf("Dificuldade (F - Facil, M - Media, D - Dificil): ");
                scanf(" %c", &receita.dificuldade);
                printf("Porções: ");
                scanf("%d", &receita.porcoes);
                printf("Custo (R$): ");
                scanf("%f", &receita.custo);
                atualizar(&lista, posicao, receita);
                break;
            }
            case 7: {
                int id;
                printf("ID da receita a buscar: ");
                scanf("%d", &id);
                int pos = buscarElemento(&lista, id);
                if (pos != -1) {
                    printf("Receita encontrada na posição %d.\n", pos);
                } else {
                    printf("Receita não encontrada.\n");
                }
                break;
            }
            case 8:
                printf("Tamanho da lista: %d\n", tamanho(&lista));
                break;
            case 9:
                excluirLista(&lista);
                break;
            case 10:
                salvarDados(&lista);
                break;
            case 11:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 11);

    return 0;
}