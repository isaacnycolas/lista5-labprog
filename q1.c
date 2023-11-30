#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <numero inteiro> <numero inteiro> <operacao (1 para soma, 2 para multiplicacao)>\n", argv[0]);
        return 1;
    }

    int numero1 = atoi(argv[1]);
    int numero2 = atoi(argv[2]);
    int op = atoi(argv[3]);

    if (op == 1) {
        int soma = numero1 + numero2;
        printf("A soma de %d e %d é igual a: %d\n", numero1, numero2, soma);
    } else if (op == 2) {
        int multiplicacao = numero1 * numero2;
        printf("A multiplicação de %d e %d é igual a: %d\n", numero1, numero2, multiplicacao);
    } else {
        printf("Operação inválida. Use 1 para soma ou 2 para multiplicação.\n");
        return 1;
    }

    return 0;
}