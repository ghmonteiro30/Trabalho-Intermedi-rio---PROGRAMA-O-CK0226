#ifndef SORTEIOS_H
#define SORTEIOS_H

// Muda a semente de geracao de numeros para que a sequencia seja diferente toda vez que o programa for rodado.
void iniciar_semente();

// Sorteia uma letra de A a Z, excluindo K, W e Y
char sortear_letra();

// Sorteia a ordem de jogada dos n jogadores
void sortear_ordem(int *ordem, int n);

// Retorna 1 se ordem valida (ou seja, se nova ordem != ordem da rodada anterior
int ordem_valida(int *ordem, int *ordem_ant, int n);

#endif
