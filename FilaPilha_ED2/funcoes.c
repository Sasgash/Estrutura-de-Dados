#include <stdio.h>
#include "funcoes.h"

// Inicializa a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

// Adiciona um item à pilha
void adicionarPilha(Pilha *pilha, Item item) {
    if (pilha->topo < MAX_SIZE - 1) {
        pilha->itens[++(pilha->topo)] = item;
    } else {
        printf("Pilha cheia!\n");
    }
}

// Remove um item da pilha
Item removerPilha(Pilha *pilha) {
    if (pilha->topo >= 0) {
        return pilha->itens[(pilha->topo)--];
    } else {
        printf("Pilha vazia!\n");
        Item item = {0}; // Retorna um item nulo
        return item;
    }
}

// Exibe a pilha
void exibirPilha(Pilha pilha) {
    if (pilha.topo >= 0) {
        printf("Pilha: ");
        for (int i = 0; i <= pilha.topo; i++) {
            printf("%d ", pilha.itens[i].codigo);
        }
        printf("\n");
    } else {
        printf("Pilha vazia!\n");
    }
}

// Inicializa a fila
void inicializarFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
}

// Adiciona um item à fila
void adicionarFila(Fila *fila, Item item) {
    if (fila->tras < MAX_SIZE - 1) {
        fila->itens[++(fila->tras)] = item;
    } else {
        printf("Fila cheia!\n");
    }
}

// Remove um item da fila
Item removerFila(Fila *fila) {
    if (fila->frente <= fila->tras) {
        return fila->itens[(fila->frente)++];
    } else {
        printf("Fila vazia!\n");
        Item item = {0}; // Retorna um item nulo
        return item;
    }
}

// Exibe a fila
void exibirFila(Fila fila) {
    if (fila.frente <= fila.tras) {
        printf("Fila: ");
        for (int i = fila.frente; i <= fila.tras; i++) {
            printf("%d ", fila.itens[i].codigo);
        }
        printf("\n");
    } else {
        printf("Fila vazia!\n");
    }
}

// Função que exibe o menu
void exibirMenu() {
    printf("Escolha uma opção:\n");
    printf("A. Adicionar à Pilha\n");
    printf("B. Remover da Pilha\n");
    printf("C. Exibir Pilha\n");
    printf("D. Adicionar à Fila\n");
    printf("E. Remover da Fila\n");
    printf("F. Exibir Fila\n");
    printf("G. Finalizar\n");
}
