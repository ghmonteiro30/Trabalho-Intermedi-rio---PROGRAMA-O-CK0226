#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "jogadores.h"
#include "categorias.h"
#include "sorteios.h"
#include "util.h"
#include "respostas.h"
#include "pontuacao.h"

int main (int narg, char *argv[]) {
	int n, *ordem = NULL, rodadas = 4, *pontos[rodadas], i, k;
	Jogador *j;
	char letra, categorias[rodadas][15];
	
	printf("*** JOGO AMEDONHA ***\n");
	
	iniciar_semente(); // Muda a semente de geracao de numeros para que a sequencia seja diferente toda vez que o programa for rodado.
	
	do {
		printf("Quantos jogadores? ");
		scanf("%d", &n);
		limpa_stdin();
	} while (n < 2 || n > 10);  //Pergunta quantos jogadores ate o numero de jogadores estiver no intervalo [2, 10]
	
	j = criarJogadores(n);
	lerNomes(j, n);
	
	for (i = 0; i < rodadas; i++) {
		// Sorteio da letra da rodada
		letra = sortear_letra();
		printf("\nA letra desta rodada eh: %c\n", letra);
		
		// Sorteio da categoria da rodada
		strcpy(categorias[i], obterNomeCategoria(sortearCategoria()));
		printf("A categoria desta rodada eh: Nome de %s\n", categorias[i]);
		
		// Sorteio da ordem de jogada da rodada
		printf("A ordem desta jogada sera: \n");
		if (ordem == NULL)
			ordem = (int*)malloc(sizeof(int) * n);
		sortear_ordem(ordem, n);
		for (k = 0; k < n; k++) {
			printf("  %d. %s\n", k + 1, j[ordem[k]].nome);
		}
		
		esperar_entrada("Tecle [Enter] para iniciar a rodada: ");
		limpa_tela();
		
		// Recebe as respostas de cada jogador
		Resposta respostas[n];
		for (k = 0; k < n; k++) {
			int idx = ordem[k]; // jogador atual
			printf("%s, voce deve entra um \"Nome de %s\" com letra \"%c\" em n segundos: ", j[idx].nome, categorias[i], letra);
			
			respostas[idx].valida = ler_resposta_com_tempo(respostas[idx].texto, 15, letra, 1);

			if(!respostas[idx].valida)
				strcpy(respostas[idx].texto,"(sem resposta)");
	
			limpa_tela();
		}
	
		// Exibe as jogadas realizadas por cada jogador
		printf("Jogadas realizadas:\n");
		for (k = 0; k < n; k++)
			printf("%-15s %s\n", j[ordem[k]].nome, respostas[k].texto); 
		
			// Calculo da Pontuacao
		calcular_pontuacao_rodada(respostas,n);

		//Acumula nos jogadores
		for (k=0;k<n;k++)
			j[k].pontos += respostas[k].pontos;

		// Se ainda nao for a ultima rodada, exibe a tabela de escores parcial
		if (i != rodadas - 1){
			printf("\nConcluida a rodada, esta eh a tabela de escores:\n");
			
			printar_tabela(j, n, i, categorias);
			
			esperar_entrada("Tecle [Enter] para iniciar a proxima rodada: ");
		} else
			esperar_entrada("Tecle [Enter] para exibir o resultado final: ");
		
		limpa_tela();
	}
	
	printf("\nRESULTADO FINAL:\n");
	
	printar_tabela(j, n, rodadas - 1, categorias);
	
	printf("O ganhador eh: \n");
	
	return EXIT_SUCCESS;
}