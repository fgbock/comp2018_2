#include "symboltable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int free_lista(struct t_lista* lista){
	struct t_lista* entrada_prev;
	struct t_lista* entrada = lista;
	while(entrada != NULL){
		entrada_prev = entrada;
		entrada = entrada->prox;
		free(entrada_prev->conteudo);
		free(entrada_prev);
	}
}

int free_tabela(struct t_lista* lista){
	struct t_lista* entrada_prev;
	struct t_lista* entrada = lista;
	struct t_entrada_simbolo* simb;
	struct t_entrada_simbolo_funcao aux1;
	struct t_entrada_simbolo_tipousuario aux2;
	while(entrada != NULL){
		entrada_prev = entrada;
		entrada = entrada->prox;
		simb = entrada_prev->conteudo;
		switch (simb->classe_entrada){
			case T_ENTRADA_DECLARACAO_FUNCAO:
				aux1 = simb->funcao;
				free_lista(&(aux1.t_argumentos));
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

int get_entrada(struct t_lista* tabela, struct t_entrada_simbolo* entrada_retorno, char* chave_buscada){
	struct t_lista* entrada = tabela;
	struct t_entrada_simbolo* simbolo;
	while(entrada != NULL){
		simbolo = entrada->conteudo;
		if (strcmp(simbolo->chave,chave_buscada)){
			entrada_retorno = simbolo;
			return 0;
		}
		else{
			entrada = entrada->prox;
		}
	}
	return -1;
}

int set_entrada(struct t_lista* tabela, struct t_entrada_simbolo* entrada_inserida){
	struct t_lista* entrada = tabela;
	struct t_lista* nova_entrada;
	while(entrada->prox != NULL){
		entrada = entrada->prox;
	}
	nova_entrada->conteudo = entrada_inserida;
	entrada->prox = nova_entrada;
	return 0;
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
