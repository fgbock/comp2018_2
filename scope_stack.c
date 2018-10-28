#include "scope_stack.h"

void scope_stack_push_scope(t_scope_stack* stack)
{
    symbol_table* table = make_table();
    t_scope_aux* scope = malloc(sizeof(t_scope_aux));
    scope->tail = stack->list;
    scope->head = table;
    stack->list = scope;
}

int is_declared_in_any_scope(t_scope_stack* stack, char* key)
{
    t_entrada_simbolo* out;
    return scope_stack_get(stack, &out, key) == 0;
}

int is_declared_in_current_scope(t_scope_stack* stack, char* key)
{
    t_entrada_simbolo* result;
    return get_entrada(stack->list->head, &result, key) == 0;
}

void scope_stack_pop_scope(t_scope_stack* stack)
{
    stack->list = stack->list->tail;
}

int scope_stack_set(t_scope_stack* stack, t_entrada_simbolo* entrada)
{
    return set_entrada(stack->list->head, entrada);
}

int scope_stack_get(t_scope_stack* stack, t_entrada_simbolo** out, char* key)
{
    t_scope_aux* current_table_list = stack->list;

    while(current_table_list != NULL) 
    {
        int result = get_entrada(current_table_list->head, out, key);
        if (result == 0) 
        {
            return result;
        }
        current_table_list = current_table_list->tail;
    }
    return -1;
}

