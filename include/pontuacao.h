#ifndef PONTUACAO_H
#define PONTUACAO_H

#include "respostas.h"
#include "jogadores.h"

// Calcula os pontos da rodada conforme repetição e arredondamento
void calcular_pontuacao_rodada(Resposta *respostas, int num_jogadores);

// Retorna indice do ganhador
int idx_ganhador(Jogador *j, int n);
#endif
