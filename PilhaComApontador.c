/*Alunos: Luiz Filipe e Mara Rúbia*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do tipo Pilha
typedef struct Pilha {
    int id;
    char nome[100];
    float tempo_preparo;
    char dificuldade;
    int porcoes;
    float custo;
    struct Pilha* proximo;
} Pilha;

// Função para criar uma pilha (inicializa a pilha vazia)
Pilha* criarPilha() {
    return NULL; // Pilha vazia
}

// Função push (inserir no topo da pilha)
void push(Pilha** topo, int id, const char* nome, float tempo_preparo, char dificuldade, int porcoes, float custo) {
    Pilha* nova = (Pilha*) malloc(sizeof(Pilha));
    nova->id = id;
    strcpy(nova->nome, nome);
    nova->tempo_preparo = tempo_preparo;
    nova->dificuldade = dificuldade;
    nova->porcoes = porcoes;
    nova->custo = custo;
    nova->proximo = *topo;
    *topo = nova;
    printf("Receita inserida no topo da pilha com sucesso!\n");
}

// Função pop (remover do topo da pilha)
void pop(Pilha** topo) {
    if (*topo == NULL) {
        printf("A pilha esta vazia. Nenhum elemento para remover.\n");
        return;
    }
    
    Pilha* temp = *topo;
    *topo = (*topo)->proximo;
    free(temp);
    printf("Elemento removido do topo da pilha.\n");
}

// Função ehVazia (verifica se a pilha est� vazia)
int ehVazia(Pilha* topo) {
    return topo == NULL;
}

// Função verTopo (verifica o conteudo do topo da pilha)
void verTopo(Pilha* topo) {
    if (topo == NULL) {
        printf("A pilha esta vazia.\n");
    } else {
        printf("Topo da pilha:\n");
        printf("ID: %d\n", topo->id);
        printf("Nome: %s\n", topo->nome);
        printf("Tempo de preparo: %.2f minutos\n", topo->tempo_preparo);
        printf("Dificuldade: %c\n", topo->dificuldade);
        printf("Porcoes: %d\n", topo->porcoes);
        printf("Custo: R$ %.2f\n", topo->custo);
        printf("-----------------------------\n");
    }
}

// Função excluirPilha (apaga todos os elementos da pilha)
void excluirPilha(Pilha** topo) {
    while (*topo != NULL) {
        Pilha* temp = *topo;
        *topo = (*topo)->proximo;
        free(temp);
    }
    printf("A pilha foi excluida com sucesso!\n");
}

// Função carregarDados (carrega dados do arquivo para a pilha)
void carregarDados(Pilha** topo) {
    FILE* arquivo = fopen("dados_pilha.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (!feof(arquivo)) {
        Pilha nova;
        fscanf(arquivo, "%d\n", &nova.id);
        fgets(nova.nome, 100, arquivo);
        nova.nome[strcspn(nova.nome, "\n")] = 0;  // Remover o '\n' extra de fgets
        fscanf(arquivo, "%f\n", &nova.tempo_preparo);
        fscanf(arquivo, "%c\n", &nova.dificuldade);
        fscanf(arquivo, "%d\n", &nova.porcoes);
        fscanf(arquivo, "%f\n", &nova.custo);

        push(topo, nova.id, nova.nome, nova.tempo_preparo, nova.dificuldade, nova.porcoes, nova.custo);
    }

    fclose(arquivo);
    printf("Dados carregados do arquivo com sucesso!\n");
}

// Função salvarDados (salva os dados da pilha em um arquivo)
void salvarDados(Pilha* topo) {
    FILE* arquivo = fopen("dados_pilha.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Pilha* temp = topo;
    while (temp != NULL) {
        fprintf(arquivo, "%d\n", temp->id);
        fprintf(arquivo, "%s\n", temp->nome);
        fprintf(arquivo, "%.2f\n", temp->tempo_preparo);
        fprintf(arquivo, "%c\n", temp->dificuldade);
        fprintf(arquivo, "%d\n", temp->porcoes);
        fprintf(arquivo, "%.2f\n", temp->custo);
        temp = temp->proximo;
    }

    fclose(arquivo);
    printf("Dados salvos no arquivo com sucesso!\n");
}

// Função main (menu e interação com o usuário)
int main() {
    Pilha* topo = criarPilha();

    int opcao;
    do {
        printf("\n--- Menu ---\n");
        printf("[1] Inserir Receita no Topo\n");
        printf("[2] Remover Receita do Topo\n");
        printf("[3] Ver Topo da Pilha\n");
        printf("[4] Exibir se a Pilha esta Vazia\n");
        printf("[5] Carregar Dados do Arquivo\n");
        printf("[6] Salvar Dados no Arquivo\n");
        printf("[7] Excluir Pilha e Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado após scanf

        switch(opcao) {
            case 1: {
                int id;
                char nome[100];
                float tempo_preparo, custo;
                char dificuldade;
                int porcoes;

                printf("Informe o ID da receita: ");
                scanf("%d", &id);
                getchar(); // Limpar o buffer
                printf("Informe o nome da receita: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = 0;  // Remover o '\n' extra de fgets
                printf("Informe o tempo de preparo (em minutos): ");
                scanf("%f", &tempo_preparo);
                getchar();
                printf("Informe a dificuldade (F = Facil, M = Medio, D = Dificil): ");
                dificuldade = getchar();
                getchar();  // Limpar o buffer
                printf("Informe o numero de porcoes: ");
                scanf("%d", &porcoes);
                printf("Informe o custo da receita: ");
                scanf("%f", &custo);

                push(&topo, id, nome, tempo_preparo, dificuldade, porcoes, custo);
                break;
            }
            case 2:
                pop(&topo);
                break;
            case 3:
                verTopo(topo);
                break;
            case 4:
                if (ehVazia(topo)) {
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("A pilha nao esta vazia.\n");
                }
                break;
            case 5:
                carregarDados(&topo);
                break;
            case 6:
                salvarDados(topo);
                break;
            case 7:
                excluirPilha(&topo);
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 7);

    return 0;
}
