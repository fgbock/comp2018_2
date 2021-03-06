#include "semantic.h"


// Generic function to check and set semantic value of arithmetic nodes
void set_arithmetic_semantic(ast_node* node) {

    ast_node* lhs_node = node->child[0];
    ast_node* rhs_node = node->child[1];
    int lhs_nature = node->child[0]->semantic_nature;
    int rhs_nature = node->child[1]->semantic_nature;
    return;
    
    // int, int -> int
    if (lhs_nature == NATUREZA_LITERAL_INT && rhs_nature == NATUREZA_LITERAL_INT)
    {
        node->semantic_nature = NATUREZA_LITERAL_INT;
        return;
    }

    // float, float -> float
    else if (lhs_nature == NATUREZA_LITERAL_FLOAT && rhs_nature == NATUREZA_LITERAL_FLOAT)
    {
        node->semantic_nature = NATUREZA_LITERAL_FLOAT;
        return;
    }

    // A lot of implicit conversions:
    // int, bool -> int
    else if ((lhs_nature == NATUREZA_LITERAL_BOOL && rhs_nature == NATUREZA_LITERAL_INT) || 
    (lhs_nature == NATUREZA_LITERAL_INT && rhs_nature == NATUREZA_LITERAL_BOOL)) 
    {
        node->semantic_nature = NATUREZA_LITERAL_INT;
        return;
    }

    // float, bool -> float
    else if ((lhs_nature == NATUREZA_LITERAL_BOOL && rhs_nature == NATUREZA_LITERAL_FLOAT) || 
    (lhs_nature == NATUREZA_LITERAL_FLOAT && rhs_nature == NATUREZA_LITERAL_BOOL)) 
    {
        node->semantic_nature = NATUREZA_LITERAL_FLOAT;
        return;
    }

    // int, float -> float
    else if ((lhs_nature == NATUREZA_LITERAL_INT && rhs_nature == NATUREZA_LITERAL_FLOAT) ||
       (lhs_nature == NATUREZA_LITERAL_FLOAT && rhs_nature == NATUREZA_LITERAL_INT))
    {
        node->semantic_nature = NATUREZA_LITERAL_FLOAT;
        return;
    }

    if (lhs_nature == NATUREZA_IDENTIFICADOR)
    {
        check_arithmetic_identifier_semantic(lhs_node);
        return;
    }
    if (rhs_nature == NATUREZA_IDENTIFICADOR)
    {
        check_arithmetic_identifier_semantic(rhs_node);
        return;
    }

    // Errors:
    if ((lhs_nature == NATUREZA_LITERAL_CHAR || rhs_nature == NATUREZA_LITERAL_CHAR))
    {
        exit(ERR_CHAR_TO_X);
    }

    if ((lhs_nature == NATUREZA_LITERAL_STRING || rhs_nature == NATUREZA_LITERAL_STRING))
    {
        exit(ERR_STRING_TO_X);
    }
    printf("Error: Wrong type in expression\n");
    exit(ERR_WRONG_TYPE);
    
}

void set_node_parenthesis(ast_node* node)
{
    node->semantic_nature = node->child[0]->semantic_nature;
}

int check_arithmetic_identifier_semantic(ast_node* node)
{
    assert(node->type == NODE_VAR_ACCESS);
    char* identifier = node->child[0]->string_literal;
    t_entrada_simbolo* symbol;

    if (scope_stack_get(&scope_stack, &symbol, identifier) != 0) {
        exit(ERR_UNDECLARED);
    }
    if (symbol->classe_entrada != T_ENTRADA_VARIAVEL) {
        exit(ERR_VARIABLE);
    }
    if (symbol->variavel.tipo.natureza_semantica == NATUREZA_LITERAL_CHAR) {
        exit(ERR_CHAR_TO_X);
    }
    if (symbol->variavel.tipo.natureza_semantica == NATUREZA_LITERAL_STRING) {
        exit(ERR_STRING_TO_X);
    }
}

