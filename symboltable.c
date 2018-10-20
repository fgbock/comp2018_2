#include "symboltable.h"
#include <stdio.h>
#include <string.h>

int free_lista(struct *t_lista alvo);

int free_tabela();

int get_entrada(struct *t_lista tabela, struct *t_entrada_simbolo entrada_retorno, *char chave_buscada){
	struct t_lista entrada = (*tabela);
	struct t_entrada_simbolo simbolo;
	while(entrada != NULL){
		simbolo = *(entrada->conteudo);
		if (strcmp(simbolo->chave,chave_buscada)){
			entrada_retorno = &(simbolo);
			return 0;
		}
		else{
			entrada = *(entrada->prox);
		}
	}
	return -1;
}

int set_entrada(struct *t_lista tabela, struct *t_entrada_simbolo entrada_inserida){
	struct t_lista entrada = (*tabela);
	while(*(entrada->prox) != NULL){
		entrada = *(entrada->prox);
	}
	entrada->prox = &(entrada_inserida);
};
