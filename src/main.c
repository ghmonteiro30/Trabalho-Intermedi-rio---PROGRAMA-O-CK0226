/* Trabalho Intermediário – Jogo Amedonha - Disciplina Programação (CK0226) 
   Autores: ANTONIO CARDOSO DO NASCIMENTO NETO - 508199
			FRANCISCO DAVID VAZ DE SOUSA - 554152
			GABRIEL HENRIQUE MONTEIRO DE MORAIS - 548113

   Data: Dezembro de 2025
   Descrição: O jogo Amedonha começa solicitando o número de jogadores e seus respectivos nomes.
   A cada rodada, uma categoria e uma letra são sorteadas, assim como a ordem de resposta, que
   muda a cada nova rodada. Os jogadores devem então fornecer respostas que atendam à categoria
   e iniciem com a letra sorteada, dentro do tempo disponível. Ao final de cada rodada, são atribuídas
   pontuações conforme as respostas, e ao término do jogo, vence o jogador com a maior pontuação total.
   Em caso de empate, o vencedor é definido pelo menor tempo acumulado de respostas.

   CONTRIBUIÇÕES DOS AUTORES:
	- ANTONIO CARDOSO DO NASCIMENTO NETO: 

	- FRANCISCO DAVID VAZ DE SOUSA: 

	- GABRIEL HENRIQUE MONTEIRO DE MORAIS: Estruturação do projeto (src/include), Implementação dos módulos jogadores.c/h,
	e testes no ambiente Linux (WSL).
*/


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
	int n, *ordem = NULL, *ordem_ant = NULL, rodadas = 4, segundos, *pontos_rodada = NULL, i, k, idx;
	Jogador *j;
	Resposta *respostas = NULL;
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
		if (ordem == NULL) {
			ordem = (int*)malloc(sizeof(int) * n);
			ordem_ant = (int*)malloc(sizeof(int) * n);
			sortear_ordem(ordem, n);
		} else {
			for (k = 0; k < n; k++)
				ordem_ant[k] = ordem[k];
			do {
				sortear_ordem(ordem, n);
			} while (!ordem_valida(ordem, ordem_ant, n));
		}
		for (k = 0; k < n; k++) {
			printf("  %d. %s\n", k + 1, j[ordem[k]].nome);
		}
		
		esperar_entrada("Tecle [Enter] para iniciar a rodada: ");
		limpa_tela();
		
		// Recebe as respostas de cada jogador
		if (respostas == NULL)
			respostas = (Resposta*)malloc(sizeof(Resposta) * n);
		for (k = 0; k < n; k++) {
			idx = ordem[k]; // jogador atual
			segundos = 8 + (2 * n) - (2 * k);
			printf("%s, voce deve entra um \"Nome de %s\" com letra \"%c\" em %d segundos:\n", j[idx].nome, categorias[i], letra, segundos);
			
			respostas[idx].valida = ler_resposta_com_tempo(respostas[idx].texto, &respostas[idx].tempo, segundos, letra, 1);

			if(!respostas[idx].valida) {
				strcpy(respostas[idx].texto,"(sem resposta)");
				respostas[idx].tempo = segundos;
			}
	
			limpa_tela();
		}
	
		// Exibe as jogadas realizadas por cada jogador
		printf("Jogadas realizadas:\n");
		for (k = 0; k < n; k++)
			printf("%-15s %s\n", j[ordem[k]].nome, respostas[k].texto); 
		
			// Calculo da Pontuacao
		calcular_pontuacao_rodada(respostas,n);

		// Matriz para armazenar a pontuação de cada rodada
		if (pontos_rodada == NULL)
			pontos_rodada = (int*)malloc(sizeof(int) * n * rodadas);
		for (k = 0; k < n; k++)
			pontos_rodada[(i * n) + ordem[k]] = respostas[k].pontos;

		//Acumula nos jogadores os pontos e tempo levado
		for (k=0;k<n;k++) {
			j[ordem[k]].pontos += respostas[k].pontos;
			j[ordem[k]].tempo_total += respostas[k].tempo;
		}

		// Se ainda nao for a ultima rodada, exibe a tabela de escores parcial
		if (i != rodadas - 1){
			printf("\nConcluida a rodada, esta eh a tabela de escores:\n");
			printar_tabela(j, n, i, pontos_rodada, categorias);
			esperar_entrada("Tecle [Enter] para iniciar a proxima rodada: ");
		} else
			esperar_entrada("Tecle [Enter] para exibir o resultado final: ");
		
		limpa_tela();
	}
	
	
	// Resultado final
	printf("\nRESULTADO FINAL:\n");
	printar_tabela(j, n, rodadas - 1, pontos_rodada, categorias);
	printf("\nO ganhador eh: %s\n", j[idx_ganhador(j, n)].nome);
	
	return EXIT_SUCCESS;
}
