/*
 * funcoes_hash.c
 *
 *  Created on: 18 de set. de 2024
 *      Author: João Pedro Andrade e Gabriel Fernandes
 */

#include "biblioteca_hash.h"

void menu() {
	setbuf(stdout, NULL);

	char escolha;
	int indice = 0;
	int x = 0;
	lista *tabela[TAMANHO_TABELA] = {NULL};

	do {
		printf("\nA. Inserção de Elementos.\nB. Pesquisa de Elementos.\nC. Imprimir.\nD.Inserção em Massa.\nE.Finalizar.\nDigite sua opção: ");
		scanf(" %c", &escolha);
		escolha = toupper(escolha);

		switch(escolha) {
		case 'A':
			printf("\nDigite um número: ");
			scanf("%d", &indice);
			inserir_tabela(tabela, indice);
			break;
		case 'B':
			printf("\nDigite um número: ");
			scanf("%d", &indice);
			encontrar_codigo_tabela(tabela, indice);
			break;
		case 'C':
			imprimir_tabela(tabela, 0);
			break;
		case 'D':
			printf("\nDigite o número de inserções: ");
			scanf("%d", &x);
			printf("\nDigite o indice das inserções: ");
			scanf("%d", &indice);
			insercao_massa(tabela, x, indice);
			break;
		case 'E':
			printf("\nPrograma finalizado...");
			break;
		default:
			printf("Digite uma opção válida!\n");
			break;
		}
	} while (escolha != 'E');
}

int funcao_hash(int codigo) {
	return codigo % 11;
}

void inserir_lista (lista **listaSimples) {
	lista *novo = (lista*) malloc (sizeof(lista));
	novo->codigo = ALEATORIO();
	novo->proximo = *listaSimples;
	*listaSimples =  novo;
}

void inserir_tabela (lista *tabela[], int codigo) {
	int indice = funcao_hash(codigo);
	inserir_lista(&tabela[indice]);
}

void imprimir_lista(lista* listaSimples) {
	if (listaSimples != NULL) {
		printf("Endereço de memória do elemento: %p\nCódigo do elemento:%d\nEndereço do próximo elemento: %p\n", (void*)listaSimples, listaSimples->codigo, (void*)listaSimples->proximo);
		imprimir_lista(listaSimples->proximo);
	} else {
		return;
	}
}

void imprimir_tabela(lista *tabela[], int indice) {
	if (indice != TAMANHO_TABELA) {
		printf("Indice %d: ", indice);
		imprimir_lista(tabela[indice]);
		imprimir_tabela(tabela, indice + 1);
	} else {
		return;
	}
}

lista* buscar_tabela(lista *tabela[], int codigo) {
    int indice = funcao_hash(codigo);
    lista *atual = tabela[indice];
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void insercao_massa (lista *tabela[], int tamanho, int codigo) {
	for (int i = 0; i < tamanho; i++) {
		inserir_tabela(tabela, codigo);
	}
}

void encontrar_codigo_tabela(lista *tabela[], int valor) {
	for (int i = 0; i < TAMANHO_TABELA; i++) {
		lista *atual = tabela[i];
		while (atual != NULL) {
			if (atual->codigo == valor) {
				printf("Hash (índice da tabela): %d\nEndereço de memória do elemento: %p\nCódigo do elemento:%d\nEndereço do próximo elemento: %p\n",i, (void*)atual, atual->codigo, (void*)atual->proximo);
			}
			atual = atual->proximo;
		}
	}
}
