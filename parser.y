%{

#include "arvore.h"

int yylex(void);
void yyerror (char const *s);

extern void *arvore;

#define BINARY_EXP(X) $$ = make_node(X); $$->child[0] = $1; $$->child[1] = $3; \

%}

%union {
   ast_node* node;
   int valor_lexico_int;
   int valor_lexico_bool;
   float valor_lexico_float;
   char valor_lexico_char;
   char* valor_lexico_string;
}

%define parse.error verbose

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_CONST
%token TK_PR_STATIC
%token TK_PR_FOREACH
%token TK_PR_FOR
%token TK_PR_SWITCH
%token TK_PR_CASE
%token TK_PR_BREAK
%token TK_PR_CONTINUE
%token TK_PR_CLASS
%token TK_PR_PRIVATE
%token TK_PR_PUBLIC
%token TK_PR_PROTECTED
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_SL
%token TK_OC_SR
%token TK_OC_FORWARD_PIPE
%token TK_OC_BASH_PIPE
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_LIT_STRING
%token TK_IDENTIFICADOR
%token TOKEN_ERRO


%type<node> programa programa_aux declaracao_funcao_usertype_e_var_global declaracao_variavel_global declaracao_novo_tipo declaracao_funcao expressao acesso_variavel chamada_funcao literal comando_if comando_else_opcional bloco_comandos argumento argumento_aux optional_pipe_command comando_pipe pipe tipo_variavel_primitiva tipo_variavel_usuario tipo_variavel opcional_encapsulamento declaracao_novo_tipo_propriedade declaracao_novo_tipo_propriedades identificador declaracao_tamanho primeiro_param_funcao  declaracao_parametro_unico_funcao param_funcao um_comando comando_simples comando_while comando_do_while comando_switch comando_case comando_foreach comando_for comando_continue comando_break comando_return output input declaracao_variavel_local_ou_atribuicao_ou_shift opcional_acesso_vetor opcional_acesso_propriedade lista_expressoes atribuicao declaracao_variavel_local_ou_atribuicao_ou_shift_id declaracao_variavel_local_ou_atribuicao_id_parametro acesso_propriedade declaracao_variavel_local declaracao_variavel_local_const declaracao_variavel_local_static opcional_declaracao_valor comandos_dentro_for comandos_dentro_for_aux function_body;

%left '+' '-'
%left '*' '/' '%'
%left TK_OC_NE TK_OC_EQ TK_OC_GE TK_OC_LE '<' '>'
%left TK_OC_OR TK_OC_AND
%left '!''&' '|' '^' '#'
%left '(' ')' ':' '?'
%left '='
%right  TK_PR_THEN TK_PR_ELSE 
%nonassoc '[' ']' ';' ','
%%



programa: programa_aux { arvore = make_node(NODE_PROGRAM); ((ast_node*)arvore)->child[0] = $1; };


programa_aux: declaracao_funcao_usertype_e_var_global programa_aux { $$ = make_node(NODE_PROGRAM); $$->child[0] = $1; $$->child[1] = $2; };
programa_aux: declaracao_variavel_global              programa_aux { $$ = make_node(NODE_PROGRAM); $$->child[0] = $1; $$->child[1] = $2; };
programa_aux: declaracao_novo_tipo                    programa_aux { $$ = make_node(NODE_PROGRAM); $$->child[0] = $1; $$->child[1] = $2; };
programa_aux: declaracao_funcao                       programa_aux { $$ = make_node(NODE_PROGRAM); $$->child[0] = $1; $$->child[1] = $2; };
programa_aux: %empty {$$ = NULL;};

