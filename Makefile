etapa6:
	bison -d -v parser.y
	gcc -g -c parser.tab.c
	flex scanner.l
	gcc -c lex.yy.c
	gcc -c yyerror.c
	gcc -c arvore.c
	gcc -c list.c
	gcc -c symboltable.c
	gcc -c scope_stack.c
	gcc -c semantic.c
	gcc -c codegen.c
	gcc -c main.c
	gcc -o etapa6 main.o arvore.o list.o codegen.o semantic.o symboltable.o scope_stack.o yyerror.o parser.tab.o lex.yy.o

debug: 
	bison -d -v parser.y --report-file=REPORTFILE
	gcc -g -c parser.tab.c
	flex scanner.l
	gcc -g -c lex.yy.c
	gcc -g -c yyerror.c
	gcc -g -c arvore.c
	gcc -c list.c
	gcc -c symboltable.c
	gcc -c scope_stack.c
	gcc -c semantic.c
	gcc -c codegen.c
	gcc -g -c main.c
	gcc -o etapa6 main.o arvore.o list.o codegen.o semantic.o symboltable.o scope_stack.o yyerror.o parser.tab.o lex.yy.o

clean:
	rm -rf etapa6 lex.yy.c lex.yy.o main.o arvore.o list.o codegen.o semantic.o yyerror.o parser.tab.c parser.tab.h parser.tab.o parser.output REPORTFILE temp1 temp2 symboltable.o scope_stack.o
	
