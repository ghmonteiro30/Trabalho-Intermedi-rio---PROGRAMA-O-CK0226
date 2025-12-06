#ifndef CATEGORIAS_H
#define CATEGORIAS_H

// Enum para identificar as categorias do jogo
typedef enum {
    CAT_PESSOA = 0,
    CAT_CIDADE,
    CAT_ANIMAL,
    CAT_COMIDA,
    CAT_PROFISSAO,
    CAT_NENHUMA   // vai ser utilizado quando nao houverem categorias disponiveis
} TipoCategoria;

// Marca todas as categorias como não usadas
void inicializarCategorias();

// Retorna uma categoria ainda não sorteada
// se todas ja foram utilizadas retorna o CAT_NENHUMA
TipoCategoria sortearCategoria();

// retorna o nome textual/string da categoria
const char* obterNomeCategoria(TipoCategoria cat);

// Verifica se ainda existem categorias disponíveis
int existemCategoriasDisponiveis();

#endif
