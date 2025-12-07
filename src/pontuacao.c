#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "pontuacao.h"
#include "respostas.h"

// funcao auxiliar que vai converter string para maiúsculas
static void para_maiusculas(char *destino, const char *origem)
{
    while (*origem) {
        *destino = toupper((unsigned char)*origem);
        destino++;
        origem++;
    }
    *destino = '\0';
}

void calcular_pontuacao_rodada(Resposta *respostas, int num_jogadores)
{   
    char **normalizadas = malloc(num_jogadores * sizeof(char*));
    int *repeticoes = calloc(num_jogadores, sizeof(int));
    //alocacao dinamica
    for (int i = 0; i < num_jogadores; i++) {
        normalizadas[i] = malloc((TAM_RESPOSTA + 1) * sizeof(char));

        if (respostas[i].valida) {
            para_maiusculas(normalizadas[i], respostas[i].texto);
            repeticoes[i] = 1; // conta a si mesmo inicialmente
        } else {
            strcpy(normalizadas[i], "");
            repeticoes[i] = 0;
        }
    }

    // Descobre repetições
    for (int i = 0; i < num_jogadores; i++) {
        if (!respostas[i].valida) continue;

        for (int j = i + 1; j < num_jogadores; j++) {
            if (respostas[j].valida &&
                strcmp(normalizadas[i], normalizadas[j]) == 0)
            {
                repeticoes[i]++;
                repeticoes[j]++;
            }
        }
    }

    // Calcula pontos
    for (int i = 0; i < num_jogadores; i++) {

        if (respostas[i].valida && repeticoes[i] > 0) {

            int tamanho = strlen(respostas[i].texto); 
            //calculo do arredondamento
            double calculado = (double)tamanho / repeticoes[i];

            respostas[i].pontos = (int)round(calculado);

        } else {
            respostas[i].pontos = 0;
        }
    }

    // limpeza de memoria
    for (int i = 0; i < num_jogadores; i++)
        free(normalizadas[i]);

    free(normalizadas);
    free(repeticoes);
}

int idx_ganhador(Jogador *j, int n){
	int i, ganhador;
	
	ganhador = 0;
	for (i = 1; i < n; i++){
		if (j[i].pontos >= j[ganhador].pontos) {
			if (j[i].pontos == j[ganhador].pontos) {
				if (j[i].tempo_total < j[ganhador].tempo_total)
					ganhador = i;
			} else
				ganhador = i;
		}
	}
	
	return ganhador;
}

