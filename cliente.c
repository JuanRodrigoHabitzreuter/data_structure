/*desafio eleborado por Valquiria e Juan*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

// Definição da struct cliente (tipo opaco)
struct cliente {
    char nome[TAM_NOME];
    char bairro[TAM_BAIRRO];
    int pessoas;
    int criancas;
    double renda;
};

Cliente* cria_cliente(const char* nome, const char* bairro, int pessoas, int criancas, double renda) {
    Cliente* c = (Cliente*) malloc(sizeof(Cliente));
    if (c == NULL) {
        fprintf(stderr, "Erro ao alocar memória para cliente.\n");
        return NULL;
    }

    strncpy(c->nome, nome, TAM_NOME - 1);
    c->nome[TAM_NOME - 1] = '\0';

    strncpy(c->bairro, bairro, TAM_BAIRRO - 1);
    c->bairro[TAM_BAIRRO - 1] = '\0';

    c->pessoas = pessoas;
    c->criancas = criancas;
    c->renda = renda;

    return c;
}

const char* get_nome(Cliente* c) {
    if (c == NULL) return NULL;
    return (const char*)c->nome; // Cast para garantir const
}

const char* get_bairro(Cliente* c) {
    if (c == NULL) return NULL;
    return (const char*)c->bairro; // Cast para garantir const
}

int get_pessoas(Cliente* c) {
    if (c == NULL) return -1;
    return c->pessoas;
}

int get_criancas(Cliente* c) {
    if (c == NULL) return -1;
    return c->criancas;
}

double get_renda(Cliente* c) {
    if (c == NULL) return -1.0;
    return c->renda;
}

void libera_cliente(Cliente* c) {
    if (c != NULL) {
        free(c);
    }
}

// Função para criar uma lista de clientes (inicialmente vazia)
Clientenode* criar_lista() {
    return NULL; // Lista vazia
}

// Função para adicionar um cliente ao início da lista
void inserir_cliente(Clientenode** lista, Cliente* c) {
    Clientenode* novo = (Clientenode*) malloc(sizeof(Clientenode));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo cliente.\n");
        return;
    }
    novo->cliente = c;
    novo->proximo = *lista; // Adiciona no início da lista
    *lista = novo;
}

// Função para buscar um cliente pelo nome na lista
Cliente* busca_cliente_nome(Clientenode* lista, const char* nome) {
    while (lista != NULL) {
        if (strcmp(get_nome(lista->cliente), nome) == 0) {
            return lista->cliente;
        }
        lista = lista->proximo;
    }
    return NULL; // Cliente não encontrado
}

// Função para liberar a memória de um nó da lista e do cliente dentro dele
void libera_cliente_node(Clientenode* node) {
    if (node != NULL) {
        // Primeiro libera o cliente associado ao nó
        libera_cliente(node->cliente);
        // Depois libera o próprio nó
        free(node);
    }
}

// Função para liberar a memória de toda a lista de clientes
void libera_lista_clientes(Clientenode* head) {
    Clientenode* atual = head;
    while (atual) {
        Clientenode* proximo = atual->proximo;
        libera_cliente_node(atual);
        atual = proximo;
    }
}