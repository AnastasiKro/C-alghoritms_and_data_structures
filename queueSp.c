#include <stdio.h>
#include <malloc.h>

typedef struct Node{
	int info;
	struct Node* next;
}Node;
typedef struct queue{
	//Node N;
	Node* tail;
	Node* head;
}queue;

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
int WriteQueue(queue* Q){	
	printf("Input digit to put to stack\n");
	int a = getint();
	Node* N = (Node*)malloc(sizeof(Node));
	N->info = a;
	N->next = NULL;
	if(Q->head == NULL){
		printf("a\n");
		Q->head = N;
	}
	else{
		printf("b\n");
		Q->tail->next = N;
	}
	Q->tail = N;
	return 0;
}
int ReadQueue(queue* Q){
	if (Q->head==NULL){
			printf("The queue is empty\n");
			return 0;
	}
	Node* x = Q->head;
	int a =x->info;
	printf("Read: %d\n", a);
	Q->head = Q->head->next;
	x->next = NULL;
	return 0;
}
int PutQueue(queue Q){
	Node* ptr = Q.head;
	while(ptr!=NULL){
		printf("%d, ", ptr->info);
		ptr=ptr->next;
		
	}
	return 0;
}

int main(){
	int n;
	int flag = 1;
	queue Q;
	//printf("input the lehgth of the queue\n");
	//Q.N=getint();
	Q.tail=NULL;
	Q.head =NULL; 
	while (flag!=0){
	printf("Input:\n0 to get out\n1 to write to queue\n2 to read from queue\n3 to put all the queue\n");
	flag=getint();
	if (flag == 1)
		WriteQueue(&Q);
	if (flag ==2)
		ReadQueue(&Q);
	if (flag ==3)
		PutQueue(Q);
	}
	return 0;
}
