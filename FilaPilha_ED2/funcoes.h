#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_SIZE 100

// Estrutura para um item
typedef struct {
    int codigo;
} Item;

// Estrutura para a pilha
typedef struct {
    Item itens[MAX_SIZE];
    int topo;
} Pilha;

// Estrutura para a fila
typedef struct {
    Item itens[MAX_SIZE];
    int frente, tras;
} Fila;

// Funções para Pilha
void inicializarPilha(Pilha *pilha);
void adicionarPilha(Pilha *pilha, Item item);
Item removerPilha(Pilha *pilha);
void exibirPilha(Pilha pilha);

// Funções para Fila
void inicializarFila(Fila *fila);
void adicionarFila(Fila *fila, Item item);
Item removerFila(Fila *fila);
void exibirFila(Fila fila);

// Função para exibir o menu
void exibirMenu();

#endif
