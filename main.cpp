#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cabecalho.h"

void medirTempoOrdenacao(void (*funcOrdenacao)(int[], int), int arr[], int n, const char *nomeOrdenacao) {
    clock_t inicio, fim;
    double tempo_usado;

    inicio = clock();
    funcOrdenacao(arr, n);
    fim = clock();
    tempo_usado = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("%s: %f segundos\n", nomeOrdenacao, tempo_usado);
}

void medirTempoOrdenacaoComMerge(void (*funcOrdenacao)(int[], int, int), int arr[], int esq, int dir, const char *nomeOrdenacao) {
    clock_t inicio, fim;
    double tempo_usado;

    inicio = clock();
    funcOrdenacao(arr, esq, dir);
    fim = clock();
    tempo_usado = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("%s: %f segundos\n", nomeOrdenacao, tempo_usado);
}

int main() {
    int tamanhos[] = {1000, 10000, 100000, 200000, 500000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < numTamanhos; i++) {
        int n = tamanhos[i];
        int *arr = (int*) malloc(n * sizeof(int));
        int *arrCopia = (int*) malloc(n * sizeof(int));

        if (arr == NULL || arrCopia == NULL) {
            printf("Falha na alocacao de memória\n");
            return 1;
        }

        gerarVetorAleatorio(arr, n);
        copiarVetor(arr, arrCopia, n);

        printf("Ordenando %d elementos\n", n);

        medirTempoOrdenacao(insercao, arrCopia, n, "Ordenacao por Insercao");
        copiarVetor(arr, arrCopia, n);

        medirTempoOrdenacao(selecao, arrCopia, n, "Ordenacao por Selecao");
        copiarVetor(arr, arrCopia, n);

        medirTempoOrdenacaoComMerge(mergeSort, arrCopia, 0, n - 1, "Ordenacao por Merge");
        copiarVetor(arr, arrCopia, n);

        medirTempoOrdenacaoComMerge(quickSort, arrCopia, 0, n - 1, "Ordenacao por Quick");
        copiarVetor(arr, arrCopia, n);

        free(arr);
        free(arrCopia);

        printf("\n");
    }

    return 0;
}
