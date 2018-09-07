%{
int yylex(void);
void yyerror (char const *s);
%}

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

%%

programa: declaracao_variavel_global | declaracao_novo_tipo | declaracao_funcao | %empty;

declaracao_novo_tipo: TK_PR_CLASS TK_IDENTIFICADOR '{' declaracao_novo_tipo_propriedade declaracao_novo_tipo_propriedades '}';
declaracao_novo_tipo_propriedades: declaracao_novo_tipo_propriedade ':' | %empty;
declaracao_novo_tipo_propriedade: opcional_encapsulamento tipo_variavel_primitiva TK_IDENTIFICADOR ';';
opcional_encapsulamento: %empty | TK_PR_PRIVATE | TK_PR_PUBLIC | TK_PR_PROTECTED;

declaracao_variavel_global: TK_IDENTIFICADOR opcional_static tipo_variavel opcional_tamanho ';';
opcional_static: %empty | TK_PR_STATIC;
opcional_tamanho: %empty | '[' TK_LIT_INT ']';

tipo_variavel_primitiva: TK_PR_INT | TK_PR_FLOAT | TK_PR_CHAR | TK_PR_BOOL | TK_PR_STRING;
tipo_variavel: TK_IDENTIFICADOR | tipo_variavel_primitiva;

/*
operador_unario: '+' | '-' | '&' | '*' | '?' | '#';
operator_aritmetico: '+' | '-' | '*' | '/' | '%' | '|' | '&' | '^';
operador_relacional: '<' | '>' | TK_OC_LE | 'TK_OC_GE' | TK_OC_EQ | TK_OC_NE | TK_OC_AND | TK_OC_OR;
operador_binario: operator_aritmetico | operador_relacional; */

declaracao_funcao: opcional_static tipo_variavel_primitiva TK_IDENTIFICADOR lista_param_funcao bloco_comandos;
lista_param_funcao: '(' primeiro_param_funcao ')';
primeiro_param_funcao: %empty | opcional_const tipo_variavel_primitiva TK_IDENTIFICADOR param_funcao;
param_funcao: %empty | ',' opcional_const tipo_variavel_primitiva TK_IDENTIFICADOR param_funcao;
opcional_const: %empty | TK_PR_CONST;

comando_simples: %empty | declaracao_variavel_local_definida ';' comando_simples | declaracao_variavel_local_primitiva ';' comando_simples | bloco_comandos ';' comando_simples;
declaracao_variavel_local_primitiva: opcional_static opcional_const tipo_variavel_primitiva TK_IDENTIFICADOR opcional_declaracao_valor ';';
declaracao_variavel_local_definida: opcional_static opcional_const tipo_variavel TK_IDENTIFICADOR ';';
opcional_declaracao_valor: %empty | TK_OC_LE TK_IDENTIFICADOR | TK_OC_LE literal;
bloco_comandos: %empty | '{' comando_simples '}';
literal: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_FALSE | TK_LIT_TRUE | TK_LIT_CHAR | TK_LIT_STRING;

opcional_acesso_vetor: %empty | '[' expressao ']';
acesso_variavel: TK_IDENTIFICADOR opcional_acesso_vetor;

expressao: acesso_variavel;
expressao: '(' expressao ')';
expressao: operador_unario expressao;
expressao: expressao operador_binario expressao;
expressao: expressao '?' expressao ':' expressao;



>>>>>>> 3ec4fd53ff001e8828f05f53fffca9c2bd46265c

%%
