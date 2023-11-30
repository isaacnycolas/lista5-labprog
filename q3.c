#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* gerarVetor(int qtd) {
    srand(time(NULL));
    int *vetor = (int*)malloc(qtd * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < qtd; i++) {
        vetor[i] = rand() % 100;
    }

    return vetor;
}

int encontrarMenorElemento(int vetor[], int qtd, int **enderecoMenor) {
    if (qtd <= 0) {
        printf("Erro: vetor vazio.\n");
        return -1;
    }

    int menor = vetor[0];
    *enderecoMenor = &vetor[0];

    for (int i = 1; i < qtd; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
            *enderecoMenor = &vetor[i];
        }
    }

    return menor;
}

int encontrarMaiorElemento(int vetor[], int qtd, int **enderecoMaior) {
    if (qtd <= 0) {
        printf("Erro: vetor vazio.\n");
        return -1;
    }

    int maior = vetor[0];
    *enderecoMaior = &vetor[0];

    for (int i = 1; i < qtd; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            *enderecoMaior = &vetor[i];
        }
    }

    return maior;
}

void retornarVetor(int **enderecoMenor, int menor, int maior, int **enderecoMaior){
    int vetorEnderecos[2];
    vetorEnderecos[0] = *enderecoMaior;
    vetorEnderecos[1] = *enderecoMenor;

    printf("Endereço 1: %p\n", (void *)vetorEnderecos[0]);
    printf("Endereço 2: %p\n", (void *)vetorEnderecos[1]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamanho do vetor>\n", argv[0]);
        return 1;
    }

    int numero = atoi(argv[1]);
    int *vetor = gerarVetor(numero);

    int *enderecoMenor;
    int menor = encontrarMenorElemento(vetor, numero, &enderecoMenor);

    int *enderecoMaior;
    int maior = encontrarMaiorElemento(vetor, numero, &enderecoMaior);

    printf("Vetor gerado:\n");
    for (int i = 0; i < numero; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Menor elemento: %d\n", menor);
    printf("Endereço do menor elemento: %p\n", (void*)enderecoMenor);

    printf("Maior elemento: %d\n", maior);
    printf("Endereço do maior elemento: %p\n", (void*)enderecoMaior);

    retornarVetor(&enderecoMenor, menor, maior, &enderecoMaior);
    free(vetor);

    return 0;
}