#include "jogadores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aloca e inicializa vetor de jogadores
Jogador* criarJogadores(int n) {
    Jogador* j = (Jogador*) malloc(n * sizeof(Jogador));
    if (!j) {
        printf("Erro ao alocar memória para jogadores.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        j[i].pontos = 0;
        j[i].tempo_total = 0.0;
        j[i].nome[0] = '\0';
        j[i].resposta[0] = '\0';
    }

    return j;
}

// Lê e valida nome dos jogadores
void lerNomes(Jogador* jogadores, int n) {
    char buffer[100];

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Qual é o nome do jogador %d? ", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strlen(buffer) > 12) {
                printf("O nome deve ter no máximo 12 caracteres. Tente novamente.\n");
                continue;
            }

            strcpy(jogadores[i].nome, buffer);
            break;
        }
    }
}

// Libera memória
void destruirJogadores(Jogador* jogadores) {
    free(jogadores);
}
