#ifndef JOGADORES_H
#define JOGADORES_H

// Estrutura que representa um jogador

typedef struct {
    char nome[13];        // até 12 caracteres
    char resposta[31];    // até 30 caracteres
    int pontos;           // pontuação acumulada
    double tempo_total;   // soma dos tempos de resposta
} Jogador;

// Cria dinamicamente um vetor de jogadores
Jogador* criarJogadores(int n);

// Lê e valida os nomes dos jogadores
void lerNomes(Jogador* jogadores, int n);

// Libera a memória alocada
void destruirJogadores(Jogador* jogadores);

#endif
