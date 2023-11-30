#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** gerarVetor(int qtd) {
    srand(time(NULL));

  
    int **vetor = (int **)malloc(qtd * sizeof(int *));
    for (int i = 0; i < qtd; i++) {
        vetor[i] = (int *)malloc(qtd * sizeof(int));
    }

    for (int i = 0; i < qtd; i++) {
        for (int j = 0; j < qtd; j++) {
            vetor[i][j] = rand() % 10;
        }
    }

    return vetor;
}

void paridade(int qtd, int (*vetor)[qtd]) {
    int somatorio = 0;
    
    for (int i = 0; i < qtd; i++) {
        for (int j = 0; j < qtd; j++) {
            if (i == j) {
                somatorio += vetor[i][j];
            }
        }
    }
    
    if (somatorio % 2 == 0) {
        puts("O valor do somatório da diagonal é par");
    } else {
        puts("O valor do somatório da diagonal é ímpar");
    }
}

int main() {
    int tamanho;
    puts("Qual o tamanho da matriz?");
    scanf("%d", &tamanho);

    int **matriz = gerarVetor(tamanho);

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    paridade(tamanho, matriz);

    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
