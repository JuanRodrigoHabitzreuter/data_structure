/*desafio eleborado por Valquiria e Juan*/
#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "lista.h"
#include "cliente.h"

// Defina um tipo para representar os critérios de busca/inserção
typedef enum {
    POR_NOME = 1,
    POR_BAIRRO = 2,
    POR_PESSOAS = 3,
    POR_CRIANCAS = 4,
    POR_RENDA = 5,
} CriterioBusca;

// Defina os tamanhos das tabelas hash
#define HASH_SIZE_NOME 29
#define HASH_SIZE_BAIRRO 29
#define HASH_SIZE_PESSOAS 5
#define HASH_SIZE_CRIANCAS 2
#define HASH_SIZE_RENDA 4

typedef struct estrutura {
    Lista *tabelas[5]; // Array de listas, indexado pelo CriterioBusca
} Estrutura;

Estrutura *cria_estrutura();
void insere_cliente(Estrutura *estrutura, CriterioBusca criterio, Cliente *cliente);
Lista *recupera_cliente(Estrutura *estrutura, CriterioBusca criterio, int valor_int, const char *valor_str);
void libera_estrutura(Estrutura *estrutura);

#endif