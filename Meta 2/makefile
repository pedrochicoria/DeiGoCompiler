make:
	lex gocompiler.l
	yacc -d --report=state gocompiler.y
	cc -Wall -o gocompiler y.tab.c lex.yy.c ast.c 

	rm -f gocompiler.zip
	zip -r gocompiler.zip gocompiler.l gocompiler.y ast.h ast.c

	./gocompiler < testes/sum.dgo  