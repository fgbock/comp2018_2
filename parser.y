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

/* opcionais & auxiliares */
literal: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_FALSE | TK_LIT_TRUE | TK_LIT_CHAR | TK_LIT_STRING;
opcional_static: %empty | TK_PR_STATIC;
opcional_tamanho: %empty | '[' TK_LIT_INT ']';
opcional_const: %empty | TK_PR_CONST;
opcional_acesso_vetor: %empty | '[' expressao ']';
opcional_declaracao_valor: %empty | TK_OC_LE TK_IDENTIFICADOR | TK_OC_LE literal;
opcional_propriedade: %empty | '$' TK_IDENTIFICADOR;
acesso_variavel_simples: TK_IDENTIFICADOR opcional_acesso_vetor;
acesso_variavel_simples_ou_usuario: acesso_variavel_simples opcional_propriedade;

/* declarações de tipo */
declaracao_novo_tipo: TK_PR_CLASS TK_IDENTIFICADOR '{' declaracao_novo_tipo_propriedade declaracao_novo_tipo_propriedades '}';
declaracao_novo_tipo_propriedades: declaracao_novo_tipo_propriedade ':' | %empty;
declaracao_novo_tipo_propriedade: opcional_encapsulamento tipo_variavel_primitiva TK_IDENTIFICADOR ';';
opcional_encapsulamento: %empty | TK_PR_PRIVATE | TK_PR_PUBLIC | TK_PR_PROTECTED;

/* declaração de variável global */
declaracao_variavel_global: TK_IDENTIFICADOR opcional_static tipo_variavel opcional_tamanho ';';

/* tipo de variável */
tipo_variavel_primitiva: TK_PR_INT | TK_PR_FLOAT | TK_PR_CHAR | TK_PR_BOOL | TK_PR_STRING;
tipo_variavel: TK_IDENTIFICADOR | tipo_variavel_primitiva;

/* operadores */
operador_unario: '+' | '-' | '&' | '*' | '?' | '#';
operator_aritmetico: '+' | '-' | '*' | '/' | '%' | '|' | '&' | '^';
operador_relacional: '<' | '>' | TK_OC_LE | TK_OC_GE | TK_OC_EQ | TK_OC_NE | TK_OC_AND | TK_OC_OR;
operador_binario: operator_aritmetico | operador_relacional;

/* declaração de função */
declaracao_funcao: opcional_static tipo_variavel_primitiva TK_IDENTIFICADOR '(' primeiro_param_funcao ')' bloco_comandos;
primeiro_param_funcao: %empty | opcional_const tipo_variavel_primitiva TK_IDENTIFICADOR param_funcao;
param_funcao: %empty | ',' opcional_const tipo_variavel_primitiva TK_IDENTIFICADOR param_funcao;

/* comando simples */
comando_simples: %empty | declaracao_variavel_local_novo_tipo ';' comando_simples | declaracao_variavel_local_primitiva ';' comando_simples | atribuicao ';' comando_simples | bloco_comandos ';' comando_simples | input ';' comando_simples | output ';' comando_simples | chamada_funcao ';' comando_simples | shift ';' comando_simples;

/* comandos simples - declarações */
declaracao_variavel_local_primitiva: opcional_static opcional_const tipo_variavel_primitiva TK_IDENTIFICADOR opcional_declaracao_valor ';';
declaracao_variavel_local_novo_tipo: opcional_static opcional_const tipo_variavel TK_IDENTIFICADOR ';';

/* comandos simples - bloco de comandos */
bloco_comandos: %empty | '{' comando_simples '}';

/* comandos simples - atribuições */
atribuicao: acesso_variavel_simples_ou_usuario '=' expressao;

/* comando simples - io */
input: TK_PR_INPUT expressao;
output: TK_PR_OUTPUT lista_expressoes_primeira;
lista_expressoes_primeira: expressao ';' lista_expressoes;
lista_expressoes: %empty | expressao ';' lista_expressoes;

/* comando simples - função */
chamada_funcao: TK_IDENTIFICADOR '(' primeiro_argumento ')';
primeiro_argumento: %empty | argumento;
argumento: %empty | expressao ',' argumento | '.' ',' argumento;

/* comando simples - shift */
shift: acesso_variavel_simples_ou_usuario shift_token expressao;
shift_token: TK_OC_SR | TK_OC_SL;

/* expressões */
expressao: acesso_variavel_simples_ou_usuario;
expressao: '(' expressao ')';
expressao: operador_unario expressao;
expressao: expressao operador_binario expressao;
expressao: expressao '?' expressao ':' expressao;

/* comandos de laco */
comando_laco: comando_foreach | comando_for | comando_while | comando_do_while;
comando_foreach: TK_PR_FOREACH '(' lista_expressoes_primeira ')' bloco_comandos;
comando_for: TK_PR_FOR '(' lista_expressoes_primeira ')';
comando_while: TK_PR_WHILE '(' expressao ')' TK_PR_DO bloco_comandos;
comando_do_while: TK_PR_DO bloco_comandos TK_PR_WHILE '(' expressao ')';




%%
