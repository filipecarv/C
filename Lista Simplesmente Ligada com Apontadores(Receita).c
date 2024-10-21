/****************************************************************** 
 * Nome: Lista Simplesmente Ligada com Apontadores                *
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
 * Ultima alteracao: 21/10/2024                                   *
 ******************************************************************/

/*Include das bibliotecas*/ 
#include <stdio.h>
#include <stdlib.h>

/*Definicao da estrutura Lista e do elemento da lista*/ 
typedef struct receita Receita;
typedef struct receitaNO ReceitaNO;

struct receita{
    ReceitaNO *prim;
};

struct receitaNO{
    int valor;
    ReceitaNO *prox;
};

/*Funcoes implementadas*/
int AtualizarReceita(Receita*, int, int);
ReceitaNO* BuscarReceita(Receita*, int);
Receita* CriarLista();
int InserirReceita(Receita*, int);
void ImprimirReceitas(Receita *receita);
int RemoverReceita(Receita*, int);
Receita* ExcluirLista(Receita* receita);

int main(){
    /*Ponteiro usado para a criacao da lista*/
    Receita *receita = NULL;
    ReceitaNO *pesquisa = NULL;

    /*exemplo de chamada da funcoes*/
    receita = CriarLista();
    
    ImprimirReceitas(receita);
    InserirReceita(receita, 1);
    ImprimirReceitas(receita);
    InserirReceita(receita, 2);
    ImprimirReceitas(receita);
    InserirReceita(receita, 3);
    ImprimirReceitas(receita);
    InserirReceita(receita, 4);
    ImprimirReceitas(receita);
    InserirReceita(receita, 5);
    ImprimirReceitas(receita);
    InserirReceita(receita, 6);
    ImprimirReceitas(receita);
    InserirReceita(receita, 7);
    ImprimirReceitas(receita);

    pesquisa = BuscarReceita(receita, 3);
    if(pesquisa == NULL){
        printf("Receita nao encontrada\n");
    }else{
        printf("Receita %d\n", pesquisa->valor);
    }
    printf("Removendo o 4\n");
    RemoverReceita(receita, 4);
    ImprimirReceitas(receita);
    AtualizarReceita(receita, 5, 9);
    ImprimirReceitas(receita);

    receita = ExcluirLista(receita);
    ImprimirReceitas(receita);

    
    return 0;
}

/* Nome: AtualizarReceita
 * Parametros: lista - ponteiro que possui o endereco lista
 *             busca - receita que sera buscado na lista
 *             valor - novo valor da receita que sera alterado 
 * Retorno: 1 - quando o valor e atualizado e 0 - caso contrario
 * Descricao: Funcao responsavel por atualizar uma receita
 *            da lista, caso o mesmo esteja na lista indicada
 */
