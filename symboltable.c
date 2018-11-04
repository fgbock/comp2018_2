#include "symboltable.h"
#define NATUREZA_NULL               0
#define NATUREZA_LITERAL_INT        1
#define NATUREZA_LITERAL_FLOAT      2
#define NATUREZA_LITERAL_CHAR       3
#define NATUREZA_LITERAL_STRING     4
#define NATUREZA_LITERAL_BOOL       5
#define NATUREZA_IDENTIFICADOR      6

struct t_symbol_table* tabela_global;

/*
int free_tabela(t_symbol_table* table) {
	t_lista* entrada_prev;
	t_lista* entrada = table->symbols;
	t_entrada_simbolo* simb;
	t_entrada_simbolo_funcao aux1;
	t_entrada_simbolo_tipousuario aux2;
	while(entrada != NULL){
		entrada_prev = entrada;
		entrada = entrada->prox;
		simb = entrada_prev->conteudo;
		switch (simb->classe_entrada){
			case T_ENTRADA_DECLARACAO_FUNCAO:
				aux1 = simb->funcao;
				free_lista(aux1.parameters);
				free(simb);
				free(entrada_prev);
				break;
			case T_ENTRADA_TIPO_USUARIO:
				aux2 = simb->tipo_usuario;
				//free_lista(aux2.campos);
				free(simb);
				free(entrada_prev);
				break;
			default:
				free(simb);
				free(entrada_prev);
				break;
		}
	}
}
*/

t_symbol_table* make_table(int is_global_table) 
{
	t_symbol_table* table = malloc(sizeof(t_symbol_table));
	table->offset_in_bytes = 0;
	table->is_global_table = is_global_table;
	table->symbols.conteudo = NULL;
	table->symbols.prox = NULL;
	return table;
}

int get_entrada(t_symbol_table* table, t_entrada_simbolo** entrada_retorno, char* chave_buscada)
{
	t_lista* entrada = &table->symbols;
	t_entrada_simbolo* simbolo;
	while (entrada != NULL)
	{
		if (entrada->conteudo == NULL)
		{
			entrada = entrada->prox;
			continue;
		}
		simbolo = entrada->conteudo;
		if (strcmp(simbolo->chave, chave_buscada) == 0)
		{
			*entrada_retorno = simbolo;
			return 0;
		}
		else 
		{
			entrada = entrada->prox;
		}
	}
	return -1;
}

int get_natureza_size(int natureza_semantica)
{
	switch(natureza_semantica)
	{
		case NATUREZA_LITERAL_INT:
			return 4;
		case NATUREZA_LITERAL_FLOAT:
			return 8;
		case NATUREZA_LITERAL_CHAR:
			return 1;
		case NATUREZA_LITERAL_STRING:
			return 1;
		case NATUREZA_LITERAL_BOOL:
			return 1;
	}
	return 0;
}

int set_entrada(t_symbol_table* table, t_entrada_simbolo* entrada_inserida)
{
	// Generate missing properties
	if (entrada_inserida->classe_entrada == T_ENTRADA_VARIAVEL)
	{
		t_tipo tipo_aux = entrada_inserida->variavel.tipo;
		entrada_inserida->variavel.size_in_bytes = get_natureza_size(tipo_aux.natureza_semantica);
		if (tipo_aux.tamanho_vetor != -1)
		{
			entrada_inserida->variavel.size_in_bytes *= tipo_aux.tamanho_vetor;
		}
		entrada_inserida->variavel.offset_in_bytes = table->offset_in_bytes;
		entrada_inserida->variavel.is_global_var = table->is_global_table;
		table->offset_in_bytes += entrada_inserida->variavel.size_in_bytes;
	}

	// Add into table
	t_lista* entrada = &table->symbols;
	if (table != NULL && entrada->conteudo == NULL) 
	{
		entrada->conteudo = entrada_inserida;
		return 0;
	}
	while(entrada->prox != NULL) 
	{
		entrada = entrada->prox;
	}
	entrada->prox = malloc(sizeof(t_lista));
	entrada->prox->prox = NULL;

	entrada->prox->conteudo = entrada_inserida;
	return 0;
}

void print_table(t_symbol_table* table)
{
	t_lista* p = &table->symbols;
	printf("Table: ");
	printf("Offset: %d\n", table->offset_in_bytes);
	printf("Is global: %d\n", table->is_global_table);
	while (p != NULL)
	{
		if (p->conteudo != NULL)
		{
			t_entrada_simbolo* table_entry = (t_entrada_simbolo *)p->conteudo;
			printf("Chave: %s, ", table_entry->chave);
			printf("Linha: %d, ", table_entry->loc_linha);
			printf("Coluna: %d, ", table_entry->loc_coluna);
			if (table_entry->classe_entrada == T_ENTRADA_VARIAVEL)
			{
				printf("Tamanho: %d, ", table_entry->variavel.size_in_bytes);
				printf("Offset: %d,  ", table_entry->variavel.offset_in_bytes);
				printf("Is global: %d,  ", table_entry->variavel.is_global_var);
				switch(table_entry->variavel.tipo.natureza_semantica)
				{
					case NATUREZA_LITERAL_INT:
						printf("Tipo: Int\n");
						break;
					case NATUREZA_LITERAL_FLOAT:
						printf("Tipo: Float\n");
						break;
					case NATUREZA_LITERAL_CHAR:
						printf("Tipo: Char\n");
						break;
					case NATUREZA_LITERAL_STRING:
						printf("Tipo: String\n");
						break;
					case NATUREZA_LITERAL_BOOL:
						printf("Tipo: Bool\n");
						break;
					case NATUREZA_IDENTIFICADOR:
						printf("Tipo: Tipo de Usuario\n");
						break;
				}
			}
		}
		p = p->prox;
	}
	printf("\n");
}
