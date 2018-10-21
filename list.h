#ifndef LIST
#define LIST

#include <stdlib.h>

typedef struct t_lista {
	void* conteudo;
	struct t_lista* prox;
} t_lista;

t_lista* create_list();

void add_list(t_lista* list, void* data);

int free_lista(t_lista* list);


#endif
