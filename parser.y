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


%type<node> programa programa_aux declaracao_funcao_usertype_e_var_global declaracao_variavel_global declaracao_novo_tipo declaracao_funcao expressao acesso_variavel chamada_funcao literal comando_if comando_else_opcional bloco_comandos argumento argumento_aux optional_pipe_command comando_pipe pipe;

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
programa_aux: %empty { };

/* opcionais & auxiliares */
literal: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_FALSE | TK_LIT_TRUE | TK_LIT_CHAR | TK_LIT_STRING;
opcional_const: %empty | TK_PR_CONST;
opcional_acesso_vetor: %empty | '[' expressao ']';
opcional_declaracao_valor: %empty | TK_OC_LE TK_IDENTIFICADOR | TK_OC_LE literal;
opcional_acesso_propriedade: %empty | '$' TK_IDENTIFICADOR;
acesso_variavel: TK_IDENTIFICADOR opcional_acesso_propriedade opcional_acesso_vetor;

/* tipo de variável */
tipo_variavel_primitiva: TK_PR_INT | TK_PR_FLOAT | TK_PR_CHAR | TK_PR_BOOL | TK_PR_STRING;
tipo_variavel_usuario: TK_IDENTIFICADOR;
tipo_variavel: tipo_variavel_usuario | tipo_variavel_primitiva;


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
expressao: '(' expressao ')' { $$ = $2; };
expressao: expressao '?' expressao ':' expressao { $$ = make_node(NODE_TERNARY); $$->child[0] = $1; $$->child[1] = $3; $$->child[2] = $5; };

/* declarações de tipo */
declaracao_novo_tipo: TK_PR_CLASS TK_IDENTIFICADOR '[' declaracao_novo_tipo_propriedade declaracao_novo_tipo_propriedades ']'';';
declaracao_novo_tipo_propriedades: ':' declaracao_novo_tipo_propriedade declaracao_novo_tipo_propriedades | %empty;
declaracao_novo_tipo_propriedade: opcional_encapsulamento tipo_variavel_primitiva TK_IDENTIFICADOR;
opcional_encapsulamento: %empty | TK_PR_PRIVATE | TK_PR_PUBLIC | TK_PR_PROTECTED;

/* fix de s/r para declarações de global e função */
declaracao_funcao_usertype_e_var_global: TK_IDENTIFICADOR TK_IDENTIFICADOR global | TK_IDENTIFICADOR TK_IDENTIFICADOR funcao { $$ = make_node(NODE_VAR_GLOBAL); };
global: ';';
funcao: '(' primeiro_param_funcao ')' bloco_comandos;

/* declaração de variável global */
//{ printf("meme"); $$ = make_node(NODE_VAR_GLOBAL); };
declaracao_variavel_global:  TK_IDENTIFICADOR TK_PR_STATIC tipo_variavel ';' { $$ = make_node(NODE_VAR_GLOBAL); };
declaracao_variavel_global:  TK_IDENTIFICADOR '[' TK_LIT_INT ']' tipo_variavel ';' { $$ = make_node(NODE_VAR_GLOBAL); };
declaracao_variavel_global: TK_IDENTIFICADOR '[' TK_LIT_INT ']' TK_PR_STATIC tipo_variavel ';'{ $$ = make_node(NODE_VAR_GLOBAL); };
declaracao_variavel_global: TK_IDENTIFICADOR tipo_variavel_primitiva ';' { $$ = make_node(NODE_VAR_GLOBAL); };

/* declaração de função */
declaracao_funcao: TK_PR_STATIC tipo_variavel TK_IDENTIFICADOR '(' primeiro_param_funcao ')' bloco_comandos | tipo_variavel_primitiva TK_IDENTIFICADOR '(' primeiro_param_funcao ')' bloco_comandos;;
primeiro_param_funcao: %empty | opcional_const tipo_variavel TK_IDENTIFICADOR param_funcao;
param_funcao: %empty | ',' opcional_const tipo_variavel TK_IDENTIFICADOR param_funcao;

/* comando simples */
um_comando: declaracao_variavel_local_ou_atribuicao_ou_shift | input | output | chamada_funcao | comando_return | comando_break | comando_continue | comando_do_while | comando_if | comando_switch | comando_foreach | comando_for | comando_while;
comando_simples: %empty 
| um_comando ';' comando_simples 
| bloco_comandos ';' comando_simples
| comando_case comando_simples;



/* comandos simples - bloco de comandos */
bloco_comandos: '{' comando_simples '}';

/* comandos simples - atribuições */
atribuicao: acesso_variavel '=' expressao | TK_IDENTIFICADOR TK_IDENTIFICADOR;

declaracao_variavel_local_ou_atribuicao_ou_shift: TK_IDENTIFICADOR declaracao_variavel_local_ou_atribuicao_ou_shift_id;
declaracao_variavel_local_ou_atribuicao_ou_shift: TK_PR_CONST declaracao_variavel_local_const;
declaracao_variavel_local_ou_atribuicao_ou_shift: TK_PR_STATIC declaracao_variavel_local_static;
declaracao_variavel_local_ou_atribuicao_ou_shift: tipo_variavel_primitiva TK_IDENTIFICADOR opcional_declaracao_valor;

