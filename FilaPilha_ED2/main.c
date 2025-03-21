#include <stdio.h>
#include "funcoes.h"

int main() {
    Pilha pilha;
    Fila fila;
    char opcao;
    Item item;
    int codigo = 1;

    inicializarPilha(&pilha);
    inicializarFila(&fila);

    do {
        exibirMenu();
        printf("Digite sua opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'A': // Adicionar à Pilha
                item.codigo = codigo++;
                adicionarPilha(&pilha, item);
                break;
            case 'B': // Remover da Pilha
                item = removerPilha(&pilha);
                if (item.codigo != 0) {
                    printf("Item removido da pilha: %d\n", item.codigo);
                }
                break;
            case 'C': // Exibir Pilha
                exibirPilha(pilha);
                break;
            case 'D': // Adicionar à Fila
                item.codigo = codigo++;
                adicionarFila(&fila, item);
                break;
            case 'E': // Remover da Fila
                item = removerFila(&fila);
                if (item.codigo != 0) {
                    printf("Item removido da fila: %d\n", item.codigo);
                }
                break;
            case 'F': // Exibir Fila
                exibirFila(fila);
                break;
            case 'G': // Finalizar
                printf("Finalizando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 'G');

    return 0;
}
