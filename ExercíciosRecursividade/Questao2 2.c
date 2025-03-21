/*
 ============================================================================
 Name        : Questao2.c
 Author      : Gabriel Fernandes
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decimalParaBinario(int numero);

int main() {
    setbuf(stdout, NULL);
    int numeroDecimal, numeroBinario;

    printf("\nDigite um número decimal: ");
    scanf("%d", &numeroDecimal);
    numeroBinario = decimalParaBinario(numeroDecimal);
    printf("O número binário equivalente de %d é %d\n", numeroDecimal, numeroBinario);

    return 0;
}

int decimalParaBinario(int numero) {
    if (numero == 0) {
        return 0;
    } else {
        return (numero % 2) + 10 * decimalParaBinario(numero / 2);
    }
}
