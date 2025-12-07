#include "sorteios.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char sortear_letra(){
	char c;
	
	do {
		c = (rand() % 26) + 65;  //Gera um inteira de 65 a 90
	} while (c == 75 || c == 87 || c == 89); //Gera novamente se o inteiro gerado for 75, 87 ou 89, ou seja K, W e Y
	
	return c;
}

void sortear_ordem(int *ordem, int n){
	int i = 0, j, valido;
	
	do {
		valido = 1;
		ordem[i] = rand() % n;
		for (j = 0; j < i; j++)
			if (ordem[j] == ordem[i])
				valido = 0;
		if (valido)
			i++;
	} while (i < n);
}

int ordem_valida(int *ordem, int *ordem_ant, int n) {
	int i;
	
	for (i = 0; i < n; i++) 
		if (ordem[i] != ordem_ant[i])
			return 1;			// Se algum inteiro na mesma posição for diferente, a nova ordem é diferente da anterior
	return 0;                                       // Se todos os inteiros forem iguais, a nova ordem é igual a anterior 					
}

void iniciar_semente(){
	srand((int)time(NULL)); // Muda a semente de geracao de numeros para que a sequencia seja diferente toda vez que o programa for rodado.
}
