#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* gerarVetor(int qtd) {
    int *vetor = (int*)malloc(qtd * sizeof(int));

    if (vetor == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < qtd; i++) {
        vetor[i] = rand() % 10;
    }

    return vetor;
}

float calcularMedia(int vetor[], int qtd){
    int somatorio = 0;

    for (int i = 0; i < qtd; i++){
       somatorio += vetor[i];
    }
    float media = (float)somatorio/qtd;
    return media;
}

float calcularMediana(int vetor[], int qtd){
    float mediana = 0;

    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    if(qtd % 2 == 0){
        mediana = (vetor[(qtd/2 - 1)] + vetor[(qtd)/2])/2;
        
    }else{
        mediana = vetor[(qtd)/2];
    }

    return mediana;
}

void calcularModa(int vetor[], int qtd){
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    int frequenciaAtual = 1;
    int maxFrequencia = 1;
    int moda = vetor[0];

    for (int i = 1; i < qtd; i++) {
        if (vetor[i] == vetor[i - 1]) {
            frequenciaAtual++;
        } else {
            frequenciaAtual = 1;
        }

        if (frequenciaAtual > maxFrequencia) {
            maxFrequencia = frequenciaAtual;
            moda = vetor[i];
        }
    }

    printf("A moda é: %d\n", moda);
    
}
int main() {
    srand(time(NULL));
    int qtd;

    puts("Qual o tamanho do array?");
    scanf("%d", &qtd);

    int *vetor = gerarVetor(qtd);

    // MEDIA vvvvvvvvvvvvvvvvvv
    puts("Array criado: ");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", vetor[i]);
    }
    puts("\n");
    float media = calcularMedia(vetor, qtd);
    printf("A média do array é igual à: %.2f", media);
    // MEDIA ^^^^^^^^^^^^^^^^^

    //MEDIANA vvvvvvvvvvvvvvvv
    puts("\n");
    float mediana = calcularMediana(vetor, qtd);
    printf("A mediana do array é igual à: %.2f", mediana);
    //MEDIANA^^^^^^^^^^^^^^^^^
    
    puts("\n");
    calcularModa(vetor,qtd);


    // Liberando memória 
    free(vetor);

    return 0;
}
