make:
	lex gocompiler.l
	yacc -d --report=state gocompiler.y
	cc -Wall -o gocompiler y.tab.c lex.yy.c ast.c semantics.c 

	rm -f gocompiler.zip
	zip -r gocompiler.zip gocompiler.l gocompiler.y ast.h ast.c semantics.c semantics.h
	
	./gocompiler -s < testes/vardcl.dgo 