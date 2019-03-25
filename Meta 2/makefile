make:
	lex gocompiler.l
	yacc -d --report=state gocompiler.y
	cc -Wall -o gocompiler y.tab.c lex.yy.c 

	rm -f gocompiler.zip
	zip -r gocompiler.zip gocompiler.l gocompiler.y ast.h ast.c

	./gocompiler  < smallest.dgo