int AtualizarReceita(Receita *receita, int busca, int valor){
    ReceitaNO *p;

    /*Verificando se a lista foi criada*/
    if(receita == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    /*Verificando se a lista possui receitas*/
    if(receita->prim == NULL){
        printf("A lista esta vazia\n");
        return 0;
    }

    /*percorrendo todas as receitas presentes na lista*/
    for(p = receita->prim; p != NULL; p = p->prox){
        /*condicao que verifica se a receita da lista e igual a busca*/
        if(p->valor == busca){
            /*atualizando a receita*/
            p->valor = valor;
            return 1;
        }
    }
    return 0;
}


/* Nome: BuscarReceita
 * Parametro: lista - ponteiro que possui o endereco lista
 *            valor - receita que sera buscado na lista
 * Retorno: ponteiro com endereco da receita encontrado, NULL caso contrario
 * Descricao: Funcao criada para buscar uma receita na lista
 */
ReceitaNO* BuscarReceita(Receita *receita, int valor){
    ReceitaNO *p;
    
    /*Verificando se a lista foi criada*/
    if(receita == NULL){
        printf("A lista nao foi criada\n");
        return NULL;
    }

    /*Verificando se a lista possui receitas*/
    if(receita->prim == NULL){
        printf("A lista esta vazia\n");
        return NULL;
    }

    /*Percorrendo todos os elementos presentes na lista*/
    for(p = receita->prim; p != NULL; p = p->prox){
        /*Verificando se a receita atual e igual ao valor buscado*/
        if(p->valor == valor){
            return p;
        }
    }
    return NULL;
}


/* Nome: CriarLista
 * Parametro: void 
 * Retorno: endereco do espaco de memoria reservado pelo malloc
 * Descricao: Funcao responsavel pela criacao da lista e inicializacao
 *            do campo prim
 */
Receita* CriarLista(){
    /*solicitando espaco para a lista*/
    Receita *nova = (Receita*)malloc(sizeof(Receita));
    
    /*Verificando se o espaco foi resevado*/
    if(nova == NULL){
        printf("Sem espaco\n");
        return NULL;
    }
    /*Preparando os dados iniciais da lista*/
    nova->prim = NULL;

    /*Retonando o espaco reservado*/
    return nova;
}


/* Nome: ExcluirLista
 * Parametro: lista - ponteiro que possui o endereco lista
 * Retorno: NULL para indicar que a lista foi excluida
 * Descricao: Funcao responsavel pela exclusao da lista
 */
Receita* ExcluirLista(Receita* receita){
    ReceitaNO *aux;

    /*Verificando se a lista foi criada*/
    if(receita == NULL){
        printf("A lista nao foi criada\n");
        return NULL;
    }

    /*Liberando o espaco que foi reservado para as receitas*/
    while(receita->prim != NULL){
        aux = receita->prim;
        receita->prim = receita->prim->prox;
        free(aux);
    }
    
    /*Liberando o espaco que foi reservado para a lista*/
    free(receita);
    
    return NULL;
}


/* Nome: InserirReceita
 * Parametros: lista - ponteiro que possui o endereco lista
 *             valor - receita que sera adicionado na lista
 * Retorno: 1 se a receita foi adicionada, 0 - caso contrario
 * Descricao: Funcao criada para inserir uma receita no final da lista
 */
int InserirReceita(Receita *receita, int valor){
    ReceitaNO *p; 

    /*Solicitando espaco para criar um no da lista*/
    ReceitaNO *nova = (ReceitaNO*) malloc(sizeof(ReceitaNO));
    
    /*Verificando se o espaco foi reservado corretamente*/
    if(nova == NULL){
        printf("Sem espaco\n");
        return 0;
    }

    /*Preparando as informacoes inciais da receita a ser inserido*/
    nova->valor = valor;
    nova->prox = NULL;

    /*Tratamento para inserir uma receita quando a lista esta vazia*/
    if(receita->prim == NULL){
        receita->prim = nova;
        return 1;
    }

    /*Procurando o ultimo ponteiro da lista para receber a nova receita*/
    for(p = receita->prim; p->prox != NULL; p = p->prox);

    /*Inserindo a receita na ultima posicao da lista*/
    p->prox = nova;

    return 1;
}


/* Nome: ImprimirReceitas
 * Parametro: lista - ponteiro que possui o endereco lista
 * Retorno: void
 * Descricao: Funcao criada para apresentar todas as receitas presentes na lista
 */
void ImprimirReceitas(Receita *receita){
    ReceitaNO *p;

    /*Verificando se a lista foi criada*/
    if(receita == NULL){
        printf("A lista nao foi criada\n");
        return ;
    }

    /*Verificando se a lista possui receitas*/
    if(receita->prim == NULL){
        printf("A lista esta vazia\n");
        return ;
    }

    /*Mostrando cada receita presente na lista*/
    for(p = receita->prim; p != NULL; p = p->prox){
        printf("%d ", p->valor);
    }
    printf("\n");
}


/* Nome: RemoverReceita
 * Parametro: lista - ponteiro que possui o endereco lista
 *            valor - receita que sera removido da lista
 * Retorno: 1 se a receita foi removido, 0 - caso contrario
 * Descricao: Funcao criada para remover uma receita da lista
 */
int RemoverReceita(Receita *receita, int valor){
    ReceitaNO *p, *aux;

    /*Verificando se a lista foi criada*/
    if(receita == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    /*Verificando se a lista foi criada*/
    if(receita->prim == NULL){
        printf("A lista esta vazia\n");
        return 0;
    }

    /*Removendo a receita caso ela esteja na primeira posicao da lista*/
    if( receita->prim->valor == valor){
        p = receita->prim;
        receita->prim = receita->prim->prox;
        free(p);
        return 1;
    }

    /*Passando por todas as receitas em busca da receita que sera removido*/
    for(p = receita->prim; p->prox->prox != NULL; p = p->prox){
        /*Verificando se e a receita que sera removido da lista*/
        if(p->prox->valor == valor){
            aux = p->prox;
            p->prox = p->prox->prox;
            free(aux);
            return 1;
        }
    }

    /*Tratamento da exclusao quando a receita se encontra na ultima posicao da lista*/
    if(p->prox->valor == valor){
        aux = p->prox;
        p->prox = NULL;
        free(aux);
        return 1;
    }
    
    return 0;
}