/* opcionais & auxiliares */
literal: TK_LIT_INT    { $$ = make_node(NODE_INT_LITERAL);    $$->int_literal = yylval.valor_lexico_int; };
literal: TK_LIT_FLOAT  { $$ = make_node(NODE_FLOAT_LITERAL);  $$->float_literal = yylval.valor_lexico_float; };
literal: TK_LIT_FALSE  { $$ = make_node(NODE_BOOL_LITERAL);   $$->bool_literal = 0; };
literal: TK_LIT_TRUE   { $$ = make_node(NODE_BOOL_LITERAL);   $$->bool_literal = 1; };
literal: TK_LIT_CHAR   { $$ = make_node(NODE_CHAR_LITERAL);   $$->char_literal = yylval.valor_lexico_char; };
literal: TK_LIT_STRING { $$ = make_node(NODE_STRING_LITERAL); $$->string_literal = yylval.valor_lexico_string; };
//opcional_const: %empty;
//opcional_const: TK_PR_CONST;
opcional_acesso_vetor: %empty            { $$ = make_node(NODE_EMPTY); };
opcional_acesso_vetor: '[' expressao ']' { $$ = make_node(NODE_VECTOR_ACCESS); $$->child[0] = $2; };
opcional_declaracao_valor: %empty                    { $$ = make_node(NODE_EMPTY); };
opcional_declaracao_valor: TK_OC_LE identificador    { $$ = $2; };
opcional_declaracao_valor: TK_OC_LE literal          { $$ = $2; };
opcional_acesso_propriedade: %empty               { $$ = make_node(NODE_EMPTY); };
opcional_acesso_propriedade: '$' TK_IDENTIFICADOR { $$ = make_node(NODE_PROPERTY_ACCESS); $$->string_literal = yylval.valor_lexico_string; };
acesso_propriedade: '$' TK_IDENTIFICADOR { $$ = make_node(NODE_PROPERTY_ACCESS); $$->string_literal = yylval.valor_lexico_string; };
acesso_variavel: identificador opcional_acesso_propriedade opcional_acesso_vetor { $$ = make_node(NODE_VAR_ACCESS); $$->child[0] = $1; $$->child[1] = $2; $$->child[2] = $3; };

/* tipo de variável */
tipo_variavel_primitiva: TK_PR_INT         { $$ = make_node(NODE_INT_TYPE);    };
tipo_variavel_primitiva: TK_PR_FLOAT       { $$ = make_node(NODE_FLOAT_TYPE);  };
tipo_variavel_primitiva: TK_PR_CHAR        { $$ = make_node(NODE_CHAR_TYPE);   };
tipo_variavel_primitiva: TK_PR_BOOL        { $$ = make_node(NODE_BOOL_TYPE);   };
tipo_variavel_primitiva: TK_PR_STRING      { $$ = make_node(NODE_STRING_TYPE); };
tipo_variavel_usuario:   identificador     { $$ = $1; };
tipo_variavel: tipo_variavel_usuario       { $$ = $1; };
tipo_variavel: tipo_variavel_primitiva     { $$ = $1; };


/* Expressões */

/* Unarias */
expressao: '+' expressao { $$ = make_node(NODE_POSITIVE);      $$->child[0] = $2; };
expressao: '-' expressao { $$ = make_node(NODE_MINUS);         $$->child[0] = $2; };
expressao: '!' expressao { $$ = make_node(NODE_NOT);           $$->child[0] = $2; };
expressao: '&' expressao { $$ = make_node(NODE_DEREF_POINTER); $$->child[0] = $2; };
expressao: '*' expressao { $$ = make_node(NODE_DEREF_VALUE);   $$->child[0] = $2; };
expressao: '#' expressao { $$ = make_node(NODE_ACCESS);        $$->child[0] = $2; };
expressao: '?' expressao { $$ = make_node(NODE_BOOL_EVAL);     $$->child[0] = $2; };

