#include "jogadores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria um vetor de jogadores e inicializa seus campos básicos.
// Cada jogador começa com 0 pontos e tempo total 0 e strings vazias.
Jogador* criarJogadores(int n) {
    Jogador* j = (Jogador*) malloc(n * sizeof(Jogador));
    if (!j) { // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória para jogadores.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) { // Inicializa os campos
        j[i].pontos = 0;
        j[i].tempo_total = 0.0;
        j[i].nome[0] = '\0';
        j[i].resposta[0] = '\0';
    }

    return j; // Retorna o ponteiro para o vetor de jogadores
}

// Lê os nomes dos jogadores, garantindo que não excedam 12 caracteres.
// Também remove o caractere de nova linha lido pelo fgets.
void lerNomes(Jogador* jogadores, int n) {
    char buffer[100];

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Qual é o nome do jogador %d? ", i + 1);
            fgets(buffer, sizeof(buffer), stdin); 
            buffer[strcspn(buffer, "\n")] = '\0';// Remove o '\n' do final

            if (strlen(buffer) > 12) { // Verifica o tamanho do nome e solicita novamente se exceder
                printf("O nome deve ter no máximo 12 caracteres. Tente novamente.\n");
                continue; 
            }
            
            strcpy(jogadores[i].nome, buffer); // Copia o nome para a estrutura do jogador
            break;
        }
    }
}

// Libera memória alocada para o vetor de jogadores.
void destruirJogadores(Jogador* jogadores) { 
    free(jogadores);
}
