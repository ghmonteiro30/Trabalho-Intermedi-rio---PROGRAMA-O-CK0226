VPATH = src include

ALL:	main

main:	main.o jogadores.o sorteios.o util.o respostas.o categorias.o tempo.o pontuacao.o
	gcc main.o jogadores.o sorteios.o util.o respostas.o categorias.o tempo.o pontuacao.o -o main -lm
	
main.o:	main.c jogadores.h sorteios.h util.h
	gcc -Iinclude -c src/main.c

jogadores.o:	jogadores.c jogadores.h
	gcc -Iinclude -c src/jogadores.c

categorias.o:	categorias.c categorias.h
	gcc -Iinclude -c src/categorias.c

sorteios.o:	sorteios.c sorteios.h
	gcc -Iinclude -c src/sorteios.c

respostas.o:	respostas.c respostas.h
	gcc -Iinclude -c src/respostas.c

tempo.o:	tempo.c tempo.h
	gcc -Iinclude -c src/tempo.c

pontuacao.o:	pontuacao.c pontuacao.h respostas.h
	gcc -Iinclude -c src/pontuacao.c

util.o:	util.c util.h
	gcc -Iinclude -c src/util.c
