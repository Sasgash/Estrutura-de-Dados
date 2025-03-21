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

int verificar_palindromo(char* str, int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    } else {
        if (str[inicio] != str[fim]) {
            return 0;
        }
        return verificar_palindromo(str, inicio + 1, fim - 1);
    }
}

void checar_palindromo(char *str) {
    int resultado;
    int comprimento = strlen(str) - 1;

    resultado = verificar_palindromo(str, 0, comprimento);

    if (resultado == 1) {
        printf("É um palíndromo\n");
    } else {
        printf("Não é um palíndromo\n");
    }
}

int main(void) {
    setbuf(stdout, NULL);
    char texto[30] = "natan"; 
    checar_palindromo(texto); 
    return 0;
}