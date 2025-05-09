# data_structure
estrutura de dados em cima de testes prontos, utilizando linguagem C, listas encadeadas e hashtables
📘 Estrutura de Dados para Manipulação de Clientes com HashTables em C
📌 Objetivo
Construir uma estrutura de dados eficiente para cadastrar e recuperar informações de clientes com base em diferentes critérios, utilizando:

Linguagem C

TADs organizados em arquivos .h e .c

Listas encadeadas

Tabelas hash (hash tables)

🧱 Estrutura do Cliente
Cada cliente contém:

nome (até 40 caracteres)

bairro (até 40 caracteres)

pessoas_residencia (int: de 1 a 5+)

tem_criancas (bool: 0 ou 1)

renda (double)

c
Copiar
Editar
typedef struct ficha_cliente {
    char nome[41];
    char bairro[41];
    int pessoas_residencia;
    int tem_criancas;
    double renda;
} FichaCliente;
🗃️ Arquivos do Projeto
less
Copiar
Editar
📁 projeto_clientes/
│
├── cliente.h / cliente.c       // TAD do cliente
├── nodo.h / nodo.c             // Nó da lista encadeada
├── lista.h / lista.c           // Lista encadeada de clientes
├── estrutura.h / estrutura.c   // Estrutura principal com hash tables
├── teste.c         // Testes fornecidos
🔁 Listas Encadeadas
Cada bucket da tabela hash é uma lista encadeada.

Cada nodo armazena um ponteiro para FichaCliente.

🧩 Tabelas Hash
Hash Tables Criadas:
hash_nome[PRIMO] – hash do nome

hash_bairro[PRIMO] – hash do bairro

hash_pessoas[5] – índice direto de 1 a 5+

hash_criancas[2] – 0 (não tem) ou 1 (tem)

hash_renda[4] – por faixa:

Faixa	Índice
até 2000	0
2000.01 até 3000	1
3000.01 até 5000	2
acima de 5000	3

🔍 Recuperação de Clientes
Assinatura da Função
c
Copiar
Editar
Lista* recupera_cliente(Estrutura *estrutura, int criterio, int complemento, char *busca);
Critérios:
Critério	Descrição	complemento	busca
1	Nome	0	string
2	Bairro	0	string
3	Pessoas na residência (1–5+)	1–5	NULL
4	Tem crianças menores de 5 anos	0 ou 1	NULL
5	Faixa de renda	0–3	NULL

⚙️ Funções Básicas Esperadas
cliente.h / cliente.c
FichaCliente* post_ficha(...)

void delete_ficha(FichaCliente*)

char* get_nome(...), etc.

nodo.h / nodo.c
Nodo* cria_nodo(FichaCliente*)

lista.h / lista.c
Lista* cria_lista()

void insere_lista(Lista*, FichaCliente*)

void libera_lista(Lista*)

estrutura.h / estrutura.c
Estrutura* cria_estrutura()

void adiciona_cliente(Estrutura*, FichaCliente*)

Lista* recupera_cliente(...)

✅ Requisitos Atendidos
 Listas encadeadas usadas nos buckets

 Recuperação por todos os critérios

 Múltiplas tabelas hash (nome, bairro, etc.)

 Funções compatíveis com o teste fornecido

 Alocação dinâmica e modularização

 Função recupera_cliente(...) com critérios corretos

 Estrutura extensível e eficiente

💡 Observações
As funções de hash para nome e bairro usam soma de caracteres com mod PRIMO.

Pessoas, crianças e renda usam índices diretos para maior performance.

A estrutura está otimizada para inserção e recuperação por critério sem necessidade de percorrer todos os dados.

