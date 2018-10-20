#include "semantic.h"

// Generic function to check and set semantic value of arithmetic nodes
void set_arithmetic_semantic(ast_node* node) {

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

    // Errors:
    else if ((lhs_nature == NATUREZA_LITERAL_CHAR || rhs_nature == NATUREZA_LITERAL_CHAR))
    {
        exit(ERR_CHAR_TO_X);
    }

    else if ((lhs_nature == NATUREZA_LITERAL_STRING || rhs_nature == NATUREZA_LITERAL_STRING))
    {
        exit(ERR_STRING_TO_X);
    }

    else if ((lhs_nature == NATUREZA_IDENTIFICADOR || rhs_nature == NATUREZA_IDENTIFICADOR))
    {
        // TODO: Check identifier on symbol table
        exit(ERR_USER_TO_X);
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

    if (can_cast_to_bool(lhs_nature) && can_cast_to_bool(rhs_nature))
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
    if (!can_cast_to_int(expression_nature))
    {
        exit_with_cannot_cast_to_int_error(expression_nature);
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_while_semantic(ast_node* node)
{
    //ASSERT(ast_node->type == NODE_WHILE);
    int expression_nature = node->child[0]->semantic_nature;
    if (!can_cast_to_bool(expression_nature))
    {
        exit_with_cannot_cast_to_bool(expression_nature);
    }
}

void set_do_while_semantic(ast_node* node)
{
    int expression_nature = node->child[0]->semantic_nature;
    if (!can_cast_to_bool(expression_nature))
    {
        exit_with_cannot_cast_to_bool(expression_nature);
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

    if (!can_cast_to_bool(expression_nature))
    {
        exit_with_cannot_cast_to_bool(expression_nature);
    }

    node->semantic_nature = NATUREZA_NULL;
}

void set_unary_bool_semantic(ast_node* node)
{
    int child_nature = node->child[0]->semantic_nature;

    if (can_cast_to_bool(child_nature))
    {
        node->semantic_nature = NATUREZA_LITERAL_BOOL;
    }
    else
    {
        exit_with_cannot_cast_to_bool(child_nature);
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
    if (!can_cast_to_bool(expression_nature))
    {
        exit_with_cannot_cast_to_bool(expression_nature);
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_for_semantic(ast_node* node)
{
    int test_nature = node->child[2]->semantic_nature;
    if (!can_cast_to_bool(test_nature))
    {
        exit_with_cannot_cast_to_bool(test_nature);
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
    if (!can_cast_to_bool(expression_nature)) 
    {
        exit_with_cannot_cast_to_bool(expression_nature);
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_semantic_do_while(ast_node* node)
{
    assert(node->type == NODE_DO_WHILE);
    int expression_nature = node->child[0]->semantic_nature;
    if (!can_cast_to_bool(expression_nature))
    {
        exit_with_cannot_cast_to_bool(expression_nature);
    }
    node->semantic_nature = NATUREZA_NULL;
}

void set_local_var_semantic(ast_node* node)
{
    assert(node->type == NODE_LOCAL_VAR);
    node->semantic_nature = NATUREZA_NULL;
    t_entrada_simbolo_tipousuario user_type;
    //user_type.campos.conteudo
    // TODO: Add in symbol table
}

void set_global_var_semantic(ast_node* node)
{
    assert(node->type == NODE_VAR_GLOBAL);
    // Nome, Static, Tamanho, Tipo
    t_entrada_simbolo table_entry;
    char* var_nome = node->child[0]->string_literal;
    int var_is_static = node->child[1]->type == NODE_STATIC;
    int var_declaracao_tamanho = from_node_size_to_table_size(node->child[2]);
    t_tipo type = from_node_type_to_table_type(node->child[3]);
    type.a_const = 0;
    type.a_static = var_is_static;
    type.tamanho_vetor = var_declaracao_tamanho;

    table_entry.chave = var_nome;
    table_entry.entrada_tipo = type;
    node->semantic_nature = NATUREZA_NULL;
}

void set_new_user_type_semantic(ast_node* node)
{
    assert(node->type == NODE_NEW_TYPE);
    node->semantic_nature = NATUREZA_NULL;
    // TODO: Add in symbol table
}

void set_function_definition_semantic(ast_node* node)
{
    assert(node->type == NODE_FUNCTION_DEFINITION);

    t_entrada_simbolo table_entry;
    t_entrada_simbolo_funcao function_definition;

    int return_is_static = node->child[0]->type == NODE_STATIC;
    char* return_identifier = node->child[2]->string_literal;
    ast_node* argument_list_node = node->child[3];

    t_tipo return_type = from_node_type_to_table_type(node->child[1]);


    table_entry.entrada_tipo = return_type;
    table_entry.funcao = function_definition;


    node->semantic_nature = NATUREZA_NULL;

    
    // TODO: Add in symbol table
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
        return_type.tipo = T_TIPO_PRIMITIVO;
        return_type.tipo_tipo = NATUREZA_LITERAL_INT;
    }
    if (node->type == NODE_FLOAT_TYPE)
    {
        return_type.tipo = T_TIPO_PRIMITIVO;
        return_type.tipo_tipo = NATUREZA_LITERAL_FLOAT;
    }
    if (node->type == NODE_STRING_TYPE)
    {
        return_type.tipo = T_TIPO_PRIMITIVO;
        return_type.tipo_tipo = NATUREZA_LITERAL_STRING;
    }
    if (node->type == NODE_CHAR_TYPE)
    {
        return_type.tipo = T_TIPO_PRIMITIVO;
        return_type.tipo_tipo = NATUREZA_LITERAL_CHAR;
    }
    else
    {
        return_type.tipo = T_TIPO_USUARIO;
        return_type.tipousuario = node->string_literal;
    }
}

int can_cast_to_bool(int semantic_nature)
{
    if (semantic_nature == NATUREZA_LITERAL_BOOL ||
        semantic_nature == NATUREZA_LITERAL_FLOAT ||
        semantic_nature == NATUREZA_LITERAL_INT)
    {
        return 1;
    }
    else if (semantic_nature == NATUREZA_IDENTIFICADOR)
    {
        // TODO: Check on the symbol table
        return 0;
    }
    else
    {
        return 0;
    }
}

int can_cast_to_int(int semantic_nature)
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

void exit_with_cannot_cast_to_int_error(int semantic_nature)
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

void exit_with_cannot_cast_to_bool(int semantic_nature)
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
