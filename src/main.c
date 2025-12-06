#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "jogadores.h"
#include "categorias.h"
#include "sorteios.h"
#include "util.h"

int main (int narg, char *argv[]) {
	int n, *ordem, i, k;
	Jogador *j;
	char letra, categoria[15], buffer[100];
	
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
		// Sorteio da letra da rodada
		letra = sortear_letra();
		printf("\nA letra desta rodada eh: %c\n", letra);
		
		// Sorteio da categoria da rodada
		strcpy(categoria, obterNomeCategoria(sortearCategoria()));
		printf("A categoria desta rodada eh: %s\n", categoria);
		
		// Sorteio da ordem de jogada da rodada
		printf("A ordem desta jogada sera: \n");
		ordem = sortear_ordem(n);
		for (k = 0; k < n; k++) {
			printf("  %d. %s\n", k + 1, j[ordem[k]].nome);
		}
		
		esperar_entrada("Tecle [Enter] para iniciar a rodada: ");
		limpa_tela();
		
		// Recebe as respostas de cada jogador
		for (k = 0; k < n; k++) {
			printf("%s, voce deve entra um \"%s\" com letra \"%c\" em n segundos: ", j[ordem[k]].nome, categoria, letra);
			fgets(buffer, 100, stdin);
			limpa_tela();
		}
		
		// Exibe as jogadas realizadas por cada jogador
		printf("Jogadas realizadas:\n");
		for (k = 0; k < n; k++)
			printf("%s:    %s\n", j[ordem[k]].nome, "resposta"); 
		
		// Se ainda nao for a ultima rodada, exibe a tabela de escores parcial
		if (i != 3){
			printf("\nConcluida a rodada, esta eh a tabela de escores:\n");
			
			printf("--- aqui tabela de escores ---\n");
			
			esperar_entrada("Tecle [Enter] para iniciar a proxima rodada: ");
		} else
			esperar_entrada("Tecle [Enter] para exibir o resultado final: ");
		
		limpa_tela();
	}
	
	printf("\nRESULTADO FINAL:\n");
	
	printf("--- aqui resultado final ---");
	
	printf("O ganhador eh: \n");
	
	return EXIT_SUCCESS;
}
