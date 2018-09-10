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


programa: declaracao_variavel_global programa | declaracao_novo_tipo programa | declaracao_funcao programa | %empty;

/* opcionais & auxiliares */
literal: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_FALSE | TK_LIT_TRUE | TK_LIT_CHAR | TK_LIT_STRING;
opcional_static: %empty | TK_PR_STATIC;
opcional_tamanho: %empty | '[' TK_LIT_INT ']';
opcional_const: %empty | TK_PR_CONST;
opcional_acesso_vetor: %empty | '[' expressao ']';
opcional_declaracao_valor: %empty | TK_OC_LE TK_IDENTIFICADOR | TK_OC_LE literal;
opcional_acesso_propriedade: %empty | '$' TK_IDENTIFICADOR;
acesso_variavel: TK_IDENTIFICADOR opcional_acesso_vetor opcional_acesso_propriedade;

/* tipo de variável */
tipo_variavel_primitiva: TK_PR_INT | TK_PR_FLOAT | TK_PR_CHAR | TK_PR_BOOL | TK_PR_STRING;
tipo_variavel_usuario: TK_IDENTIFICADOR;
tipo_variavel: tipo_variavel_usuario | tipo_variavel_primitiva;

/* operadores */
operador_unario: '+' | '-' | '!' | '&' | '*' | '?' | '#';
operator_aritmetico: '+' | '-' | '*' | '/' | '%' | '|' | '&' | '^';
operador_relacional: '<' | '>' | TK_OC_LE | TK_OC_GE | TK_OC_EQ | TK_OC_NE | TK_OC_AND | TK_OC_OR;
operador_binario: operator_aritmetico | operador_relacional;

/* expressões */
expressao: literal;
expressao: acesso_variavel;
expressao: chamada_funcao;
expressao: '(' expressao ')';
expressao: operador_unario expressao;
expressao: expressao operador_binario expressao;
expressao: expressao '?' expressao ':' expressao;

/* declarações de tipo */
declaracao_novo_tipo: TK_PR_CLASS TK_IDENTIFICADOR '{' declaracao_novo_tipo_propriedade declaracao_novo_tipo_propriedades '}'';';
declaracao_novo_tipo_propriedades: ':' declaracao_novo_tipo_propriedade declaracao_novo_tipo_propriedades | %empty;
declaracao_novo_tipo_propriedade: opcional_encapsulamento tipo_variavel_primitiva TK_IDENTIFICADOR;
opcional_encapsulamento: %empty | TK_PR_PRIVATE | TK_PR_PUBLIC | TK_PR_PROTECTED;

/* declaração de variável global */
declaracao_variavel_global: TK_IDENTIFICADOR opcional_static tipo_variavel opcional_tamanho ';';

/* declaração de função */
declaracao_funcao: opcional_static tipo_variavel TK_IDENTIFICADOR '(' primeiro_param_funcao ')' bloco_comandos;
primeiro_param_funcao: %empty | opcional_const tipo_variavel TK_IDENTIFICADOR param_funcao;
param_funcao: %empty | ',' opcional_const tipo_variavel TK_IDENTIFICADOR param_funcao;

/* comando simples */
comando_com_ponto_e_virgula: atribuicao | declaracao_variavel_local | input | output | chamada_funcao | shift | comando_return | comando_break | comando_continue | comando_do_while;
comando_sem_ponto_e_virgula: comando_if | comando_switch | comando_case | comando_foreach | comando_for | comando_while;
comando_simples: %empty;
comando_simples: comando_com_ponto_e_virgula ';' comando_simples;
comando_simples: comando_sem_ponto_e_virgula comando_simples;

/* comandos simples - declarações */
declaracao_variavel_local: opcional_static opcional_const declaracao_variavel_local_aux;
declaracao_variavel_local_aux: declaracao_variavel_local_primitiva | declaracao_variavel_local_novo_tipo;
declaracao_variavel_local_primitiva: tipo_variavel_primitiva TK_IDENTIFICADOR opcional_declaracao_valor;
declaracao_variavel_local_novo_tipo: tipo_variavel_usuario TK_IDENTIFICADOR;

/* comandos simples - bloco de comandos */
bloco_comandos: %empty | '{' comando_simples '}';

/* comandos simples - atribuições */
atribuicao: acesso_variavel '=' expressao;

/* comando simples - io */
input: TK_PR_INPUT expressao;
output: TK_PR_OUTPUT expressao ',' lista_expressoes;
lista_expressoes: %empty | expressao ',' lista_expressoes;

/* comando simples - função */
chamada_funcao: TK_IDENTIFICADOR '(' argumento ')' optional_pipe_command;
argumento: %empty | expressao ',' argumento | '.' ',' argumento;

/* comando simples - shift */
shift: expressao shift_token expressao;
shift_token: TK_OC_SR | TK_OC_SL;

/* comandos de return, break, continue e case */
comando_return: TK_PR_RETURN expressao;
comando_break: TK_PR_BREAK;
comando_continue: TK_PR_CONTINUE;
comando_case: TK_PR_CASE TK_LIT_INT ':';

/* controles de fluxo */
comando_if: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco_comandos comando_else_opcional;
comando_else_opcional: %empty | TK_PR_ELSE bloco_comandos;
comando_switch: TK_PR_SWITCH '(' expressao ')' bloco_comandos;

/* comandos de iteracao */
comandos_dentro_for: atribuicao comandos_dentro_for_aux;
comandos_dentro_for_aux: %empty | ',' atribuicao comandos_dentro_for_aux;
comando_foreach: TK_PR_FOREACH '(' expressao ',' lista_expressoes ')' bloco_comandos;
comando_for: TK_PR_FOR '(' comandos_dentro_for ':' expressao ':' comandos_dentro_for ')' bloco_comandos;
comando_while: TK_PR_WHILE '(' expressao ')' TK_PR_DO bloco_comandos;
comando_do_while: TK_PR_DO bloco_comandos TK_PR_WHILE '(' expressao ')';

/* comandos com pipes */
pipe: TK_OC_FORWARD_PIPE | TK_OC_BASH_PIPE;
optional_pipe_command: %empty | comando_pipe;
comando_pipe: pipe chamada_funcao;

%%
