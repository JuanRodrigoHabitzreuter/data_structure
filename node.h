/*desafio eleborado por Valquiria e Juan*/
#ifndef NODE_H
#define NODE_H

typedef struct node {
    void *data;
    struct node *next;
} Node;

Node *cria_node(void *data);
void *get_data(Node *node);
struct node *get_next(Node *node);
void set_next(Node *node, struct node *next);
void libera_node(Node *node);

#endif