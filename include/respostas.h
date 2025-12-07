#ifndef RESPOSTAS_H
#define RESPOSTAS_H

#define TAM_RESPOSTA 30

// estrutura que referente a resposta de um jogador
typedef struct {
    char texto[TAM_RESPOSTA + 1];
    int pontos;   // Pontos obtidos na rodada
    int valida;   // 1 = resposta válida / 0 = inválida ou acabou o tempo
} Resposta;

// Função que vai ler a resposta do usuário com limite de tempo
// Retorna 1 se válida, 0 se tempo acabou ou inválida
int ler_resposta_com_tempo(char *buffer_destino,int max_segundos,char letra_sorteada,int eh_nome_pessoa);

#endif