declaracao_variavel_local_const: declaracao_variavel_local;
declaracao_variavel_local_static: TK_PR_CONST declaracao_variavel_local;
declaracao_variavel_local_static: declaracao_variavel_local;

declaracao_variavel_local_ou_atribuicao_ou_shift_id: TK_OC_SL expressao; // Shift
declaracao_variavel_local_ou_atribuicao_ou_shift_id: TK_OC_SR expressao; // Shift
declaracao_variavel_local_ou_atribuicao_ou_shift_id: '[' expressao ']' '=' expressao; // Atribuicao
declaracao_variavel_local_ou_atribuicao_ou_shift_id: '$' TK_IDENTIFICADOR declaracao_variavel_local_ou_atribuicao_id_parametro; // Atribuicao
declaracao_variavel_local_ou_atribuicao_ou_shift_id: TK_IDENTIFICADOR;
declaracao_variavel_local_ou_atribuicao_ou_shift_id: '=' expressao; // Atribuicao

declaracao_variavel_local_ou_atribuicao_id_parametro: '[' expressao ']' '=' expressao;
declaracao_variavel_local_ou_atribuicao_id_parametro: '=' expressao;
declaracao_variavel_local_ou_atribuicao_id_parametro: TK_OC_SL expressao; // Shift
declaracao_variavel_local_ou_atribuicao_id_parametro: TK_OC_SR expressao; // Shift

declaracao_variavel_local: TK_IDENTIFICADOR;
declaracao_variavel_local: TK_PR_INT TK_IDENTIFICADOR opcional_declaracao_valor;
declaracao_variavel_local: TK_PR_FLOAT TK_IDENTIFICADOR opcional_declaracao_valor;
declaracao_variavel_local: TK_PR_BOOL TK_IDENTIFICADOR opcional_declaracao_valor;
declaracao_variavel_local: TK_PR_CHAR TK_IDENTIFICADOR opcional_declaracao_valor;
declaracao_variavel_local: TK_PR_STRING TK_IDENTIFICADOR opcional_declaracao_valor;

declaracao_variavel_local: TK_IDENTIFICADOR TK_IDENTIFICADOR;


/* comando simples - io */
input: TK_PR_INPUT expressao;
output: TK_PR_OUTPUT expressao lista_expressoes;
lista_expressoes: %empty | ',' expressao lista_expressoes;

/* comando simples - função */
chamada_funcao: TK_IDENTIFICADOR '(' argumento ')' optional_pipe_command { $$ = make_node(NODE_FUNCTION_CALL);         $$->child[0] = make_node(NODE_IDENTIFIER); $$->child[1] = $3; $$->child[2] = $5; };
argumento: %empty { };
argumento: expressao argumento_aux { $$ = make_node(NODE_ARGUMENT);         $$->child[0] = $1; $$->child[1] = $2;};
argumento: '.' argumento_aux {$$ = make_node(NODE_ARGUMENT);         $$->child[0] = make_node(NODE_ARGUMENT_PLACEHOLDER); $$->child[0] = $2;};
argumento_aux: %empty {};
argumento_aux: ',' argumento {$$ = $2;};


/* comandos de return, break, continue e case */
comando_return: TK_PR_RETURN expressao;
comando_break: TK_PR_BREAK;
comando_continue: TK_PR_CONTINUE;
comando_case: TK_PR_CASE TK_LIT_INT ':';

/* controles de fluxo */
comando_if: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco_comandos comando_else_opcional { $$ = make_node(NODE_IF); $$->child[0] = $3; $$->child[1] = $6; $$->child[2] = $7; };
comando_else_opcional: %empty | TK_PR_ELSE bloco_comandos;
comando_switch: TK_PR_SWITCH '(' expressao ')' bloco_comandos;

/* comandos de iteracao */
comandos_dentro_for: atribuicao | bloco_comandos;
comandos_dentro_for_aux: %empty | ',' comandos_dentro_for comandos_dentro_for_aux;
comando_foreach: TK_PR_FOREACH '(' TK_IDENTIFICADOR ':' expressao lista_expressoes ')' bloco_comandos;
comando_for: TK_PR_FOR '(' comandos_dentro_for comandos_dentro_for_aux ':' expressao ':' comandos_dentro_for comandos_dentro_for_aux ')' bloco_comandos;
comando_while: TK_PR_WHILE '(' expressao ')' TK_PR_DO bloco_comandos;
comando_do_while: TK_PR_DO bloco_comandos TK_PR_WHILE '(' expressao ')';

/* comandos com pipes */
pipe: TK_OC_FORWARD_PIPE {$$ = make_node(NODE_FORWARD_PIPE); };
pipe: TK_OC_BASH_PIPE {$$ = make_node(NODE_BASH_PIPE); };
optional_pipe_command: %empty {}; 
optional_pipe_command: comando_pipe {$$ = $1;}; 
comando_pipe: pipe chamada_funcao {$$ = make_node(NODE_PIPE_COMMAND); $$->child[0] = $1; $$->child[1] = $2;};

%%
