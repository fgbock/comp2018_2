#include "list.h"

t_lista* create_list()
{
    t_lista* new_list = malloc(sizeof(t_lista));
    new_list->conteudo = NULL;
    new_list->prox = NULL;
    return new_list;
}

void add_list(t_lista* list, void* data)
{
	t_lista* entrada_prev;
	t_lista* entrada = list;
    while(entrada != NULL)
    {
		entrada_prev = entrada;
		entrada = entrada->prox;
    }
    t_lista* new_node = malloc(sizeof(t_lista));
    new_node->conteudo = data;
    new_node->prox = NULL;
    entrada_prev->prox = new_node;
}

int free_lista(t_lista* list) {
	t_lista* entrada_prev;
	t_lista* entrada = list;
	while(entrada != NULL) 
	{
		entrada_prev = entrada;
		entrada = entrada->prox;
		free(entrada_prev->conteudo);
		free(entrada_prev);
	}
}

