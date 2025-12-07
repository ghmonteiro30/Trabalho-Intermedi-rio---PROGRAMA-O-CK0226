#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "respostas.h"
// utilizamos sys/select e sys/time para criar a entrada com limite de tempo

// Faz a leitura com tempo limite usando select()
int ler_resposta_com_tempo(char *buffer_destino, double *tempo_levado, int max_segundos,char letra_sorteada, int eh_nome_pessoa){
	struct timeval inicio, atual, prazo;
	fd_set descritores;
	int segundos_restantes = max_segundos;
	//Marca o tempo inicial
	gettimeofday(&inicio, NULL);

	while (segundos_restantes > 0) {
		//configuracao para monitorar o teclado
		FD_ZERO(&descritores);
		FD_SET(STDIN_FILENO, &descritores);

		prazo.tv_sec = segundos_restantes;
		prazo.tv_usec = 0;
		//funcao para aguardar a entrada ou o tempo acabar
		int resultado = select(STDIN_FILENO + 1, &descritores, NULL, NULL, &prazo);

		if (resultado == 0)
			return 0; // o tempo acabou e nao houve resposta

		if (resultado > 0) {
			//o usuario digitou algo antes de acabar o tempo
			char buffer_temp[100]; // buffer grande para identificar se o usuario digitou caracteres demais

			if (fgets(buffer_temp, sizeof(buffer_temp), stdin) != NULL) {

				buffer_temp[strcspn(buffer_temp, "\n")] = 0;

				// Validacao do tamanho máximo de 30
				if (strlen(buffer_temp) > TAM_RESPOSTA) {
					printf("Resposta muito longa! Máximo %d caracteres. Tente novamente: ",
					   TAM_RESPOSTA);

					gettimeofday(&atual, NULL);
					segundos_restantes =
					max_segundos - (atual.tv_sec - inicio.tv_sec);

					continue;
				}

				// Nome de pessoa → só uma palavra
				if (eh_nome_pessoa) {
					char *espaco = strchr(buffer_temp, ' ');
					if (espaco)
					*espaco = '\0';
				}

				// Validacao da letra inicial
				if (toupper(buffer_temp[0]) != toupper(letra_sorteada)) {
					printf("A resposta deve começar com a letra '%c'. Tente novamente: ",
					   letra_sorteada);

					gettimeofday(&atual, NULL);
					segundos_restantes =
					max_segundos - (atual.tv_sec - inicio.tv_sec);

					continue;
				}

				gettimeofday(&atual, NULL);
				*tempo_levado = (double) (atual.tv_usec - inicio.tv_usec) / 1000000 + (double) (atual.tv_sec - inicio.tv_sec);
				strcpy(buffer_destino, buffer_temp);
				return 1; //retorna 1 ou seja sucesso
			}
		}
	}

	return 0; // retorna 0 indicando que acabou o tempo
}
