#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct stack{
	int top;
	int N;
	int* T;
}stack;
int getint(){
	int pa;
	int n = 0;
	while (n ==0){
		n=scanf("%d", &pa);
		if (n==0)
			printf("I need a digit\n");
	}
	return pa;
}
int Put_To_Stack(stack* St){
	if (St->top == St->N){
		printf("Нельзя, стэк полон\n");
		return 0;
	}
	int a;
	printf("Input digit\n");
	a=getint();
	St->T[St->top] = a;
	St->top+=1;
	return 1;
}
int Read__Stack(stack* St){
	if (St->top==0){
		printf("Отказ, стэк пуст\n");
		return 0;
	}
	int a = St->T[St->top-1];
	St->top = St->top-1;
	return a;
}
int Put__Stack(stack St){
	
	for (int i = 0; i<St.top; i++){
		printf("%d ", St.T[i]);
	}
	return 0;
}
int main(){
	int s;
	stack St;
	printf("Input size of the stack\n");
	s = getint();
	St.N = s;
	St.top=0;
	St.T = (int*)malloc(St.N*sizeof(int));
	int flag = 1;
	while (flag !=0){
	printf("Input:\n0 to esacpe\n1 to write to stack\n2 to read from stack\n3 to put stack\n");
	flag = getint();
	if (flag ==1)
		Put_To_Stack(&St);
	if (flag == 2){
		s = Read__Stack(&St);
		if (s!=0)
			printf("%d\n", s);
	}
	if (flag == 3)
		Put__Stack(St);
	}
	return 0;
}


