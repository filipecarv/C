#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEICULOS 10
#define MAX_MARCA_MODELO 29

struct Veiculo
{
    char tipo[10];
    char marca[MAX_MARCA_MODELO + 1];
    char modelo[MAX_MARCA_MODELO + 1];
    int codigo;
};

void registrarVeiculo(struct Veiculo veiculos[], int *numVeiculos);
void gerarRelatorio(struct Veiculo veiculos[], int numVeiculos);

int main()
{
    struct Veiculo veiculos[MAX_VEICULOS];
    int numVeiculos = 0;
    int opcao;

    printf("----- Boa Tarde -----\n");
    do
    {
        printf("\n--- Menu ---\n");
        printf("[1] Registrar Veiculo\n");
        printf("[2] Gerar Relatorio\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Erro na leitura da opcao. Saindo do programa...\n");
            return 1;
        }

        switch (opcao)
        {
        case 1:
            registrarVeiculo(veiculos, &numVeiculos);
            break;
        case 2:
            if (numVeiculos == 0)
            {
                printf("Nenhum veiculo registrado. Registre um veiculo antes de gerar o relatorio.\n");
            }
            else
            {
                gerarRelatorio(veiculos, numVeiculos);
            }
            break;
        case 0:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void registrarVeiculo(struct Veiculo veiculos[], int *numVeiculos)
{
    if (*numVeiculos >= MAX_VEICULOS)
    {
        printf("Limite maximo de veiculos atingido!\n");
        return;
    }

    printf("\nRegistro de Veiculo:\n");

    int tipo;
    do
    {
        printf("--- Tipo de Veiculo ---\n[1] Carro\n[2] Moto\n[3] Caminhao\nQual opcao voce deseja: ");
        scanf("%d", &tipo);
        if (tipo < 1 || tipo > 3)
        {
            printf("Opcao invalida! Escolha 1, 2 ou 3.\n");
        }
    } while (tipo < 1 || tipo > 3);

    strcpy(veiculos[*numVeiculos].tipo, (tipo == 1) ? "Carro" : (tipo == 2) ? "Moto"
                                                                            : "Caminhao");

    printf("Marca: ");
    scanf("%29s", veiculos[*numVeiculos].marca);
    printf("Modelo: ");
    scanf("%29s", veiculos[*numVeiculos].modelo);
    printf("Codigo: ");
    scanf("%d", &veiculos[*numVeiculos].codigo);

    (*numVeiculos)++;
    printf("Veiculo registrado com sucesso!\n");
}

void gerarRelatorio(struct Veiculo veiculos[], int numVeiculos)
{
    FILE *arquivo;
    arquivo = fopen("relatorio.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fprintf(arquivo, "----- Relatorio de Veiculos -----\n\n");
    for (int i = 0; i < numVeiculos; i++)
    {
        fprintf(arquivo, "Veiculo %d:\n", i + 1);
        fprintf(arquivo, "  Tipo: %s\n", veiculos[i].tipo);
        fprintf(arquivo, "  Marca: %s\n", veiculos[i].marca);
        fprintf(arquivo, "  Modelo: %s\n", veiculos[i].modelo);
        fprintf(arquivo, "  Codigo: %d\n\n", veiculos[i].codigo);
    }

    fclose(arquivo);
    printf("Relatorio gerado com sucesso em 'relatorio.txt'!\n");
}
