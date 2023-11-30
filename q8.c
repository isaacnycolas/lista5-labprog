#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** gerarMatriz(int tamanho) {
    int **matriz = (int**)malloc(tamanho * sizeof(int*));

    if (matriz == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tamanho; i++) {
        matriz[i] = (int*)malloc(tamanho * sizeof(int));

        if (matriz[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }


    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = rand() % 10;
        }
    }

    return matriz;
}

void imprimirMatriz(int **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void liberarMatriz(int **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void transformarMatriz(int **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int tamanho;
    puts("QUal o tamanho da matriz?");
    scanf("%d", &tamanho);
    int **matriz = gerarMatriz(tamanho);

    printf("Matriz original:\n");
    imprimirMatriz(matriz, tamanho);

    transformarMatriz(matriz, tamanho);

    printf("\nMatriz transformada:\n");
    imprimirMatriz(matriz, tamanho);

    liberarMatriz(matriz, tamanho);

    return 0;
}
