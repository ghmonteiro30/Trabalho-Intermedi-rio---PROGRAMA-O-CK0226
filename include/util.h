#ifndef UTIL_H
#define UTIL_H
#include "jogadores.h"

void limpa_stdin(); //Limpa o stind para nao interferir com algum fgets
void limpa_tela(); // Da um clear no terminal
void esperar_entrada(char *mensagem); // Espera um enter do usuario
void printar_tabela(Jogador *j, int num_jogadores, int num_rodadas, int *ponto_rodada, char (*categorias)[15]);  

#endif