// Generic function to check and set semantic value of boolean nodes
void set_boolean_semantic(ast_node* node)
{
    int lhs_nature = node->child[0]->semantic_nature;
    int rhs_nature = node->child[1]->semantic_nature;
    return;

    if (can_cast_to_bool(node->child[0]) && can_cast_to_bool(node->child[1]))
    {
        node->semantic_nature = NATUREZA_LITERAL_BOOL;
    }
    else if (lhs_nature == NATUREZA_LITERAL_CHAR || rhs_nature == NATUREZA_LITERAL_CHAR)
    {
        exit(ERR_CHAR_TO_X);
    }
    else if (lhs_nature == NATUREZA_LITERAL_STRING || rhs_nature == NATUREZA_LITERAL_STRING)
    {
        exit(ERR_STRING_TO_X);
    }
    else if (lhs_nature == NATUREZA_IDENTIFICADOR || rhs_nature == NATUREZA_IDENTIFICADOR)
    {
        // TODO: Check identifier on symbol table
        //exit(ERR_USER_TO_X);
        return;
    }
    else
    {
        exit(ERR_WRONG_TYPE);
    }
}

void set_lit_int_semantic(ast_node* node)
{
    node->semantic_nature = NATUREZA_LITERAL_INT;
}

void set_lit_string_semantic(ast_node* node)
{
    node->semantic_nature = NATUREZA_LITERAL_STRING;
}

void set_lit_float_semantic(ast_node* node)
{
    node->semantic_nature = NATUREZA_LITERAL_FLOAT;
}

void set_lit_bool_semantic(ast_node* node)
{
    node->semantic_nature = NATUREZA_LITERAL_BOOL;
}

void set_lit_char_semantic(ast_node* node)
{
    node->semantic_nature = NATUREZA_LITERAL_CHAR;
}

void set_function_call_semantic(ast_node* node)
{
    assert(node->type == NODE_FUNCTION_CALL);
    char* function_identifier = node->child[0]->string_literal;

    if (function_identifier != NULL) 
    {
        t_entrada_simbolo* result;
        if (scope_stack_get(&scope_stack, &result, function_identifier) == -1)
        {
            exit(ERR_UNDECLARED);
        }
    }
}

