#include <stdio.h>
int funcao(int a,int b){
	printf("%d%d\n",a,b);
	return a;
}
int main (){

	printf("Hello, World!");
	int a,b;
	a =2;
	b=a;
	
	char c;
	funcao(a,b);
}
