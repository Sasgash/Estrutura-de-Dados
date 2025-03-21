/*
 * BibliotecaAAIJogo.h
 *
 *  Created on: 14 de out. de 2024
 *      Author: danie
 */

#ifndef BIBLIOTECAAAIJOGO_H_
#define BIBLIOTECAAAIJOGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

typedef struct dadosPersonagem personagem;
struct dadosPersonagem {
	char personagem[50];
	char dragon[50];
	int vida;

	personagem *proximo;
	personagem *inicio;

};

void menuPrincipal();
personagem* criandoPlayer();
void menuPersonagens();
void escolhendoPersonagens(int escolha, personagem **players);
void sorteandoNpc(personagem **NPCs);
void partida(personagem **NPCs, personagem **player, int *moedas);
void ataque(personagem **playerAta, personagem **playerDef, int escolha,
		int *final, int chanceCritico);
void menuAtaque(personagem **playerAta, personagem **playerDef, int escolha,
		int *final, int *moedas, char indentificandoNPC, char *identificandoJogada );
void ataqueCritico(int aleatorio, int *poderAtaque);
void mudandoPersonagem(personagem **player);


void impressao(personagem *players);

#endif /* BIBLIOTECAAAIJOGO_H_ */
