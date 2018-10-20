#ifndef SYMBOLTABLE
#define SYMBOLTABLE

typedef struct t_lista{
	void* conteudo;
	struct lista* next;
} t_lista;

typedef struct t_tipo {
	int tipo_tipo;
	union{
		int tipo;
		char *tipousuario;
	}
} t_tipo;

typedef struct t_argumento{
	int a_const;
	int a_static;
	struct tipo arg_tipo;
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
} t_entrada_simbolo_funcao;

typedef struct t_entrada_simbolo{
	int loc_linha;
	int loc_coluna;
	int natureza_semantica;
	int tamanho;
	struct t_tipo entrada_tipo;
	int classe_entrada;
	union {
		t_entrada_simbolo_funcao funcao;
		t_entrada_simbolo_tipousuario tipo_usuario;
	};
} t_entrada_simbolo;

int free_lista(struct *t_lista alvo);

int free_tabela();

int get_entrada(struct *t_lista tabela, struct *t_entrada_simbolo entrada, *char chave, );

int set_entrada(struct *t_lista tabela, struct *t_entrada_simbolo entrada);

#endif




