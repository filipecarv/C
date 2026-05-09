/*Alunos: Luiz Filipe e Mara Rúbia*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;
typedef struct listaNo ListaNo;

struct lista {
    ListaNo *prim;
};

struct listaNo {
    int id;
    char nome[50];
    int tempo_preparo;
    char dificuldade;
    int porcoes;
    float custo;
    ListaNo *prox;
};

/* Funções implementadas */
int AtualizarReceitas(Lista*, int, ListaNo);
ListaNo* BuscarReceitas(Lista*, int);
Lista* Criar();
int InserirReceita(Lista*, ListaNo);
int InserirReceitaID(Lista*, ListaNo, int);
int InserirReceitaInicio(Lista*, ListaNo);
int tamanho(Lista*);
void ImprimirReceita(Lista *lista);
int RemoverReceita(Lista*, int);
Lista* Excluir(Lista* lista);
void SalvarDados(Lista *lista, const char *nomeArquivo);
void CarregarDados(Lista *lista, const char *nomeArquivo);

int main() {
    Lista *lista = Criar();
    int opcao;
    ListaNo receita;

    do {
        printf("\n---Menu---\n");
        printf("[1] Inserir Receita\n");
        printf("[2] Inserir Receita no Inicio\n");
        printf("[3] Inserir Receita no ID Especifico\n");
        printf("[4] Imprimir Receitas\n");
        printf("[5] Buscar Receita\n");
        printf("[6] Remover Receita\n");
        printf("[7] Atualizar Receita\n");
        printf("[8] Salvar Dados\n");
        printf("[9] Carregar Dados\n");
        printf("[10] Excluir Lista\n");
        printf("[11] Tamanho da Lista\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao meu bom: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: /*Inserir Receitas*/
                printf("\n---Inserir Receitas---\n");
                printf("|ID: ");
                scanf("%d",&receita.id);
                printf("|Nome: ");
                scanf("%s",receita.nome);
                printf("|Tempo de preparo: ");
                scanf("%d",&receita.tempo_preparo);
                printf("|Dificuldade: ");
                scanf(" %c",&receita.dificuldade);
                printf("|Porcoes: ");
                scanf("%d",&receita.porcoes);
                printf("|Custo: ");
                scanf("%f",&receita.custo);
                InserirReceita(lista, receita);
                break;

            case 2: /*Inserir Receita no Início*/
                printf("\n---Inserir Receita no Inicio---\n");
                printf("|ID: ");
                scanf("%d",&receita.id);
                printf("|Nome: ");
                scanf("%s",receita.nome);
                printf("|Tempo de preparo: ");
                scanf("%d",&receita.tempo_preparo);
                printf("|Dificuldade: ");
                scanf(" %c",&receita.dificuldade);
                printf("|Porcoes: ");
                scanf("%d",&receita.porcoes);
                printf("|Custo: ");
                scanf("%f",&receita.custo);
                InserirReceitaInicio(lista, receita);
                break;

            case 3: /*Inserir Receita no ID Específico*/
                printf("\n---Inserir Receita no ID Especifico---\n");
                printf("|ID: ");
                scanf("%d",&receita.id);
                printf("|Nome: ");
                scanf("%s",receita.nome);
                printf("|Tempo de preparo: ");
                scanf("%d",&receita.tempo_preparo);
                printf("|Dificuldade: ");
                scanf(" %c",&receita.dificuldade);
                printf("|Porcoes: ");
                scanf("%d",&receita.porcoes);
                printf("|Custo: ");
                scanf("%f",&receita.custo);
                printf("Digite o ID onde deseja inserir: ");
                int idInserir;
                scanf("%d", &idInserir);
                if (InserirReceitaID(lista, receita, idInserir)) {
                    printf("Receita inserida com sucesso!\n");
                } else {
                    printf("ID ja existe meu bom!\n");
                }
                break;

            case 4: /*Imprimir Receitas*/
                printf("\n---Imprimir Receitas---\n");
                ImprimirReceita(lista);
                break;

            case 5: /*Buscar Receitas*/
                printf("\n---Buscar Receitas---\n");
                printf("Digite o ID da receita meu bom: ");
                scanf("%d", &receita.id);
                ListaNo *resultado = BuscarReceitas(lista, receita.id);
                if (resultado) {
                    printf("|ID: %d\n", resultado->id);
                    printf("|Nome: %s\n", resultado->nome);
                    printf("|Tempo de preparo: %d minutos\n", resultado->tempo_preparo);
                    printf("|Dificuldade: %c\n", resultado->dificuldade);
                    printf("|Porcoes: %d\n", resultado->porcoes);
                    printf("|Custo: R$%.2f\n", resultado->custo);
                } else {
                    printf("Receita nao encontrada meu bom!\n");
                }
                break;

            case 6: /*Remover Receitas*/
                printf("\n---Remover Receitas---\n");
                printf("Digite o ID da receita meu bom: ");
                scanf("%d", &receita.id);
                if (RemoverReceita(lista, receita.id)) {
                    printf("Receita removida com sucesso meu bom!\n");
                } else {
                    printf("Receita nao encontrada meu bom!\n");
                }
                break;

            case 7: /*Atualizar Receitas*/
                printf("\n---Atualizar Receitas---\n");
                printf("Digite o ID da receita meu bom: ");
                scanf("%d", &receita.id);
                printf("|Nome: ");
                scanf("%s",receita.nome);
                printf("|Tempo de preparo: ");
                scanf("%d",&receita.tempo_preparo);
                printf("|Dificuldade: ");
                scanf(" %c",&receita.dificuldade);
                printf("|Porcoes: ");
                scanf("%d",&receita.porcoes);
                printf("|Custo: ");
                scanf("%f",&receita.custo);
                if (AtualizarReceitas(lista, receita.id, receita)) {
                    printf("Receita atualizada com sucesso meu bom!\n");
                } else {
                    printf("Receita nao encontrada meu bom!\n");
                }
                break;

            case 8: /*Salvar*/
                printf("\n---Salvar Receitas---\n");
                SalvarDados(lista, "receitas.txt");
                printf("Dados salvos com sucesso meu bom!\n");
                break;

            case 9: /*Carregar*/
                printf("\n---Carregar Receitas---\n");
                CarregarDados(lista, "receitas.txt");
                printf("Dados carregados com sucesso meu bom!\n");
                break;

            case 10: /*Excluir Lista*/
                printf("\n---Excluir Lista---\n");
                lista = Excluir(lista);
                printf("Lista excluída com sucesso meu bom!\n");
                break;

            case 11: /*Tamanho*/
                printf("Total de receitas na lista meu bom!: %d\n", tamanho(lista));
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

/* Função para inserir receita no ID específico */
int InserirReceitaID(Lista *lista, ListaNo valor, int id) {
    ListaNo *p, *nova = (ListaNo*) malloc(sizeof(ListaNo));

    if (nova == NULL) {
        printf("Sem espaco\n");
        return 0;
    }

    *nova = valor;
    nova->prox = NULL;

    if (lista->prim == NULL) {
        lista->prim = nova;
        return 1;
    }

    for (p = lista->prim; p != NULL; p = p->prox) {
        if (p->id == id) {
            printf("ID ja existe meu bom!\n");
            free(nova);
            return 0;
        }
    }

    nova->prox = lista->prim;
    lista->prim = nova;

    return 1;
}

/* Função para inserir receita no início */
int InserirReceitaInicio(Lista *lista, ListaNo valor) {
    ListaNo *nova = (ListaNo*) malloc(sizeof(ListaNo));

    if (nova == NULL) {
        printf("Sem espaco\n");
        return 0;
    }

    *nova = valor;
    nova->prox = lista->prim;
    lista->prim = nova;

    return 1;
}

/* Função para retornar o tamanho da lista */
int tamanho(Lista *lista) {
    int count = 0;
    ListaNo *p;

    if (lista == NULL) {
        printf("A lista nao foi criada meu bom!\n");
        return count;
    }

    for (p = lista->prim; p != NULL; p = p->prox) {
        count++;
    }

    return count;
}

/*Função para atualizar receitas*/
int AtualizarReceitas(Lista *lista, int busca, ListaNo novaReceita) {
    ListaNo *p;

    if (lista == NULL) {
        printf("A lista nao foi criada meu bom!\n");
        return 0;
    }

    if (lista->prim == NULL) {
        printf("A lista esta vazia meu bom!\n");
        return 0;
    }

    for (p = lista->prim; p != NULL; p = p->prox) {
        if (p->id == busca) {
            *p = novaReceita;
            return 1;
        }
    }
    return 0;
}


/*Função para buscar receitas*/
ListaNo* BuscarReceitas(Lista *lista, int valor) {
    ListaNo *p;
    
    if (lista == NULL) {
        printf("A lista nao foi criada meu bom!\n");
        return NULL;
    }

    if (lista->prim == NULL) {
        printf("A lista esta vazia meu bom!\n");
        return NULL;
    }

 for (p = lista->prim; p != NULL; p = p->prox) {
        if (p->id == valor) {
            return p;
        }
    }
    return NULL;
}


/* Função para criar uma lista*/
Lista* Criar() {

    Lista *nova = (Lista*)malloc(sizeof(Lista));
    
    if (nova == NULL) {
        printf("Sem espaco!\n");
        return NULL;
    }
    nova->prim = NULL;

    return nova;
}


/* Função para excluir uma lista*/
Lista* Excluir(Lista* lista) {
    ListaNo *aux;

    if (lista == NULL) {
        printf("A lista nao foi criada meu bom!\n");
        return NULL;
    }

    while (lista->prim != NULL) {
        aux = lista->prim;
        lista->prim = lista->prim->prox;
        free(aux);
    }

    free(lista);
    
    return NULL;
}


/* Função Para inserir Receitas*/
int InserirReceita(Lista *lista, ListaNo valor) {
    ListaNo *p; 

    ListaNo *nova = (ListaNo*) malloc(sizeof(ListaNo));

    if (nova == NULL) {
        printf("Sem espaco\n");
        return 0;
    }

    *nova = valor;
    nova->prox = NULL;

    if (lista->prim == NULL) {
        lista->prim = nova;
        return 1;
    }

    for (p = lista->prim; p->prox != NULL; p = p->prox);
    p->prox = nova;

    return 1;
}


/*Função para imprimir as receitas*/
void ImprimirReceita(Lista *lista) {
    ListaNo *p;

    if (lista == NULL) {
        printf("A lista nao foi criada meu bom!\n");
        return ;
    }

    if (lista->prim == NULL) {
        printf("A lista esta vazia meu bom!\n");
        return ;
    }

    for (p = lista->prim; p != NULL; p = p->prox) {
        printf("|ID: %d\n", p->id);
        printf("|Nome: %s\n", p->nome);
        printf("|Tempo de preparo: %d minutos\n", p->tempo_preparo);
        printf("|Dificuldade: %c\n", p->dificuldade);
        printf("|Porcoes: %d\n", p->porcoes);
        printf("|Custo: R$%.2f\n\n", p->custo);
    }
    printf("\n");
}


/*Função para remover receitas*/
int RemoverReceita(Lista *lista, int valor) {
    ListaNo *p, *aux;

    if (lista == NULL) {
        printf("A lista nao foi criada meu bom!\n");
        return 0;
    }

    if (lista->prim == NULL) {
        printf("A lista esta vazia meu bom!\n");
        return 0;
    }

    if (lista->prim->id == valor) {
        p = lista->prim;
        lista->prim = lista->prim->prox;
        free(p);
        return 1;
    }

    for (p = lista->prim; p->prox->prox != NULL; p = p->prox) {
        if (p->prox->id == valor) {
            aux = p->prox;
            p->prox = p->prox->prox;
            free(aux);
            return 1;
        }
    }

    if (p->prox->id == valor) {
        aux = p->prox;
        p->prox = NULL;
        free(aux);
        return 1;
    }
    
    return 0;
}


/*Função para salvar dados em receitas*/
void SalvarDados(Lista *lista, const char *receitas) {
    FILE *arquivo;
    ListaNo *p;

    arquivo = fopen(receitas, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (p = lista->prim; p != NULL; p = p->prox) {
        fprintf(arquivo, "%d;%s;%d;%c;%d;%.2f\n", p->id, p->nome, p->tempo_preparo, p->dificuldade, p->porcoes, p->custo);
    }

    fclose(arquivo);
}


/*Função para carregar dados de receitas*/
void CarregarDados(Lista *lista, const char *receitas) {
    FILE *arquivo;
    char linha[1024];
    ListaNo receita;

    arquivo = fopen(receitas, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fgets(linha, 1024, arquivo) != NULL) {
        sscanf(linha, "%d;%[^;];%d;%c;%d;%f", &receita.id, receita.nome, &receita.tempo_preparo, &receita.dificuldade, &receita.porcoes, &receita.custo);
        InserirReceita(lista, receita);
    }

    fclose(arquivo);
}