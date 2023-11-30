#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float* gerarVetor(int qtd) {
    srand(time(NULL));
    float* vetor = (float*)calloc(qtd, sizeof(float));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < qtd; i++) {
        vetor[i] = rand() % 100;
    }

    return vetor;
}

float somarVetor(float* vetor, int qtd){
    float somatorio = 0;
    for(int i = 0; i < qtd; i++){
        somatorio += vetor[i];
    }
    return somatorio;
}

int main(int argc, char argv[]){
    int tamanho = atoi(argv[1]);
    float* vetor = gerarVetor(tamanho);
    for(int i = 0; i < tamanho; i++){
        printf("%.2f", vetor[i]);
    }
    float somatorio = somarVetor(vetor, tamanho);
    printf("O somatório do vetor gerado é: %.2f", somatorio);

    return 0;
}