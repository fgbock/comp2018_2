#ifndef SYMBOLTABLE
#define SYMBOLTABLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct t_tipo {
	int is_const;
	int is_static;
	int natureza_semantica;
	int tamanho_vetor;
	char* user_type_name; // Valido quando natureza == NATUREZA_IDENTIFICADOR
} t_tipo;

typedef struct t_argumento {
	t_tipo arg_tipo;
	char* identificador;
} t_argumento;

typedef struct t_campo {
	int encapsulamento;
	int tipo;
	char* identificador;
} t_campo;

typedef struct t_entrada_simbolo_funcao {
	t_lista* parameters;
	t_tipo return_type;
} t_entrada_simbolo_funcao;

typedef struct t_entrada_simbolo_tipousuario {
	t_lista* campos;
	int size_in_bytes;
} t_entrada_simbolo_tipousuario;

typedef struct t_entrada_declaracao_variavel {
	t_tipo tipo;
	int offset_in_bytes;
	int size_in_bytes;
	int is_global_var;
} t_entrada_declaracao_variavel;

#define T_ENTRADA_DECLARACAO_FUNCAO 0
#define T_ENTRADA_TIPO_USUARIO 1
#define T_ENTRADA_VARIAVEL 2

typedef struct t_entrada_simbolo {
	char *chave;
	int loc_linha;
	int loc_coluna;
	int classe_entrada;
	union {
		t_entrada_simbolo_funcao      funcao;
		t_entrada_simbolo_tipousuario tipo_usuario;
		t_entrada_declaracao_variavel variavel;
	};
} t_entrada_simbolo;

typedef struct t_symbol_table {
	int offset_in_bytes;
	int is_global_table;
	t_lista symbols;
} t_symbol_table;

//typedef t_lista symbol_table;


t_symbol_table* make_table(int is_global_table);

//int free_tabela();

/*
* Procura na 'tabela' pela 'chave'. Caso encontre, salva o conteudo no ponteiro 'entrada'
*/
int get_entrada(t_symbol_table* table, t_entrada_simbolo** entrada_retorno, char* chave_buscada);

/*
* Insere uma 'entrada' na tabela de simbolos 'tabela'
* Retorna 0 se sucesso, -1 se erro
*/
int set_entrada(t_symbol_table* table, t_entrada_simbolo* entrada);

int get_natureza_size(int natureza_semantica);


void print_table(t_symbol_table* table);

#endif




