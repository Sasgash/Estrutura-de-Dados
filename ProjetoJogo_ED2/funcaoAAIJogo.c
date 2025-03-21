/*
 * funcaoAAIJogo.c
 *
 *  Created on: 14 de out. de 2024
 *      Author: danie
 */

#include "BibliotecaAAIJogo.h"

void menuPrincipal() {
	char escolha;
	personagem *players = NULL;
	personagem *NPCs = NULL;
	int moedas;

	do {
		do {
			printf("\nDigite uma das Opções"
					"\nA - Novo Game:\n"
					"\nB - Sair:\n");
			scanf(" %c", &escolha);

			escolha = toupper(escolha);

			if (escolha != 'A' && escolha != 'B') {
				printf("\nDigite uma opcao valida\n");
			}
		} while (escolha != 'A' && escolha != 'B');

		switch (escolha) {
		case 'A':
			// Libere a memória dos jogadores e NPCs antes de iniciar um novo jogo
			free(players);
			free(NPCs);

			moedas = 10;
			players = NULL;  // Redefine players para NULL
			NPCs = NULL;     // Redefine NPCs para NULL

			menuPersonagens(&players);
			printf("\nMUITO BEM, seus personagens são:");
			impressao(players);
			sorteandoNpc(&NPCs);
			printf("\n\nSeu adversario será:");
			impressao(NPCs);

			partida(&NPCs, &players, &moedas);
		}

	} while (escolha != 'B');

	printf("OBRIGADO POR JOGAR CONOSCO, VOLTE SEMPRE !!!!");
}
void partida(personagem **NPCs, personagem **player, int *moedas) {
	int escolha;
	int final = 0;
	int aleatorio;
	char identificandoJogada = 'S';

	do {
		do {
			do {
				printf(
						"\n\nMuito bem valos lá!!"
								"\nQual comando você vai querer usar para seu Dragão ?"
								"\n1- Dracarys!!"
								"\n2- Dracarys + chance  de CRITICO(gaste duas moedas!!)");
				printf("\nVocê ainda tem %i moedas", *moedas);
				scanf(" %i", &escolha);

				if (escolha != 1 && escolha != 2) {
					printf("\nDigite uma opcao valida\n");
				}
			} while (escolha != 1 && escolha != 2);

			//Jogador atacando
			menuAtaque(player, NPCs, escolha, &final, moedas, 'P',
					&identificandoJogada);

			identificandoJogada = toupper(identificandoJogada);



		} while (identificandoJogada == 'N'); //Testando se foi possivel jogar, devida a quantidade de moedas

		//Testando se a batalha acabou
		if (final == 1) {
			return;
		}

		//Oponente atacando
		aleatorio = (rand() % 2) + 1;
		printf("\n\nOPONENTE:\n ");
		menuAtaque(NPCs, player, aleatorio, &final, moedas, 'N',
				&identificandoJogada);

	} while (final != 1);

	printf("\n\n\n---- QUE BELA PARTIDA------!!!\n");
	printf("\nVVAMOS JOGAR OUTRA, FOI MUITO BOM TER VOCÊ AQUI :)\n");

}

void menuAtaque(personagem **playerAta, personagem **playerDef, int escolha,
		int *final, int *moedas, char indentificandoNPC,
		char *identificandoJogada) {

	//Escolhendo menu de ataque;
	switch (escolha) {
	case 1:     //ataque normal
		ataque(playerAta, playerDef, escolha, final, 4);
		*identificandoJogada = 'S';
		break;
	case 2:     //ataque com chance maior de critico
		if (indentificandoNPC == 'N') {
			ataque(playerAta, playerDef, escolha, final, 2);
		} else {
			if (*moedas >= 2) {
				*moedas -= 2;
				ataque(playerAta, playerDef, escolha, final, 2);
				*identificandoJogada = 'S';
			} else {
				printf("\nATENÇÃO: Você não tem moedas suficientes!!");
				*identificandoJogada = 'N';
				return;
			}
		}
		break;
	}
}

