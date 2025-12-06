#include <stdio.h>
#include <stdlib.h>

void limpa_stdin(){
	int c;
	do {
		c = getchar();
	} while (c != '\n');
}
#include "util.h"

void limpa_tela(){
	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__MACH__)
		system("clear");
	#endif
}

void esperar_entrada(char *mensagem){
	char buf[1];
	
	printf("\n%s", mensagem);
	fgets(buf, 1, stdin);
	limpa_stdin();
}
