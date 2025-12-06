#include "tempo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <time.h>
#endif

double agora() {
#ifdef _WIN32
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / (double)freq.QuadPart;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
#endif
}

double controlarTempoDeResposta(Jogador *jog, int tempo_limite, char *destino) {
    char buffer[200];
    double inicio = agora();

    while (1) {
        double t = agora() - inicio;
        if (t > tempo_limite)
            return -1;

        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        t = agora() - inicio;
        if (t > tempo_limite)
            return -1;

        if (strlen(buffer) == 0) {
            printf("Resposta vazia! Tente novamente: ");
            continue;
        }
        if (strlen(buffer) > 30) {
            printf("A resposta deve ter até 30 caracteres. Tente novamente: ");
            continue;
        }

        strcpy(destino, buffer);
        return t;
    }
}
