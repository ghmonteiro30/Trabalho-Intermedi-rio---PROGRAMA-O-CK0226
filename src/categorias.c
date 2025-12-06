#include <stdio.h>
#include <stdlib.h>
#include "categorias.h"

#define NUM_CATEGORIAS 5

// Nomes exibidos ao usuário
static const char* NOMES_CATEGORIAS[NUM_CATEGORIAS] = {
    "Nome de Pessoa",
    "Nome de Cidade",
    "Nome de Animal",
    "Nome de Comida",
    "Profissão"
};

// 0 = não usada, 1 = já sorteada
static int categoriasUsadas[NUM_CATEGORIAS];
static int totalSorteadas = 0;

void inicializarCategorias() {
    for (int i = 0; i < NUM_CATEGORIAS; i++) {
        categoriasUsadas[i] = 0;
    }
    totalSorteadas = 0;
}

int existemCategoriasDisponiveis() {
    return totalSorteadas < NUM_CATEGORIAS;
}

TipoCategoria sortearCategoria() {
    if (!existemCategoriasDisponiveis()) {
        return CAT_NENHUMA;
    }

    int indice;
    
    // Continua sorteando até encontrar uma categoria não usada
    do {
        indice = rand() % NUM_CATEGORIAS;
    } while (categoriasUsadas[indice]);

    categoriasUsadas[indice] = 1;
    totalSorteadas++;

    return (TipoCategoria)indice;
}

const char* obterNomeCategoria(TipoCategoria cat) {
    if (cat < 0 || cat >= NUM_CATEGORIAS) {
        return "Categoria Invalida";
    }
    return NOMES_CATEGORIAS[cat];
}
