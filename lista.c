/*desafio eleborado por Valquiria e Juan*/
#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

Lista *cria_lista() {
    Lista *nova_lista = (Lista *) malloc(sizeof(Lista));
    if (nova_lista == NULL) {
        perror("Erro ao alocar memória para a lista");
        exit(EXIT_FAILURE);
    }
    nova_lista->inicio = NULL;
    nova_lista->fim = NULL;
    nova_lista->quantidade = 0;
    return nova_lista;
}

void insere_inicio(Lista *lista, Node *node) {
    if (lista == NULL || node == NULL) {
        return;
    }
    node->next = lista->inicio;
    lista->inicio = node;
    if (lista->fim == NULL) {
        lista->fim = node;
    }
    lista->quantidade++;
}

void insere_final(Lista *lista, Node *node) {
    if (lista == NULL || node == NULL) {
        return;
    }
    node->next = NULL;
    if (lista->fim == NULL) {
        lista->inicio = node;
        lista->fim = node;
    } else {
        lista->fim->next = node;
        lista->fim = node;
    }
    lista->quantidade++;
}

Node *remove_inicio(Lista *lista) {
    if (lista == NULL || lista->inicio == NULL) {
        return NULL;
    }
    Node *removido = lista->inicio;
    lista->inicio = lista->inicio->next;
    if (lista->inicio == NULL) {
        lista->fim = NULL;
    }
    lista->quantidade--;
    return removido;
}

Node *remove_final(Lista *lista) {
    if (lista == NULL || lista->inicio == NULL) {
        return NULL;
    }
    Node *removido = lista->fim;
    if (lista->inicio == lista->fim) {
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        Node *atual = lista->inicio;
        while (atual->next != lista->fim) {
            atual = atual->next;
        }
        atual->next = NULL;
        lista->fim = atual;
    }
    lista->quantidade--;
    return removido;
}

int get_quantidade(Lista *lista) {
    if (lista == NULL) {
        return 0;
    }
    return lista->quantidade;
}

Node *get_inicio(Lista *lista) {
    if (lista == NULL) {
        return NULL;
    }
    return lista->inicio;
}

Node *get_fim(Lista *lista) {
    if (lista == NULL) {
        return NULL;
    }
    return lista->fim;
}

void libera_lista(Lista *lista) {
    if (lista == NULL) {
        return;
    }
    Node *atual = lista->inicio;
    Node *proximo;
    while (atual != NULL) {
        proximo = atual->next;
        libera_node(atual); // Assume que existe uma função para liberar um nó
        atual = proximo;
    }
    free(lista);
}