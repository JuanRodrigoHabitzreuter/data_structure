/*desafio eleborado por Valquiria e Juan*/
#include "estrutura.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Função de hash simples para strings (soma dos caracteres módulo tamanho)
int hash_string(const char *str, int size) {
    unsigned long hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + toupper(str[i])) % size;
    }
    return hash;
}

// Função de hash simples para inteiros
int hash_int(int value, int size) {
    return value % size;
}

// Função de hash para crianças (int 0 ou >0)
unsigned int hash_criancas(int criancas) {
    return criancas > 0 ? 1 : 0;
}

// Função de hash para faixas de renda
int hash_renda(float renda) {
    if (renda <= 2000.00) return 0;
    if (renda <= 3000.00) return 1;
    if (renda <= 5000.00) return 2;
    return 3; // Renda > 5000.00
}

// Função hash para o número de pessoas
int hash_pessoas(int pessoas) {
    if (pessoas <= 1) return 0;
    if (pessoas == 2) return 1;
    if (pessoas == 3) return 2;
    if (pessoas == 4) return 3;
    return 4;
}

Estrutura *cria_estrutura() {
    Estrutura *estrutura = (Estrutura *) malloc(sizeof(Estrutura));
    if (!estrutura) {
        perror("Erro ao alocar memória para a estrutura");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 5; i++) {
        estrutura->tabelas[i] = cria_lista();
    }
    return estrutura;
}

void insere_cliente(Estrutura *estrutura, CriterioBusca criterio, Cliente *cliente) {
    Node *node = cria_node(cliente);
    if (!node) return;

    int index = -1;
    int size = 0;

    switch (criterio) {
        case POR_NOME:
            index = hash_string(get_nome(cliente), HASH_SIZE_NOME);
            size = HASH_SIZE_NOME;
            break;
        case POR_BAIRRO:
            index = hash_string(get_bairro(cliente), HASH_SIZE_BAIRRO);
            size = HASH_SIZE_BAIRRO;
            break;
        case POR_PESSOAS:
            index = hash_pessoas(get_pessoas(cliente));
            size = HASH_SIZE_PESSOAS;
            break;
        case POR_CRIANCAS:
            index = hash_criancas(get_criancas(cliente));
            size = HASH_SIZE_CRIANCAS;
            break;
        case POR_RENDA:
            index = hash_renda(get_renda(cliente));
            size = HASH_SIZE_RENDA;
            break;
        default:
            printf("Critério de inserção inválido!\n");
            libera_node(node);
            return;
    }
    if (index != -1) {
        estrutura->tabelas[criterio - 1] = estrutura->tabelas[criterio - 1]; // Apenas para evitar warning de unused
        insere_final(estrutura->tabelas[criterio - 1], node);
    }
}

Lista *recupera_cliente(Estrutura *estrutura, CriterioBusca criterio, int valor_int, const char *valor_str) {
    Lista *resultado = cria_lista();
    int index = -1;
    Lista *lista_busca = NULL;

    switch (criterio) {
        case POR_NOME:
            index = hash_string(valor_str, HASH_SIZE_NOME);
            lista_busca = estrutura->tabelas[POR_NOME - 1];
            break;
        case POR_BAIRRO:
            index = hash_string(valor_str, HASH_SIZE_BAIRRO);
            lista_busca = estrutura->tabelas[POR_BAIRRO - 1];
            break;
        case POR_PESSOAS:
            index = hash_pessoas(valor_int);
            lista_busca = estrutura->tabelas[POR_PESSOAS - 1];
            break;
        case POR_CRIANCAS:
            index = hash_criancas(valor_int);
            lista_busca = estrutura->tabelas[POR_CRIANCAS - 1];
            break;
        case POR_RENDA:
            switch (valor_int) {
                case 1: index = 0; break;
                case 2: index = 1; break;
                case 3: index = 2; break;
                case 4: index = 3; break;
            }
            lista_busca = estrutura->tabelas[POR_RENDA - 1];
            break;
        default:
            printf("Critério de recuperação inválido!\n");
            return resultado;
    }

    if (lista_busca && index != -1) {
        Node *cursor = get_inicio(lista_busca);
        while (cursor != NULL) {
            Cliente *cliente = get_data(cursor);
            switch (criterio) {
                case POR_NOME:
                    if (strcmp(get_nome(cliente), valor_str) == 0) insere_final(resultado, cria_node(cliente));
                    break;
                case POR_BAIRRO:
                    if (strcmp(get_bairro(cliente), valor_str) == 0) insere_final(resultado, cria_node(cliente));
                    break;
                case POR_PESSOAS:
                    if (get_pessoas(cliente) == valor_int) insere_final(resultado, cria_node(cliente));
                    break;
                case POR_CRIANCAS:
                    if (get_criancas(cliente) == valor_int) insere_final(resultado, cria_node(cliente));
                    break;
                case POR_RENDA: {
                    float renda = get_renda(cliente);
                    switch (valor_int) {
                        case 1: if (renda <= 2000.00) insere_final(resultado, cria_node(cliente)); break;
                        case 2: if (renda <= 3000.00) insere_final(resultado, cria_node(cliente)); break;
                        case 3: if (renda <= 5000.00) insere_final(resultado, cria_node(cliente)); break;
                        case 4: if (renda > 5000.00) insere_final(resultado, cria_node(cliente)); break;
                    }
                    break;
                }
            }
            cursor = get_next(cursor);
        }
    }
    return resultado;
}

void libera_estrutura(Estrutura *estrutura) {
    if (estrutura) {
        for (int i = 0; i < 5; i++) {
            libera_lista(estrutura->tabelas[i]);
        }
        free(estrutura);
    }
}