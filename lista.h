/*desafio eleborado por Valquiria e Juan*/
#ifndef LISTA_H
#define LISTA_H

#include "node.h" // Depende da definição de Node

typedef struct lista {
    Node *inicio;
    Node *fim;
    int quantidade;
} Lista;

Lista *cria_lista();
void insere_inicio(Lista *lista, Node *node);
void insere_final(Lista *lista, Node *node);
Node *remove_inicio(Lista *lista);
Node *remove_final(Lista *lista);
int get_quantidade(Lista *lista);
Node *get_inicio(Lista *lista);
Node *get_fim(Lista *lista);
void libera_lista(Lista *lista);

#endif