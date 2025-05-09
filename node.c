/*desafio eleborado por Valquiria e Juan*/
#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node *cria_node(void *data) {
    Node *novo_node = (Node *) malloc(sizeof(Node));
    if (novo_node == NULL) {
        perror("Erro ao alocar memória para o nó");
        exit(EXIT_FAILURE);
    }
    novo_node->data = data;
    novo_node->next = NULL;
    return novo_node;
}

void *get_data(Node *node) {
    if (node == NULL) {
        return NULL;
    }
    return node->data;
}

struct node *get_next(Node *node) {
    if (node == NULL) {
        return NULL;
    }
    return node->next;
}

void set_next(Node *node, struct node *next) {
    if (node != NULL) {
        node->next = next;
    }
}

void libera_node(Node *node) {
    if (node != NULL) {
        free(node);
    }
}