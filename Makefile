etapa3: 
	bison -d -v parser.y
	gcc -g -c parser.tab.c
	flex scanner.l
	gcc -c lex.yy.c
	gcc -c yyerror.c
	gcc -c arvore.c
	gcc -c main.c
	gcc -o etapa3 main.o arvore.o yyerror.o parser.tab.o lex.yy.o

debug: 
	bison -d -v parser.y --report-file=REPORTFILE
	gcc -g -c parser.tab.c
	flex scanner.l
	gcc -c lex.yy.c
	gcc -c yyerror.c
	gcc -c arvore.c
	gcc -c main.c
	gcc -o etapa3 main.o arvore.o yyerror.o parser.tab.o lex.yy.o

clean:
	rm -rf etapa3 lex.yy.c lex.yy.o main.o arvore.o yyerror.o parser.tab.c parser.tab.h parser.tab.o parser.output REPORTFILE
	
