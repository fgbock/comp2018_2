etapa4: 
	bison -d -v parser.y
	gcc -g -c parser.tab.c
	flex scanner.l
	gcc -c lex.yy.c
	gcc -c yyerror.c
	gcc -c arvore.c
	gcc -c symboltable.c
	gcc -c semantic.c
	gcc -c main.c
	gcc -o etapa4 main.o arvore.o semantic.o symboltable.o yyerror.o parser.tab.o lex.yy.o

debug: 
	bison -d -v parser.y --report-file=REPORTFILE
	gcc -g -c parser.tab.c
	flex scanner.l
	gcc -g -c lex.yy.c
	gcc -g -c yyerror.c
	gcc -g -c arvore.c
	gcc -c symboltable.c
	gcc -c semantic.c
	gcc -g -c main.c
	gcc -o etapa4 main.o arvore.o semantic.o symboltable.o yyerror.o parser.tab.o lex.yy.o

clean:
	rm -rf etapa4 lex.yy.c lex.yy.o main.o arvore.o semantic.o yyerror.o parser.tab.c parser.tab.h parser.tab.o parser.output REPORTFILE temp1 temp2 symboltable.o
	