/* Binarias */
expressao: expressao '+' expressao { $$ = make_node(NODE_ADD);         $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao '-' expressao { $$ = make_node(NODE_SUB);         $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao '*' expressao { $$ = make_node(NODE_MUL);         $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao '/' expressao { $$ = make_node(NODE_DIV);         $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao '%' expressao { $$ = make_node(NODE_MOD);         $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao '|' expressao { $$ = make_node(NODE_BITWISE_OR);  $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao '&' expressao { $$ = make_node(NODE_BITWISE_AND); $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao '^' expressao { $$ = make_node(NODE_EXP);         $$->child[0] = $1; $$->child[1] = $3; };

/* Relacionais */
expressao: expressao '<'       expressao { $$ = make_node(NODE_LESS);       $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao '>'       expressao { $$ = make_node(NODE_GREATER);    $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao TK_OC_LE  expressao { $$ = make_node(NODE_LE);         $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao TK_OC_GE  expressao { $$ = make_node(NODE_GE);         $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao TK_OC_EQ  expressao { $$ = make_node(NODE_EQ);         $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao TK_OC_NE  expressao { $$ = make_node(NODE_NE);         $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao TK_OC_AND expressao { $$ = make_node(NODE_AND);        $$->child[0] = $1; $$->child[1] = $3; };
expressao: expressao TK_OC_OR  expressao { $$ = make_node(NODE_OR);         $$->child[0] = $1; $$->child[1] = $3; };

/* Outros */
expressao: literal           { $$ = $1; };
expressao: acesso_variavel   { $$ = $1; };
expressao: chamada_funcao    { $$ = $1; };
expressao: '(' expressao ')' { $$ = make_node(NODE_BRACKET_EXPR); $$->child[0] = $2; };
expressao: expressao '?' expressao ':' expressao { $$ = make_node(NODE_TERNARY); $$->child[0] = $1; $$->child[1] = $3; $$->child[2] = $5; };

/* declarações de tipo */
declaracao_novo_tipo: TK_PR_CLASS identificador '[' declaracao_novo_tipo_propriedade declaracao_novo_tipo_propriedades ']'';' {$$ = make_node(NODE_NEW_TYPE); $$->child[0] = make_node(NODE_CLASS); $$->child[1] = $2; $$->child[2] = $4; $$->child[3] = $5;};
declaracao_novo_tipo_propriedades: ':' declaracao_novo_tipo_propriedade declaracao_novo_tipo_propriedades {$$ = make_node(NODE_NEW_TYPE_PROPERTY_LIST); $$->child[0] = $2; $$->child[1] = $3;};
declaracao_novo_tipo_propriedades: %empty {$$ = make_node(NODE_EMPTY);};
declaracao_novo_tipo_propriedade: opcional_encapsulamento tipo_variavel_primitiva identificador {$$ = make_node(NODE_NEW_TYPE_PROPERTY); $$->child[0] = $1; $$->child[1] = $2; $$->child[2] = $3;};
opcional_encapsulamento: %empty          {$$ = make_node(NODE_EMPTY);};
opcional_encapsulamento: TK_PR_PRIVATE   {$$ = make_node(NODE_PRIVATE);};
opcional_encapsulamento: TK_PR_PUBLIC    {$$ = make_node(NODE_PUBLIC);};
opcional_encapsulamento: TK_PR_PROTECTED {$$ = make_node(NODE_PROTECTED);};

/* fix de s/r para declarações de global e função */


//funcao: '(' primeiro_param_funcao ')' bloco_comandos;

/* Auxiliares */
declaracao_tamanho: '[' TK_LIT_INT ']'                                                     { $$ = make_node(NODE_SIZE);       $$->int_literal = yylval.valor_lexico_int; };
identificador: TK_IDENTIFICADOR                                                            { $$ = make_node(NODE_IDENTIFIER); $$->string_literal = yylval.valor_lexico_string; };

/* declaração de variável global */
declaracao_funcao_usertype_e_var_global: identificador identificador ';'                    { $$ = make_node(NODE_VAR_GLOBAL); $$->child[0] = $1; $$->child[1] = $2;                                                                               };
declaracao_variavel_global: identificador TK_PR_STATIC tipo_variavel ';'                    { $$ = make_node(NODE_VAR_GLOBAL); $$->child[0] = $1; $$->child[1] = make_node(NODE_STATIC); $$->child[2] = $3;                                        };
declaracao_variavel_global: identificador declaracao_tamanho tipo_variavel ';'              { $$ = make_node(NODE_VAR_GLOBAL); $$->child[0] = $1; $$->child[1] = $2;                     $$->child[2] = $3;                                        };
declaracao_variavel_global: identificador declaracao_tamanho TK_PR_STATIC tipo_variavel ';' { $$ = make_node(NODE_VAR_GLOBAL); $$->child[0] = $1; $$->child[1] = $2;                     $$->child[2] = make_node(NODE_STATIC); $$->child[3] = $4; };
declaracao_variavel_global: identificador tipo_variavel_primitiva ';'                       { $$ = make_node(NODE_VAR_GLOBAL); $$->child[0] = $1; $$->child[1] = $2;                                                                               };

/* declaração de função */
function_body: '{' comando_simples '}' { $$ = make_node(NODE_FUNCTION_BODY); $$->child[0] = $2; ; };
//bloco_comandos: '{' comando_simples '}' { $$ = make_node(NODE_COMMAND_BLOCK); $$->child[0] = $2;  };

declaracao_funcao_usertype_e_var_global:              identificador           identificador '(' primeiro_param_funcao ')' function_body { $$ = make_node(NODE_FUNCTION_DEFINITION); $$->child[0] = make_node(NODE_EMPTY);  $$->child[1] = $1; $$->child[2] = $2; $$->child[3] = $4; $$->child[4] = $6; };
declaracao_funcao:                       TK_PR_STATIC tipo_variavel           identificador '(' primeiro_param_funcao ')' function_body { $$ = make_node(NODE_FUNCTION_DEFINITION); $$->child[0] = make_node(NODE_STATIC); $$->child[1] = $2; $$->child[2] = $3; $$->child[3] = $5; $$->child[4] = $7; };
declaracao_funcao:                                    tipo_variavel_primitiva identificador '(' primeiro_param_funcao ')' function_body { $$ = make_node(NODE_FUNCTION_DEFINITION); $$->child[0] = make_node(NODE_EMPTY);  $$->child[1] = $1; $$->child[2] = $2; $$->child[3] = $4; $$->child[4] = $6; };
primeiro_param_funcao: %empty                                               { $$ = make_node(NODE_ARGUMENT_LIST); };
primeiro_param_funcao: declaracao_parametro_unico_funcao param_funcao       { $$ = make_node(NODE_ARGUMENT_LIST); $$->child[0] = $1; $$->child[1] = $2; };
param_funcao: %empty                                                        { $$ = make_node(NODE_EMPTY); };
param_funcao: ',' declaracao_parametro_unico_funcao param_funcao            { $$ = make_node(NODE_ARGUMENT_LIST); $$->child[0] = $2; $$->child[1] = $3; };

declaracao_parametro_unico_funcao: TK_PR_CONST  TK_PR_STATIC tipo_variavel identificador { $$ = make_node(NODE_ARGUMENT); $$->child[0] = make_node(NODE_CONST); $$->child[1] = make_node(NODE_STATIC); $$->child[2] = $3; $$->child[3] = $4; };
declaracao_parametro_unico_funcao: TK_PR_CONST               tipo_variavel identificador { $$ = make_node(NODE_ARGUMENT); $$->child[0] = make_node(NODE_CONST); $$->child[1] = make_node(NODE_EMPTY);  $$->child[2] = $2; $$->child[3] = $3; };
declaracao_parametro_unico_funcao: TK_PR_STATIC              tipo_variavel identificador { $$ = make_node(NODE_ARGUMENT); $$->child[0] = make_node(NODE_EMPTY); $$->child[1] = make_node(NODE_STATIC); $$->child[2] = $2; $$->child[3] = $3; };
declaracao_parametro_unico_funcao:                           tipo_variavel identificador { $$ = make_node(NODE_ARGUMENT); $$->child[0] = make_node(NODE_EMPTY); $$->child[1] = make_node(NODE_EMPTY);  $$->child[2] = $1; $$->child[3] = $2; };

/* comando simples */
um_comando: declaracao_variavel_local_ou_atribuicao_ou_shift { $$ = $1; };
um_comando: input              { $$ = $1; };
um_comando: output             { $$ = $1; };
um_comando: chamada_funcao     { $$ = $1; };
um_comando: comando_return     { $$ = $1; };
um_comando: comando_break      { $$ = $1; };
um_comando: comando_continue   { $$ = $1; };
um_comando: comando_do_while   { $$ = $1; };
um_comando: comando_if         { $$ = $1; };
um_comando: comando_switch     { $$ = $1; };
um_comando: comando_foreach    { $$ = $1; };
um_comando: comando_for        { $$ = $1; };
um_comando: comando_while      { $$ = $1; };
comando_simples: %empty                              { $$ = make_node(NODE_EMPTY); };
comando_simples: um_comando ';' comando_simples      { $$ = make_node(NODE_COMMAND_LIST); $$->child[0] = $1; $$->child[1] = $3; };
comando_simples: bloco_comandos ';' comando_simples  { $$ = make_node(NODE_COMMAND_LIST); $$->child[0] = $1; $$->child[1] = $3; };
comando_simples: comando_case comando_simples        { $$ = $1; $$->child[0] = $2; };



/* comandos simples - bloco de comandos */
bloco_comandos: '{' comando_simples '}' { $$ = make_node(NODE_COMMAND_BLOCK); $$->child[0] = $2;  };

/* comandos simples - atribuições */
atribuicao: acesso_variavel '=' expressao     { $$ = make_node(NODE_ASSIGNMENT_2); $$->child[0] = $1; $$->child[1] = $3; };
atribuicao: TK_IDENTIFICADOR TK_IDENTIFICADOR { $$ = make_node(NODE_EMPTY); };

declaracao_variavel_local_ou_atribuicao_ou_shift: identificador identificador {$$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $2; $$->child[1] = $1; };
declaracao_variavel_local_ou_atribuicao_ou_shift: identificador declaracao_variavel_local_ou_atribuicao_ou_shift_id { $$ = $2; $$->child[1] = $1; };
declaracao_variavel_local_ou_atribuicao_ou_shift: TK_PR_CONST declaracao_variavel_local_const   { $$ = $2; $$->child[2] = make_node(NODE_CONST);  };
declaracao_variavel_local_ou_atribuicao_ou_shift: TK_PR_STATIC declaracao_variavel_local_static { $$ = $2; $$->child[3] = make_node(NODE_STATIC); };
declaracao_variavel_local_ou_atribuicao_ou_shift: tipo_variavel_primitiva identificador opcional_declaracao_valor { $$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $2; $$->child[1] = $1; $$->child[4] = $3; };

declaracao_variavel_local_const: declaracao_variavel_local { $$ = $1; };
declaracao_variavel_local_static: TK_PR_CONST declaracao_variavel_local { $$ = $2; $$->child[2] = make_node(NODE_CONST);  };
declaracao_variavel_local_static: declaracao_variavel_local { $$ = $1; };

declaracao_variavel_local_ou_atribuicao_ou_shift_id: TK_OC_SL expressao { $$ = make_node(NODE_SHIFT_LEFT); $$->child[3] = $2; };
declaracao_variavel_local_ou_atribuicao_ou_shift_id: TK_OC_SR expressao { $$ = make_node(NODE_SHIFT_RIGHT); $$->child[3] = $2; };
declaracao_variavel_local_ou_atribuicao_ou_shift_id: acesso_propriedade declaracao_variavel_local_ou_atribuicao_id_parametro { $$ = $2; $$->child[2] = $1; }; // Atribuicao ou shift
//declaracao_variavel_local_ou_atribuicao_ou_shift_id: identificador                   { $$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $1; };
declaracao_variavel_local_ou_atribuicao_ou_shift_id: '[' expressao ']' '=' expressao { $$ = make_node(NODE_ASSIGNMENT); $$->child[2] = make_node(NODE_VECTOR_ACCESS); $$->child[2]->child[0] = $2; $$->child[3] = $5; };
declaracao_variavel_local_ou_atribuicao_ou_shift_id: '=' expressao                   { $$ = make_node(NODE_ASSIGNMENT);                                                                            $$->child[3] = $2; };

declaracao_variavel_local_ou_atribuicao_id_parametro: '[' expressao ']' '=' expressao { $$ = make_node(NODE_ASSIGNMENT); $$->child[2] = make_node(NODE_VECTOR_ACCESS); $$->child[2]->child[0] = $2; $$->child[3] = $5; };
declaracao_variavel_local_ou_atribuicao_id_parametro: '=' expressao                   { $$ = make_node(NODE_ASSIGNMENT);                                                                            $$->child[3] = $2; };
declaracao_variavel_local_ou_atribuicao_id_parametro: TK_OC_SL expressao { $$ = make_node(NODE_SHIFT_LEFT_SPECIAL); $$->child[3] = $2; };
declaracao_variavel_local_ou_atribuicao_id_parametro: TK_OC_SR expressao { $$ = make_node(NODE_SHIFT_RIGHT_SPECIAL); $$->child[3] = $2; };

declaracao_variavel_local: identificador                                        { $$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $1; }; 
declaracao_variavel_local: TK_PR_INT    identificador opcional_declaracao_valor { $$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $2; $$->child[1] = make_node(NODE_INT_TYPE);    $$->child[4] = $3; };
declaracao_variavel_local: TK_PR_FLOAT  identificador opcional_declaracao_valor { $$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $2; $$->child[1] = make_node(NODE_FLOAT_TYPE);  $$->child[4] = $3; };
declaracao_variavel_local: TK_PR_BOOL   identificador opcional_declaracao_valor { $$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $2; $$->child[1] = make_node(NODE_BOOL_TYPE);   $$->child[4] = $3; };
declaracao_variavel_local: TK_PR_CHAR   identificador opcional_declaracao_valor { $$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $2; $$->child[1] = make_node(NODE_CHAR_TYPE);   $$->child[4] = $3; };
declaracao_variavel_local: TK_PR_STRING identificador opcional_declaracao_valor { $$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $2; $$->child[1] = make_node(NODE_STRING_TYPE); $$->child[4] = $3; };
declaracao_variavel_local: identificador identificador { $$ = make_node(NODE_LOCAL_VAR); $$->child[0] = $2; $$->child[1] = $1; };


/* comando simples - io */
input: TK_PR_INPUT expressao                     { $$ = make_node(NODE_INPUT);  $$->child[0] = $2;                    };
output: TK_PR_OUTPUT expressao lista_expressoes  { $$ = make_node(NODE_OUTPUT); $$->child[0] = $2; $$->child[1] = $3; };
lista_expressoes: %empty                         { $$ = make_node(NODE_EMPTY);                                        };
lista_expressoes: ',' expressao lista_expressoes { $$ = make_node(NODE_EXPRESSION_LIST); $$->child[0] = $2; $$->child[1] = $3; };

/* comando simples - função */
chamada_funcao: identificador '(' argumento ')' optional_pipe_command { $$ = make_node(NODE_FUNCTION_CALL); $$->child[0] = $1; $$->child[1] = $3; $$->child[2] = $5; };
argumento: %empty                           { $$ = make_node(NODE_EMPTY);};
argumento: expressao argumento_aux          { $$ = make_node(NODE_ARGUMENT_LIST);          $$->child[0] = $1;                                    $$->child[1] = $2;};
argumento: '.' argumento_aux                { $$ = make_node(NODE_ARGUMENT_LIST);          $$->child[0] = make_node(NODE_ARGUMENT_PLACEHOLDER);  $$->child[1] = $2;};
argumento_aux: %empty                       { $$ = make_node(NODE_EMPTY);};
argumento_aux: ',' argumento  { $$ = $2; };

/* comandos de return, break, continue e case */
comando_return: TK_PR_RETURN expressao  { $$ = make_node(NODE_RETURN); $$->child[0] = $2; };
comando_break: TK_PR_BREAK              { $$ = make_node(NODE_BREAK); };
comando_continue: TK_PR_CONTINUE        { $$ = make_node(NODE_CONTINUE); };
comando_case: TK_PR_CASE TK_LIT_INT ':' { $$ = make_node(NODE_CASE); $$->int_literal = yylval.valor_lexico_int; };

/* controles de fluxo */
comando_if: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco_comandos comando_else_opcional { $$ = make_node(NODE_IF); $$->child[0] = $3; $$->child[1] = $6; $$->child[2] = $7; };
comando_else_opcional: %empty                                                          { $$ = make_node(NODE_EMPTY); };
comando_else_opcional: TK_PR_ELSE bloco_comandos                                       { $$ = make_node(NODE_ELSE); $$->child[0] = $2; };
comando_switch: TK_PR_SWITCH '(' expressao ')' bloco_comandos                          { $$ = make_node(NODE_SWITCH); $$->child[0] = $3; $$->child[1] = $5; };

/* comandos de iteracao */
comandos_dentro_for: atribuicao     { $$ = $1; };
comandos_dentro_for: bloco_comandos { $$ = $1; };
comandos_dentro_for_aux: %empty     { $$ = make_node(NODE_EMPTY); };
comandos_dentro_for_aux: ',' comandos_dentro_for comandos_dentro_for_aux { $$ = make_node(NODE_COMMAND_LIST_COMA_SEPARATED); $$->child[0] = $2; $$->child[1] = $3; };
comando_foreach: TK_PR_FOREACH '(' identificador ':' expressao lista_expressoes ')' bloco_comandos { $$ = make_node(NODE_FOREACH); $$->child[0] = $3; $$->child[1] = $5; $$->child[2] = $6; $$->child[3] = $8;  };
comando_for: TK_PR_FOR '(' comandos_dentro_for comandos_dentro_for_aux ':' expressao ':' comandos_dentro_for comandos_dentro_for_aux ')' bloco_comandos { $$ = make_node(NODE_FOR); $$->child[0] = $3; $$->child[1] = $4; $$->child[2] = $6; $$->child[3] = $8; $$->child[4] = $9; $$->child[5] = $11; };
comando_while: TK_PR_WHILE '(' expressao ')' TK_PR_DO bloco_comandos    { $$ = make_node(NODE_WHILE); $$->child[0] = $3; $$->child[1] = $6; };
comando_do_while: TK_PR_DO bloco_comandos TK_PR_WHILE '(' expressao ')' { $$ = make_node(NODE_DO_WHILE);   $$->child[0] = $2; $$->child[1] = $5; };

/* comandos com pipes */
pipe: TK_OC_FORWARD_PIPE {$$ = make_node(NODE_FORWARD_PIPE); };
pipe: TK_OC_BASH_PIPE {$$ = make_node(NODE_BASH_PIPE); };
optional_pipe_command: %empty {$$ = make_node(NODE_EMPTY);}; 
optional_pipe_command: comando_pipe {$$ = $1;}; 
comando_pipe: pipe chamada_funcao {$$ = make_node(NODE_PIPE_COMMAND); $$->child[0] = $1; $$->child[1] = $2;};

%%
