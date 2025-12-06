#include <stdio.h>
#include <stdlib.h>

void limpa_stdin(){
	char c[2];
	fgets(c, 2, stdin);
}
#include "util.h"

void limpa_tela(){
	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__MACH__)
		system("clear");
	#endif
}
