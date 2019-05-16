lex gocompiler.l && yacc -d --report=state gocompiler.y && cc -Wall -o gocompiler y.tab.c lex.yy.c ast.c semantics.c codegen.c
rm -f gocompiler.zip
zip -r gocompiler.zip gocompiler.l gocompiler.y ast.h ast.c semantics.c codegen.c semantics.h
./gocompiler   < testesC/input.dgo > testesC/exec.ll | sort
./gocompiler   < testesC/input.dgo
lli-3.8 testesC/exec.ll
