#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


double* gerarVetor(int qtd) {
    double *vetor = (double*)malloc(qtd * sizeof(double));

    if (vetor == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < qtd; i++) {
        vetor[i] = (double)rand() / RAND_MAX * 10.0;
    }

    return vetor;
}

double calcularRMSE(int tamanho, double A[], double B[]) {
    double somaQuadrados = 0;

    for (int i = 0; i < tamanho; i++) {
        double diferenca = A[i] - B[i];
        somaQuadrados += diferenca * diferenca;
    }

    double mse = somaQuadrados / tamanho;
    double rmse = sqrt(mse);

    return rmse;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <dimensao>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int qtd = atoi(argv[1]);

    double *vetorA = gerarVetor(qtd);
    double *vetorB = gerarVetor(qtd);

    
    double rmse = calcularRMSE(qtd, vetorA, vetorB);

    
    printf("Dimensao dos vetores: %d\n", qtd);
    printf("Vetor A: ");
    for (int i = 0; i < qtd; i++) {
        printf("%.2f ", vetorA[i]);
    }
    printf("\n");

    printf("Vetor B: ");
    for (int i = 0; i < qtd; i++) {
        printf("%.2f ", vetorB[i]);
    }
    printf("\n");

    printf("O RMSE entre os vetores A e B é: %.4f\n", rmse);

    
    free(vetorA);
    free(vetorB);

    return 0;
}
