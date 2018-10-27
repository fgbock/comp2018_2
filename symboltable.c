#include "symboltable.h"


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
				free_lista(&(aux1.parameters));
				free(simb);
				free(entrada_prev);
				break;
			case T_ENTRADA_TIPO_USUARIO:
				aux2 = simb->tipo_usuario;
				free_lista(&(aux2.campos));
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

int get_entrada(t_lista* tabela, t_entrada_simbolo* entrada_retorno, char* chave_buscada) {
	t_lista* entrada = tabela;
	t_entrada_simbolo* simbolo;
	while (entrada != NULL) {
		if (entrada->conteudo == NULL) {
			entrada = entrada->prox;
			continue;
		}
		simbolo = entrada->conteudo;
		if (strcmp(simbolo->chave, chave_buscada) == 0) {
			entrada_retorno = simbolo;
			return 0;
		}
		else {
			entrada = entrada->prox;
		}
	}
	return -1;
}

int set_entrada(t_lista* tabela, t_entrada_simbolo* entrada_inserida) {
	t_lista* entrada = tabela;
	if (tabela != NULL && tabela->conteudo == NULL) {
		tabela->conteudo = entrada_inserida;
		return 0;
	}

	while(entrada->prox != NULL) {
		entrada = entrada->prox;
	}
	entrada->prox = malloc(sizeof(t_lista));
	entrada->prox->prox = NULL;
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
			printf("%s, ", ((t_entrada_simbolo *)p->conteudo)->chave);
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