void set_switch_semantic(ast_node* node)
{
    int expression_nature = node->child[0]->semantic_nature;
    if (!can_cast_to_int(node->child[0]))
    {
        exit_with_cannot_cast_to_error(expression_nature);
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_while_semantic(ast_node* node)
{
    assert(node->type == NODE_WHILE);
    int expression_nature = node->child[0]->semantic_nature;
    if (!can_cast_to_bool(node->child[0]))
    {
        exit_with_cannot_cast_to_error(expression_nature);
    }
}

void set_do_while_semantic(ast_node* node)
{
    int expression_nature = node->child[0]->semantic_nature;
    if (!can_cast_to_bool(node->child[0]))
    {
        exit_with_cannot_cast_to_error(expression_nature);
    }
}

void set_return_nature(ast_node* node)
{
    // TODO: Check function type
    node->semantic_nature = NATUREZA_NULL;
}

void set_break_nature(ast_node* node)
{
    node->semantic_nature = NATUREZA_NULL;
}

void set_continue_nature(ast_node* node)
{
    node->semantic_nature = NATUREZA_NULL;
}

void set_case_nature(ast_node* node)
{
    int value_nature = node->child[0]->semantic_nature;
    if (value_nature != NATUREZA_LITERAL_INT)
    {
        exit(ERR_WRONG_TYPE);
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_ternary_expression_semantic(ast_node* node)
{
    int expression_nature = node->child[0]->semantic_nature;
    int then_nature = node->child[1]->semantic_nature;
    int else_nature = node->child[2]->semantic_nature;

    if (!can_cast_to_bool(node->child[0]))
    {
        exit_with_cannot_cast_to_error(expression_nature);
    }

    node->semantic_nature = NATUREZA_NULL;
}

void set_unary_bool_semantic(ast_node* node)
{
    int child_nature = node->child[0]->semantic_nature;

    if (can_cast_to_bool(node->child[0]))
    {
        node->semantic_nature = NATUREZA_LITERAL_BOOL;
    }
    else
    {
        exit_with_cannot_cast_to_error(child_nature);
    }
}


void set_unknown_semantic(ast_node* node)
{
    if (node->type == NODE_ASSIGNMENT)
    {
        set_assignment_semantic(node);
    }
    if (node->type == NODE_LOCAL_VAR)
    {
        set_local_var_semantic(node);
    }
}

void set_assignment_semantic(ast_node* node)
{
    assert(node->type == NODE_ASSIGNMENT);
    
    char* lhs_name = node->child[1]->string_literal;
    if (lhs_name != NULL) 
    {
        t_entrada_simbolo* result;
        if (scope_stack_get(&scope_stack, &result, lhs_name) == -1)
        {
            exit(ERR_UNDECLARED);
        }
    }
    
}

void set_unary_number_semantic(ast_node* node)
{
    int child_nature = node->child[0]->semantic_nature;

    // int -> int
    if (child_nature == NATUREZA_LITERAL_INT)
    {
        node->semantic_nature = NATUREZA_LITERAL_INT;
    }
    // float -> float
    else if (child_nature == NATUREZA_LITERAL_FLOAT)
    {
        node->semantic_nature = NATUREZA_LITERAL_FLOAT;
    }
    // bool -> int
    else if (child_nature == NATUREZA_LITERAL_BOOL)
    {
        node->semantic_nature = NATUREZA_LITERAL_INT;
    }
    else
    {
        exit(ERR_WRONG_TYPE);
    }
}

void set_if_semantic(ast_node* node)
{
    assert(node->type == NODE_IF);
    int expression_nature = node->child[0]->semantic_nature;
    if (!can_cast_to_bool(node->child[0]))
    {
        exit_with_cannot_cast_to_error(expression_nature);
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_for_semantic(ast_node* node)
{
    int test_nature = node->child[2]->semantic_nature;
    if (!can_cast_to_bool(node->child[2]))
    {
        exit_with_cannot_cast_to_error(test_nature);
    }
}

void set_input_semantic(ast_node* node)
{
    assert(node->type == NODE_INPUT);
    int input_nature = node->child[0]->semantic_nature;
    ast_node* rhs = node->child[0];

    if (rhs->type != NODE_VAR_ACCESS)
    {
        printf("Error: input only accepts identifiers\n");
        exit(ERR_WRONG_PAR_INPUT);
    }
    else
    {
        t_entrada_simbolo* out;
        char* identifier = rhs->child[0]->string_literal;
        if (is_declared_in_any_scope(&scope_stack, identifier) == 0)
        {
            printf("Error: Undeclared identifier after input\n");
            exit(ERR_WRONG_PAR_INPUT);
        }
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_foreach_semantic(ast_node* node)
{
    node->semantic_nature = NATUREZA_NULL;
}

void set_semantic_while(ast_node* node)
{
    assert(node->type == NODE_WHILE);
    int expression_nature = node->child[0]->semantic_nature;
    if (!can_cast_to_bool(node->child[0])) 
    {
        exit_with_cannot_cast_to_error(expression_nature);
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_semantic_do_while(ast_node* node)
{
    assert(node->type == NODE_DO_WHILE);
    int expression_nature = node->child[0]->semantic_nature;
    if (!can_cast_to_bool(node->child[0]))
    {
        exit_with_cannot_cast_to_error(expression_nature);
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_local_var_semantic(ast_node* node)
{
    assert(node->type == NODE_LOCAL_VAR);
    char* var_nome = node->child[0]->string_literal;
    // Check if already declared
    if (var_nome != NULL && is_declared_in_current_scope(&scope_stack, var_nome))
    {
        printf("Error: Local variable %s is already declared in this scope\n", var_nome);
        exit(ERR_DECLARED);
    }

    // Add to symbol table
    t_entrada_simbolo* table_entry = malloc(sizeof(t_entrada_simbolo));
    table_entry->classe_entrada = T_ENTRADA_VARIAVEL;
    table_entry->chave = var_nome;

    t_tipo type = from_node_type_to_table_type(node->child[1]);
    type.tamanho_vetor = -1; // TODO:

    table_entry->variavel.tipo = type;
    scope_stack_set(&scope_stack, table_entry);
    node->semantic_nature = NATUREZA_NULL;
}

void set_global_var_semantic(ast_node* node)
{
    assert(node->type == NODE_VAR_GLOBAL);
    // Nome, Static, Tamanho, Tipo
    char* var_nome = node->child[0]->string_literal;
    int var_is_static = node->child[1]->type == NODE_STATIC;
    int var_declaracao_tamanho = from_node_size_to_table_size(node->child[2]);
    t_tipo type = from_node_type_to_table_type(node->child[3]);
    type.is_const = 0;
    type.is_static = var_is_static;
    type.tamanho_vetor = var_declaracao_tamanho;

    // Check if already declared
    if (var_nome != NULL)
    {
        if (is_declared_in_current_scope(&scope_stack, var_nome))
        {
            printf("Erro: Global variable %s already declared in this scope\n", var_nome);            
            exit(ERR_DECLARED);
        }
    }

    // Add to symbol table
    t_entrada_simbolo* table_entry = malloc(sizeof(t_entrada_simbolo));        
    table_entry->classe_entrada = T_ENTRADA_VARIAVEL;
    table_entry->chave = var_nome;
    table_entry->variavel.tipo = type;
    scope_stack_set(&scope_stack, table_entry);
    node->semantic_nature = NATUREZA_NULL;
}

void set_new_user_type_semantic(ast_node* node)
{
    assert(node->type == NODE_NEW_TYPE);
    t_entrada_simbolo* table_entry = malloc(sizeof(t_entrada_simbolo));
    table_entry->classe_entrada = T_ENTRADA_TIPO_USUARIO;
    scope_stack_set(&scope_stack, table_entry);
    node->semantic_nature = NATUREZA_NULL;
}

void set_function_signature_semantic(ast_node* node)
{
    scope_stack_push_scope(&scope_stack, 0);
}

void set_function_definition_semantic(ast_node* node)
{
    assert(node->type == NODE_FUNCTION_DEFINITION);

    //scope_stack_pop_scope(&scope_stack);

    ast_node* function_header_node = node->child[0];
    char* function_identifier = function_header_node->child[2]->string_literal;

    // Check if already declared
    if (function_identifier != NULL)
    {
        if (is_declared_in_current_scope(&scope_stack, function_identifier))
        {
            exit(ERR_DECLARED);
        }
    }
	
    t_entrada_simbolo* table_entry = malloc(sizeof(t_entrada_simbolo));
    t_entrada_simbolo_funcao function_definition;
    // Create parameters list 
    if (function_header_node->child[3]->type == NODE_ARGUMENT_LIST)
    {
        // Create root and add first parameter
        t_entrada_simbolo* function_parameter_entry = malloc(sizeof(t_entrada_simbolo));

        // function_definition.parameters = create_list();
        // t_argumento* arg = malloc(sizeof(t_argumento));
        // arg->identificador = function_header_node->child[3]->child[0]->child[3]->string_literal;
        // add_list(function_definition.parameters, arg);

        function_parameter_entry->classe_entrada = T_ENTRADA_VARIAVEL;
        function_parameter_entry->chave = function_header_node->child[3]->child[0]->child[3]->string_literal;
        scope_stack_set(&scope_stack, function_parameter_entry);

        // Add next parameters
        ast_node* argument_list = function_header_node->child[3]->child[1];
        while (argument_list->type == NODE_ARGUMENT_LIST)
        {
            function_parameter_entry = malloc(sizeof(t_entrada_simbolo));
            function_parameter_entry->classe_entrada = T_ENTRADA_VARIAVEL;
            function_parameter_entry->chave = function_header_node->child[3]->child[0]->child[3]->string_literal;
            scope_stack_set(&scope_stack, function_parameter_entry);    
            // Load parameter type from ast_node
            // t_argumento* parameter_type = malloc(sizeof(t_argumento));
            // parameter_type->identificador = argument_list->child[0]->child[3]->string_literal;

            // Add to parameter list
            // add_list(function_definition.parameters, parameter_type);
            
            // Next
	        argument_list = argument_list->child[1];
        }
    }
    

    t_tipo return_type = from_node_type_to_table_type(function_header_node->child[1]);
    return_type.is_const = 0;
    return_type.is_static = function_header_node->child[0]->type == NODE_STATIC;
    table_entry->chave = function_identifier;
    table_entry->classe_entrada = T_ENTRADA_DECLARACAO_FUNCAO;
    
    table_entry->funcao = function_definition;
    table_entry->funcao.return_type = return_type;
    
    scope_stack_set(&scope_stack, table_entry);
    
    node->semantic_nature = NATUREZA_NULL;
}

void set_identifier_semantic(ast_node* node)
{
    node->semantic_nature = NATUREZA_IDENTIFICADOR;
}

// Aux

int from_node_size_to_table_size(ast_node* node)
{
    if (node->type == NODE_SIZE)
    {
        return node->int_literal;
    }
    else
    {
        return -1;
    }
}

t_tipo from_node_type_to_table_type(ast_node* node)
{
    t_tipo return_type;
    if (node->type == NODE_INT_TYPE)
    {
        return_type.natureza_semantica = NATUREZA_LITERAL_INT;
    }
    else if (node->type == NODE_FLOAT_TYPE)
    {
        return_type.natureza_semantica = NATUREZA_LITERAL_FLOAT;
    }
    else if (node->type == NODE_STRING_TYPE)
    {
        return_type.natureza_semantica = NATUREZA_LITERAL_STRING;
    }
    else if (node->type == NODE_CHAR_TYPE)
    {
        return_type.natureza_semantica = NATUREZA_LITERAL_CHAR;
    }
    else if (node->type == NODE_IDENTIFIER)
    {
        return_type.natureza_semantica = NATUREZA_IDENTIFICADOR;
        return_type.user_type_name = node->string_literal;
    }
    else
    {
        // error
    }
    return return_type;
}

int can_cast_from_natureza_to_bool(int semantic_nature)
{
    if (semantic_nature == NATUREZA_LITERAL_BOOL ||
        semantic_nature == NATUREZA_LITERAL_FLOAT ||
        semantic_nature == NATUREZA_LITERAL_INT)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int can_cast_to_bool(ast_node* node)
{
    int semantic_nature = node->semantic_nature;
    // Se o tipo semantico do nodo puder ser convertido para um booleano
    if (can_cast_from_natureza_to_bool(semantic_nature))
    {
        return 1;
    }
    else if (semantic_nature == NATUREZA_IDENTIFICADOR)
    {
        t_entrada_simbolo* entrada;
        scope_stack_get(&scope_stack, &entrada, node->string_literal);
        // Se o identificador for de uma variavel que pode ser convertida para um booleano
        if (entrada->classe_entrada == T_ENTRADA_VARIAVEL && 
            can_cast_from_natureza_to_bool(entrada->variavel.tipo.natureza_semantica))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int can_cast_from_natureza_to_int(int semantic_nature)
{
    if (semantic_nature == NATUREZA_LITERAL_BOOL ||
        semantic_nature == NATUREZA_LITERAL_FLOAT ||
        semantic_nature == NATUREZA_LITERAL_INT)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int can_cast_to_int(ast_node* node)
{
    int semantic_nature = node->semantic_nature;
    // Se o tipo semantico do nodo puder ser convertido para um int
    if (can_cast_from_natureza_to_int(semantic_nature))
    {
        return 1;
    }
    else if (semantic_nature == NATUREZA_IDENTIFICADOR)
    {
        // Checa o identificador na tabela de simbolos
        t_entrada_simbolo* entrada;
        scope_stack_get(&scope_stack, &entrada, node->string_literal);
        if (entrada == NULL)
        {
            return 0;
        }
        else
        {
            // Se o identificador for de uma variavel que pode ser convertida para um int
            if (entrada->classe_entrada == T_ENTRADA_VARIAVEL && 
                can_cast_from_natureza_to_int(entrada->variavel.tipo.natureza_semantica))
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}

void set_program_semantic()
{
    scope_stack_push_scope(&scope_stack, 0);
}

void exit_with_cannot_cast_to_error(int semantic_nature)
{
    if (semantic_nature == NATUREZA_LITERAL_CHAR)
    {
        exit(ERR_CHAR_TO_X);
    }
    else if (semantic_nature == NATUREZA_LITERAL_STRING)
    {
        exit(ERR_STRING_TO_X);
    }
    else if (semantic_nature == NATUREZA_IDENTIFICADOR)
    {
        // Assumes identifier cannot cast to int
        exit(ERR_USER_TO_X);
    }
}
