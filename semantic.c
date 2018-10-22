#include "semantic.h"

t_lista tabela; 

// Generic function to check and set semantic value of arithmetic nodes
void set_arithmetic_semantic(ast_node* node) {

    ast_node* lhs_node = node->child[0];
    ast_node* rhs_node = node->child[1];
    int lhs_nature = node->child[0]->semantic_nature;
    int rhs_nature = node->child[1]->semantic_nature;
    
    // int, int -> int
    if (lhs_nature == NATUREZA_LITERAL_INT && rhs_nature == NATUREZA_LITERAL_INT)
    {
        node->semantic_nature = NATUREZA_LITERAL_INT;
    }

    // float, float -> float
    else if (lhs_nature == NATUREZA_LITERAL_FLOAT && rhs_nature == NATUREZA_LITERAL_FLOAT)
    {
        node->semantic_nature = NATUREZA_LITERAL_FLOAT;
    }

    // A lot of implicit conversions:
    // int, bool -> int
    else if ((lhs_nature == NATUREZA_LITERAL_BOOL && rhs_nature == NATUREZA_LITERAL_INT) || 
    (lhs_nature == NATUREZA_LITERAL_INT && rhs_nature == NATUREZA_LITERAL_BOOL)) 
    {
        node->semantic_nature = NATUREZA_LITERAL_INT;
    }

    // float, bool -> float
    else if ((lhs_nature == NATUREZA_LITERAL_BOOL && rhs_nature == NATUREZA_LITERAL_FLOAT) || 
    (lhs_nature == NATUREZA_LITERAL_FLOAT && rhs_nature == NATUREZA_LITERAL_BOOL)) 
    {
        node->semantic_nature = NATUREZA_LITERAL_FLOAT;
    }

    // int, float -> float
    else if ((lhs_nature == NATUREZA_LITERAL_INT && rhs_nature == NATUREZA_LITERAL_FLOAT) ||
       (lhs_nature == NATUREZA_LITERAL_FLOAT && rhs_nature == NATUREZA_LITERAL_INT))
    {
        node->semantic_nature = NATUREZA_LITERAL_FLOAT;
    }

    else if ((lhs_nature == NATUREZA_IDENTIFICADOR || rhs_nature == NATUREZA_IDENTIFICADOR))
    {
        // TODO: Check identifier on symbol table
        exit(ERR_USER_TO_X);
    }
    // Errors:
    else if ((lhs_nature == NATUREZA_LITERAL_CHAR || rhs_nature == NATUREZA_LITERAL_CHAR))
    {
        exit(ERR_CHAR_TO_X);
    }

    else if ((lhs_nature == NATUREZA_LITERAL_STRING || rhs_nature == NATUREZA_LITERAL_STRING))
    {
        exit(ERR_STRING_TO_X);
    }
    else
    {
        exit(ERR_WRONG_TYPE);
    }
}

// Generic function to check and set semantic value of boolean nodes
void set_boolean_semantic(ast_node* node)
{
    int lhs_nature = node->child[0]->semantic_nature;
    int rhs_nature = node->child[1]->semantic_nature;

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
        exit(ERR_USER_TO_X);
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
    ASSERT(node->type == NODE_FUNCTION_CALL);
    int conditional_nature = node->child[0]->semantic_nature;
    node->semantic_nature = NATUREZA_NULL;

    //if (can_cast_to_bool(conditional_nature)) {
            // Wrong condition type
      //      exit(ERR_WRONG_TYPE);
    //}

    // TODO:

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
    int input_nature = node->child[0]->semantic_nature;
    if (input_nature != NATUREZA_IDENTIFICADOR)
    {
        // TODO: Check if is in symbol table
        exit(ERR_WRONG_PAR_INPUT);
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
    t_entrada_simbolo* table_entry = malloc(sizeof(t_entrada_simbolo));
    table_entry->classe_entrada = T_ENTRADA_VARIAVEL;
    node->semantic_nature = NATUREZA_NULL;
    set_entrada(&tabela, table_entry);
}

void set_global_var_semantic(ast_node* node)
{
    assert(node->type == NODE_VAR_GLOBAL);
    // Nome, Static, Tamanho, Tipo
    t_entrada_simbolo* table_entry = malloc(sizeof(t_entrada_simbolo));
    char* var_nome = node->child[0]->string_literal;
    int var_is_static = node->child[1]->type == NODE_STATIC;
    int var_declaracao_tamanho = from_node_size_to_table_size(node->child[2]);
    t_tipo type = from_node_type_to_table_type(node->child[3]);
    type.is_const = 0;
    type.is_static = var_is_static;
    type.tamanho_vetor = var_declaracao_tamanho;
    table_entry->classe_entrada = T_ENTRADA_VARIAVEL;
    table_entry->chave = var_nome;
    table_entry->variavel.tipo = type;
    set_entrada(&tabela, table_entry);
    node->semantic_nature = NATUREZA_NULL;
}

void set_new_user_type_semantic(ast_node* node)
{
    assert(node->type == NODE_NEW_TYPE);
    t_entrada_simbolo* table_entry = malloc(sizeof(t_entrada_simbolo));
    table_entry->classe_entrada = T_ENTRADA_TIPO_USUARIO;
    set_entrada(&tabela, table_entry);
    node->semantic_nature = NATUREZA_NULL;
}

void set_function_definition_semantic(ast_node* node)
{
    assert(node->type == NODE_FUNCTION_DEFINITION);
	
    t_entrada_simbolo* table_entry = malloc(sizeof(t_entrada_simbolo));
    t_entrada_simbolo_funcao function_definition;
	
    // Create parameters list
    if (node->child[3]->type == NODE_ARGUMENT_LIST)
    {
    
        // Create root and add first parameter
        function_definition.parameters = create_list();
        t_tipo* parameter_type = malloc(sizeof(t_tipo));
        *parameter_type = from_node_type_to_table_type(node->child[3]->child[0]);
        add_list(function_definition.parameters, parameter_type);
		
        // Add next parameters
        ast_node* argument_list = node->child[3];
        while (argument_list->type == NODE_ARGUMENT_LIST)
        {
        	// Get data from ast node
            ast_node* parameter_ast_node = argument_list->child[0]; // head
            argument_list = argument_list->child[1]; // tail

            // Load parameter type from ast_node and add on the list
            t_tipo* parameter_type = malloc(sizeof(t_tipo));
            *parameter_type = from_node_type_to_table_type(parameter_ast_node);
            
            // Add to parameter list
            add_list(function_definition.parameters, parameter_type);
        }
    }
    

    char* function_identifier = node->child[2]->string_literal;
    t_tipo return_type = from_node_type_to_table_type(node->child[1]);
    return_type.is_const = 0;
    return_type.is_static = node->child[0]->type == NODE_STATIC;
    table_entry->chave = function_identifier;
    table_entry->classe_entrada = T_ENTRADA_DECLARACAO_FUNCAO;
    table_entry->funcao.return_type = return_type;
    table_entry->funcao = function_definition;
    set_entrada(&tabela, table_entry);

    node->semantic_nature = NATUREZA_NULL;
}

void set_identifier_semantic(ast_node* node)
{

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
        get_entrada(&tabela, entrada, node->string_literal);
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
        get_entrada(&tabela, entrada, node->string_literal);
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
