lex gocompiler.l && yacc -d --report=state gocompiler.y && cc -Wall -o gocompiler y.tab.c lex.yy.c ast.c semantics.c codegen.c
rm -f gocompiler.zip
zip -r gocompiler.zip gocompiler.l gocompiler.y ast.h ast.c semantics.c codegen.c semantics.h
./gocompiler   < testes/smallest.dgo > testesC/exec.ll | sort
lli testesC/helloworld.ll 