void ataque(personagem **playerAta, personagem **playerDef, int escolha,
		int *final, int chanceCritico) {

	int aleatorio;
	int poderAtaque;
	personagem *duplaAtaque;

	aleatorio = (rand() % chanceCritico) + 1;
	ataqueCritico(aleatorio, &poderAtaque);

	(*playerDef)->vida -= poderAtaque;

	if (!((*playerDef)->vida <= 0)) {
		sleep(2);     //2 segundos para imprimir o proximo

		printf("\n%s: \"%s DRACAARYS!!!!!\" ", (*playerAta)->personagem,
				(*playerAta)->dragon);
		sleep(2);

		if (poderAtaque == 20) {

			printf("\n!!!!! UAAUU %s LANÇOU UM BELO DRACARYS CRITICO 2!!!!\n",
					(*playerAta)->dragon);
		}

		sleep(2);

		printf("\nQue golpe espetacular UAU!!!!"
				"\n A vida de %s é de %i\n", (*playerDef)->dragon,
				(*playerDef)->vida);
		sleep(2);
	} else {
		printf(
				"\n\nAUUU %s E SEU MONTADOR %s ACABARAM DE MATAR %s E SEU MONTADIR %s!!!!!\n\n",
				(*playerAta)->dragon, (*playerAta)->personagem,
				(*playerDef)->dragon, (*playerDef)->personagem);
		if ((*playerDef)->proximo != NULL) {
			mudandoPersonagem(playerDef);

			printf("\nAGORA VAMOS VER SUA DUPLA ENTRAR EM COMBATE: DRAGÃO %s E SEU MONTADOR %s\n",
					(*playerDef)->dragon, (*playerDef)->personagem);
		} else {
			printf("\n\nE ASSIM TEMOS O FIM DA DANÇA DOS DRAGÕES,");
			sleep(2);
			printf("\nCOM DRAGÃO %s E SEU MONTADOR %s,", (*playerAta)->dragon,
					(*playerAta)->personagem);
			sleep(2);
			printf("\n JUNTAMENTE COM");
			sleep(2);

			//Testando quantos personagens tem na fila para conseguir imprimir o primeiro
			if ((*playerAta)->proximo == NULL) {
				duplaAtaque = (*playerAta)->inicio;
			} else {
				duplaAtaque = (*playerAta)->proximo;
			}

			printf("\nDRAGÃO %s E SEU MONTADOR %s ", duplaAtaque->dragon,
					duplaAtaque->personagem);
			sleep(2);
			printf("\n------------!!!!! SENDOS OS VENCEDORES  !!! ----------");
			*final = 1;
		}

	}

}
void ataqueCritico(int aleatorio, int *poderAtaque) {
	if (aleatorio == 2) {
		*poderAtaque = 20;
	} else {
		*poderAtaque = 10;
	}
}

personagem* criandoPlayer() {
	personagem *player = (personagem*) malloc(sizeof(personagem));
	player->proximo = NULL;
	return player;
}

void mudandoPersonagem(personagem **player) {
	personagem *temp = *player;
	personagem *proximo = temp->proximo;
	*player = proximo;
}

void menuPersonagens(personagem **players) {
	int escolha;

	do {
		//Escolha do personagem e do dragon
		printf(
				"\nOla bem vindo ao House Of The Dragons!!\n"
						"\nVamos escolher seus dragons juntamente com seus personagens!\n"
						"\n1 - Dragão Caraxes, de Daemon Targaryen e Dragão Syrax, de Rhaenyra Targaryen "
						"\n2 - Dragão Vhagar, de Aemond Targaryen e Dragão Sunfyre, de  Aegon Targaryen II"
						"\n3 - Dragão Vermithor, de Jaehaerys I Targaryen e Dragão Meleys, de Rhaenys Velaryo"
						"\n4 - Dragão Balerion, de Aegon I e Dragão Dreamfyre, de Rhaena Targaryen I\n");
		scanf(" %i", &escolha);

		if (escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4) {
			printf("\nDigite uma opcao valida\n");
		}

	} while (escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4);

	escolhendoPersonagens(escolha, players);

}

void escolhendoPersonagens(int escolha, personagem **players) {

	//criando personagens
	personagem *npc01 = criandoPlayer();
	personagem *npc02 = criandoPlayer();

	//Testando se foi criado
	if (npc01 == NULL || npc02 == NULL) {
		printf("\nErro ao iniciar o jogo, tente novamente!\n");
		return;
	}

	switch (escolha) {
	case 1:

		strcpy(npc01->dragon, "Caraxes");
		strcpy(npc01->personagem, "Daemon Targaryen");
		strcpy(npc02->dragon, "Syrax");
		strcpy(npc02->personagem, "Rhaenyra Targaryen");

		break;
	case 2:
		strcpy(npc01->dragon, "Vhagar");
		strcpy(npc01->personagem, "Aemond Targaryen");
		strcpy(npc02->dragon, "Sunfyre");
		strcpy(npc02->personagem, "Aegon Targaryen II ");
		break;
	case 3:
		strcpy(npc01->dragon, "Vermithor");
		strcpy(npc01->personagem, "Jaehaerys I Targaryen");
		strcpy(npc02->dragon, "Meleys");
		strcpy(npc02->personagem, "Rhaenys Velaryo");
		break;
	case 4:
		strcpy(npc01->dragon, "Balerion");
		strcpy(npc01->personagem, "Aegon I");
		strcpy(npc02->dragon, "Dreamfyre");
		strcpy(npc02->personagem, "Rhaena Targaryen I");
		break;
	}
	//Iniciando vida dos personagens
	npc01->vida = 100;
	npc02->vida = 100;

	// Conectando NPCs
	npc01->proximo = npc02;
	npc02->inicio = npc01;

	// Testando se está vazio;
	if (*players == NULL) {
		*players = npc01;

	}
}

void sorteandoNpc(personagem **NPCs) {
	int aleatorio = (rand() % 4) + 1;

	escolhendoPersonagens(aleatorio, NPCs);
}

void impressao(personagem *players) {
	personagem *temp = players;
	while (temp != NULL) {
		printf("\nDragão: %s e seu montador %s", temp->dragon,
				temp->personagem);
		temp = temp->proximo;
	}
}
