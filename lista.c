#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include <stdlib.h>  // Biblioteca padrão para funções de alocação de memória e outras utilidades

// Definição da estrutura ElementoLista
struct ElementoLista {
    int valor;                       // Valor armazenado no elemento da lista
    struct ElementoLista *prox;      // Ponteiro para o próximo elemento da lista
};

// Redefinição do tipo struct ElementoLista para Item
typedef struct ElementoLista Item;

// Declaração das funções
void imprime(Item *cabeca);           // Função para imprimir os elementos da lista
void insereFim(Item *cabeca, int valor);  // Função para inserir um novo elemento no final da lista
void libera(Item *cabeca);            // Função para liberar a memória alocada para a lista

// Função principal
int main(void) {
    Item cabeca;                      // Declaração da cabeça da lista
    cabeca.prox = NULL;               // Inicializa a lista com o ponteiro NULL

    printf("Tamanho do item: %d\n", (int)sizeof(Item));  // Imprime o tamanho da estrutura Item

    printf("\nInserindo novos itens na lista...\n");
    insereFim(&cabeca, 15);           // Insere o valor 15 na lista
    insereFim(&cabeca, 125);          // Insere o valor 125 na lista
    insereFim(&cabeca, 155);          // Insere o valor 155 na lista
    insereFim(&cabeca, 65);
    insereFim(&cabeca, 16);           // Insere o valor 15 na lista
    insereFim(&cabeca, 48);          // Insere o valor 125 na lista
    insereFim(&cabeca, 23);          // Insere o valor 155 na lista
    insereFim(&cabeca, 89);
    printf("Tamanho do item: %d\n", (int)sizeof(Item));

    system("PAUSE");                  // Pausa a execução para visualização no Windows

    imprime(&cabeca);                 // Imprime todos os elementos da lista

    system("PAUSE");                  // Pausa a execução para visualização no Windows

    libera(&cabeca);                  // Libera a memória alocada para a lista
    return 0;                         // Retorna 0 indicando execução bem-sucedida
}

// Função para inserir um novo elemento no final da lista
void insereFim(Item *cabeca, int valor) {
    Item *novo = (Item*)malloc(sizeof(Item));  // Aloca memória para um novo elemento
    if (novo == NULL) {                        // Verifica se a alocação foi bem-sucedida
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(1);                               // Encerra o programa em caso de falha
    }

    novo->prox = NULL;                         // Inicializa o ponteiro do novo elemento
    novo->valor = valor;                       // Atribui o valor ao novo elemento

    printf("Item valor %3d alocando no endereco: %p\n", valor, (void*)novo);  // Imprime o endereço do novo elemento

    Item *atual = cabeca;                      // Inicia a partir da cabeça da lista
    while (atual->prox != NULL) {              // Percorre a lista até o final
        atual = atual->prox;
    }

    atual->prox = novo;                        // Adiciona o novo elemento ao final da lista
}

// Função para imprimir todos os elementos da lista
void imprime(Item *cabeca) {
    Item *atual = cabeca->prox;                // Inicia a partir do primeiro elemento após a cabeça
    int i = 0;                                 // Contador de elementos

    printf("Imprimindo itens da lista...\n");
    while (atual != NULL) {                    // Percorre a lista até o final
        printf("Valor do item: %3d\n", atual->valor);  // Imprime o valor do elemento atual
        i++;
        atual = atual->prox;                   // Avança para o próximo elemento
    }

    printf("Total de itens da lista: %d\n", i);  // Imprime o total de elementos na lista
}

// Função para liberar a memória alocada para a lista
void libera(Item *cabeca) {
    Item *atual = cabeca->prox;                // Inicia a partir do primeiro elemento após a cabeça
    Item *liberado;                            // Ponteiro temporário para o elemento a ser liberado

    while (atual != NULL) {                    // Percorre a lista até o final
        liberado = atual;                      // Armazena o ponteiro para o elemento atual
        atual = atual->prox;                   // Avança para o próximo elemento
        printf("Liberando o item valor %3d na posicao %p\n", liberado->valor, (void*)liberado);  // Imprime mensagem de liberação
        free(liberado);                        // Libera a memória do elemento atual
    }
}
