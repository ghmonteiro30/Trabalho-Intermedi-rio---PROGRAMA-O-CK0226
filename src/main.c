#include <stdlib.h>
#include <stdio.h>
#include "jogadores.h"
#include "sorteios.h"
#include "util.h"

int main (int narg, char *argv[]) {
	int n, i;
	Jogador *j;
	char letra;
	
	printf("*** JOGO AMEDONHA ***\n");
	
	iniciar_semente(); // Muda a semente de geracao de numeros para que a sequencia seja diferente toda vez que o programa for rodado.
	
	do {
		printf("Quantos jogadores? ");
		scanf("%d", &n);
		limpa_stdin();
	} while (n < 2 || n > 10);  //Pergunta quantos jogadores ate o numero de jogadores estiver no intervalo [2, 10]
	
	j = criarJogadores(n);
	lerNomes(j, n);
	
	for (i = 0; i < 4; i++) {
		printf("\nA letra desta rodada eh: %c\n", sortear_letra());
		printf("A categoria desta rodada eh: \n");
		printf("A ordem desta jogada sera: \n");
	}
	
	
	return EXIT_SUCCESS;
}
