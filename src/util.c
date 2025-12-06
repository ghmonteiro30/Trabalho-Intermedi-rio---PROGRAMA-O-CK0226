#include <stdio.h>
#include <stdlib.h>

void limpa_stdin(){
	char c[2];
	fgets(c, 2, stdin);
}

void limpa_tela(){
	system("clear");
}
