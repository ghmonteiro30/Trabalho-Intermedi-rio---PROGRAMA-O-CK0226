#include <time.h>

char sortear_letra(){
	char c;
	
	do {
		c = (rand() % 25) + 65;  //Gera um inteira de 65 a 90
	} while (c == 75 || c == 87 || c == 89); //Gera novamente se o inteiro gerado for 75, 87 ou 89, ou seja K, W e Y
	
	return c;
}


void iniciar_semente(){
	srand((int)time(NULL)); // Muda a semente de geracao de numeros para que a sequencia seja diferente toda vez que o programa for rodado.
}
