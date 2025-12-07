#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void limpa_stdin(){
	int c;
	do {
		c = getchar();
	} while (c != '\n');
}

void printar_tabela(Jogador *j, int num_jogadores, int num_rodadas, int *pontos_rodada, char (*categorias)[15]){
	int i, l;
	
	printf("%-15s", "");
	for (i = 0; i <= num_rodadas; i++)
		printf("%-15s", categorias[i]);
	printf("Total\n"); 
	
	for (i = 0; i < num_jogadores; i++){
		printf("%-15s", j[i].nome);
		for (l = 0; l <= num_rodadas; l++)
			printf("%-15d", pontos_rodada[(l * num_jogadores) + i]);
		printf("%d\n", j[i].pontos);
	}
}

void limpa_tela(){
	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__MACH__)
		system("clear");
	#endif
}

void esperar_entrada(char *mensagem){
	char buf[1];
	
	printf("\n%s", mensagem);
	fgets(buf, 1, stdin);
	limpa_stdin();
}
