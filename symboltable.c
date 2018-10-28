#include "symboltable.h"
#define NATUREZA_NULL               0
#define NATUREZA_LITERAL_INT        1
#define NATUREZA_LITERAL_FLOAT      2
#define NATUREZA_LITERAL_CHAR       3
#define NATUREZA_LITERAL_STRING     4
#define NATUREZA_LITERAL_BOOL       5
#define NATUREZA_IDENTIFICADOR      6

struct t_lista* tabela_global;

int free_tabela(t_lista* lista) {
	t_lista* entrada_prev;
	t_lista* entrada = lista;
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

t_lista* make_table() {
	t_lista* table = malloc(sizeof(t_lista));
	table->conteudo = NULL;
	table->prox = NULL;
	return table;
}

int get_entrada(t_lista* tabela, t_entrada_simbolo** entrada_retorno, char* chave_buscada) {
	t_lista* entrada = tabela;
	t_entrada_simbolo* simbolo;
	while (entrada != NULL) {
		if (entrada->conteudo == NULL) {
			entrada = entrada->prox;
			continue;
		}
		simbolo = entrada->conteudo;
		if (strcmp(simbolo->chave, chave_buscada) == 0) {
			*entrada_retorno = simbolo;
			return 0;
		}
		else {
			entrada = entrada->prox;
		}
	}
	return -1;
}

int set_tipousuario_tamanho(t_lista* lista){
	int tamanho;
	t_campo* campo; 
	while(lista != NULL) {
		campo = lista->conteudo;
		switch(campo->tipo){
			case NATUREZA_LITERAL_INT:
				tamanho += 4;
				break;
			case NATUREZA_LITERAL_FLOAT:
				tamanho += 8;
				break;
			case NATUREZA_LITERAL_CHAR:
				tamanho += 1;
				break;
			case NATUREZA_LITERAL_STRING:
				tamanho += 1;
				break;
			case NATUREZA_LITERAL_BOOL:
				tamanho += 1;
				break;
		}
		lista = lista->prox;
		struct t_campo* campo = lista->conteudo;
	}
	return tamanho;
}

int get_tipousuario_tamanho(t_lista* tabela, char* chave_buscada){
	t_lista* entrada = tabela;
	t_entrada_simbolo* simbolo;
	while (entrada != NULL) {
		if (entrada->conteudo == NULL) {
			entrada = entrada->prox;
			continue;
		}
		simbolo = entrada->conteudo;
		if ((strcmp(simbolo->chave, chave_buscada) == 0) && simbolo->classe_entrada == T_ENTRADA_TIPO_USUARIO) {
			return (simbolo->tipo_usuario).size_in_bytes;
		}
		else {
			entrada = entrada->prox;
		}
	}
	return -1;	
}

int set_entrada(t_lista* tabela, t_entrada_simbolo* entrada_inserida) {
	t_lista* entrada = tabela;
	t_tipo tipo_aux;
	if (tabela != NULL && tabela->conteudo == NULL) {
		tabela->conteudo = entrada_inserida;
		return 0;
	}
	while(entrada->prox != NULL) {
		entrada = entrada->prox;
	}
	entrada->prox = malloc(sizeof(t_lista));
	entrada->prox->prox = NULL;
	if (entrada_inserida->classe_entrada == T_ENTRADA_VARIAVEL){
		tipo_aux = (entrada_inserida->variavel).tipo;
		switch(tipo_aux.natureza_semantica){
			case NATUREZA_LITERAL_INT:
				entrada_inserida->size_in_bytes = 4 * tipo_aux.tamanho_vetor;
				break;
			case NATUREZA_LITERAL_FLOAT:
				entrada_inserida->size_in_bytes = 8 * tipo_aux.tamanho_vetor;
				break;
			case NATUREZA_LITERAL_CHAR:
				entrada_inserida->size_in_bytes = 1 * tipo_aux.tamanho_vetor;
				break;
			case NATUREZA_LITERAL_STRING:
				entrada_inserida->size_in_bytes = 1 * tipo_aux.tamanho_vetor;
				break;
			case NATUREZA_LITERAL_BOOL:
				entrada_inserida->size_in_bytes = 1 * tipo_aux.tamanho_vetor;
				break;
			case NATUREZA_IDENTIFICADOR:
				entrada_inserida->size_in_bytes = get_tipousuario_tamanho(tabela_global, tipo_aux.user_type_name);
				break;
		}
	}
	else if (entrada_inserida->classe_entrada == T_ENTRADA_TIPO_USUARIO){
		(entrada_inserida->tipo_usuario).size_in_bytes = set_tipousuario_tamanho((entrada_inserida->tipo_usuario).campos);
	}
	entrada->prox->conteudo = entrada_inserida;
	return 0;
}

void print_table(t_lista* tabela)
{
	t_lista* p = tabela;
	printf("Table: ");
	while (p != NULL)
	{
		if (p->conteudo != NULL) {
			//char *chave;
			printf("Chave: %s, ", ((t_entrada_simbolo *)p->conteudo)->chave);
			//int loc_linha;
			printf("Linha: %d, ", ((t_entrada_simbolo *)p->conteudo)->loc_linha);
			//int loc_coluna;
			printf("Coluna: %d, ", ((t_entrada_simbolo *)p->conteudo)->loc_coluna);
			//int size_in_bytes;
			printf("Tamanho: %d, ", ((t_entrada_simbolo *)p->conteudo)->size_in_bytes);
			if (((t_entrada_simbolo *)p->conteudo)->classe_entrada == T_ENTRADA_VARIAVEL){
				switch(((t_entrada_simbolo *)p->conteudo)->variavel.tipo.natureza_semantica){
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


// TESTING:
/*
int print_lista(struct *t_lista lista){
	struct *t_lista entrada_prev;
	struct t_lista entrada = (*lista);
	while(*entrada != NULL){
		printf("Chave is %s\n", (*(entrada->conteudo))->chave);
		entrada = *(entrada->prox);
	}
}

int main(){
	int i;
	char buffer[33];
	struct t_lista tabela;
	for (i = 0; i < 10; i++){
		struct t_entrada_simbolo entr;
		itoa(i, buffer, 10);
		entr->chave = strdup(buffer);
		set_entrada(&tabela, &entr);
	}
	print_lista();
	struct t_entrada_simbolo sought;
	for (i = 0; i < 10; i++){
		itoa(i, buffer, 10);
		get_entrada(&tabela, &sought, buffer);
		printf();
	}
}
*/
