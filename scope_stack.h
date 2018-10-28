#ifndef SCOPE_STACK
#define SCOPE_STACK

#include "./symboltable.h"

typedef struct t_scope_aux {
    symbol_table* head;
    struct t_scope_aux* tail;
} t_scope_aux;

typedef struct t_scope_stack {
    t_scope_aux* list;
} t_scope_stack;

int is_declared_in_current_scope(t_scope_stack* stack, char* key);

int scope_stack_get(t_scope_stack* stack, t_entrada_simbolo* out, char* key);

void scope_stack_push_scope(t_scope_stack* stack);

void scope_stack_pop_scope(t_scope_stack* stack);

int scope_stack_set(t_scope_stack* stack, t_entrada_simbolo* entrada);


#endif
