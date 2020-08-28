#include <stdio.h>
#include <malloc.h>

typedef struct queue{
	int N;
	int* info;
	int tail;
	int head;
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
int WriteQueue(queue* Q, int* n){
	if (*n==Q->N){
		printf("Queue is full\n");
		return 0;
	}
	printf("Input digit to put to stack\n");
	int a = getint();
	Q->info[Q->tail]=a;
	Q->tail=(Q->tail+1)%Q->N;
	*n+=1;
	return 0;


	
}
int ReadQueue(queue* Q, int* n){
	if (*n==0){
			printf("The queue is empty\n");
			return 0;
	}
	int a = Q->info[Q->head];
	printf("Read: %d\n", a);
	Q->head = (Q->head+1)%Q->N;
	*n-=1;
	return 0;
}
int PutQueue(queue Q, int n){
	while(n!=0){
		printf("%d, ", Q.info[Q.head]);
		Q.head=(Q.head+1)%Q.N;
		n-=1;
	}
	//if(n!=0)
		//printf("%d \n", Q.info[Q.head]);
	return 0;
}

int main(){
	int n;
	int flag = 1;
	queue Q;// = (stack*)malloc(sizeof(stack));
	printf("input the lehgth of the queue\n");
	Q.N=getint();
	Q.tail=0;
	Q.head =0;
	Q.info = (int*)calloc(Q.N, sizeof(int));
	while (flag!=0){
	printf("Input:\n0 to get out\n1 to write to queue\n2 to read from queue\n3 to put all the queue\n");
	flag=getint();
	if (flag == 1)
		WriteQueue(&Q, &n);
	if (flag ==2)
		ReadQueue(&Q, &n);
	if (flag ==3)
		PutQueue(Q, n);
	}
	return 0;
}
