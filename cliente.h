/*desafio eleborado por Valquiria e Juan*/
#ifndef CLIENTE_H
#define CLIENTE_H

#define TAM_NOME 41
#define TAM_BAIRRO 41

// Declaração da struct cliente (tipo opaco)
typedef struct cliente Cliente;

// Declaração da struct para o nó da lista encadeada de clientes
typedef struct cliente_node Clientenode;

struct cliente_node {
    Cliente* cliente;
    struct cliente_node* proximo;
};

const char* get_nome(Cliente* c);
const char* get_bairro(Cliente* c);
int get_pessoas(Cliente* c);
int get_criancas(Cliente* c);
double get_renda(Cliente* c);

// Função para criar um novo cliente
Cliente* cria_cliente(const char* nome, const char* bairro, int pessoas, int criancas, double renda);

// Função para liberar a memória de um cliente
void libera_cliente(Cliente* c);

// Função para liberar o nó da lista (incluindo o cliente que ele contém)
void libera_cliente_node(Clientenode* node);

// Função para criar uma lista de clientes (inicialmente vazia)
Clientenode* criar_lista();

// Função para adicionar um cliente ao início da lista
void inserir_cliente(Clientenode** lista, Cliente* c);

// Função para buscar um cliente pelo nome na lista
Cliente* busca_cliente_nome(Clientenode* lista, const char* nome);

// Função para liberar a memória de toda a lista de clientes
void libera_lista_clientes(Clientenode* head);

#endif // CLIENTE_H