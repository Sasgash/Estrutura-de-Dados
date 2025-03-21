/*
 * biblioteca_hash.h
 *
 *  Created on: 18 de set. de 2024
 *      Author: João Pedro Andrade e Gabriel Fernandes
 */

#ifndef BIBLIOTECA_HASH_H_
#define BIBLIOTECA_HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAMANHO_TABELA 11

#define ALEATORIO(x) rand()

typedef struct listaSimples lista;
struct listaSimples {
	int codigo;
	lista *proximo;
};

int funcao_hash(int codigo);
void inserir_lista (lista **listaSimples);
void inserir_tabela (lista *tabela[], int codigo);
void imprimir_tabela(lista *tabela[], int indice);
lista* buscar_tabela(lista *tabela[], int codigo);
void insercao_massa (lista *tabela[], int tamanho, int codigo);
void encontrar_codigo_tabela(lista *tabela[], int valor);
void menu();
#endif /* BIBLIOTECA_HASH_H_ */
