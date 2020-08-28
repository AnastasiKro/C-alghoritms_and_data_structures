#include <stdio.h>
#include <malloc.h>

typedef struct stack{
	struct stack* top;
	int info;
	struct stack* next;
}stack;

int getint(){
	int n=0;
	int pa;
	while(n==0){
		n = scanf("%d", &pa);
		if(n==0)
			printf("I needda digit\n");
	}
	return pa;
}
int WriteStack(stack* St){
	printf("Input digit to put to stack\n");
	int a = getint();
	if(St->top == NULL){
		St->info = a;
		St->top=St;
		return 0;
	}
	stack* s = (stack*)malloc(sizeof(stack));
	s->next=St->top;
	s->info = a;
	St->top = s;
	return 0;
}
int ReadStack(stack* St){
	if(St->top==NULL){
		printf("Empty stack\n");
		return 0;
	}
	int a = St->top->info;
	printf("Read: %d\n", a);
	stack* x = St->top;
	St->top=x->next;
	//free(x);
	return 0;
}
int PutStack(stack St){
	while(St.top!=0){
		printf("%d ", St.top->info);
		St.top = St.top->next;
	}
	return 0;
}

int main(){
	int flag = 1;
	stack St;// = (stack*)malloc(sizeof(stack));
	St.top=NULL;
	St.next = NULL;
	while (flag!=0){
	printf("Input:\n0 to get out\n1 to write to stack\n2 to read from stack\n3 to put all the stack\n");
	flag=getint();
	if (flag == 1)
		WriteStack(&St);
	if (flag ==2)
		ReadStack(&St);
	if (flag ==3)
		PutStack(St);
	}
	return 0;
}
