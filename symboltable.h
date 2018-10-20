#ifndef SYMBOLTABLE
#define SYMBOLTABLE

typedef struct t_lista{
	void* conteudo;
	struct t_lista* prox;
} t_lista;


#define T_TIPO_USUARIO 0
#define T_TIPO_PRIMITIVO 1
typedef struct t_tipo {
	int a_const;
	int a_static;
	int tipo_tipo;
	int tamanho_vetor;
	union{
		int tipo;
		char* tipousuario;
	};
} t_tipo;

typedef struct t_argumento{
	struct t_tipo arg_tipo;
	char* identificador;
} t_argumento;

typedef struct t_campo{
	int encapsulamento;
	int tipo;
	char* identificador;
} t_campo;

typedef struct t_entrada_simbolo_funcao{
	struct t_lista t_argumentos;
} t_entrada_simbolo_funcao;

typedef struct t_entrada_simbolo_tipousuario{
	struct t_lista campos;
} t_entrada_simbolo_tipousuario;

typedef struct t_entrada_simbolo{
	char *chave;
	int loc_linha;
	int loc_coluna;
	int natureza_semantica;
	int tamanho_memoria;
	struct t_tipo entrada_tipo;
	int classe_entrada;
	union {
		t_entrada_simbolo_funcao funcao;
		t_entrada_simbolo_tipousuario tipo_usuario;
	};
} t_entrada_simbolo;

int free_lista(t_lista* t_lista);

int free_tabela();

int get_entrada(t_lista* tabela, t_entrada_simbolo* entrada, char* chave);

int set_entrada(t_lista* tabela, t_entrada_simbolo* entrada);

#endif




