VPATH = src include

ALL:	main

main:	main.o jogadores.o sorteios.o util.o
	gcc main.o jogadores.o sorteios.o util.o -o main
	
main.o:	main.c jogadores.h sorteios.h util.h
	gcc -Iinclude -c src/main.c

jogadores.o:	jogadores.c jogadores.h
	gcc -Iinclude -c src/jogadores.c

sorteios.o:	sorteios.c sorteios.h
	gcc -Iinclude -c src/sorteios.c

util.o:	util.c util.h
	gcc -Iinclude -c src/util.c
