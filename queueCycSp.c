#include <stdio.h>
#include <malloc.h>

typedef struct Node{
	int info;
	struct Node* next;
}Node;
/*typedef struct queue{
	//Node N;
	Node* tail;
	Node* head;
}queue;
*/
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
Node* WriteQueue(Node* tail){	
	printf("Input digit to put to stack\n");
	int a = getint();
	Node* N = (Node*)malloc(sizeof(Node));
	N->info = a;
	N->next = NULL;
	if(tail==NULL){
		tail = N;
		N->next = N;
	}
	else{
		N->next=tail->next;
		tail->next = N;
		tail = N;
	}
	return tail;
}
Node* ReadQueue(Node* tail){
	if (tail==NULL){
			printf("The queue is empty\n");
			return 0;
	}
	if (tail->next == tail){
		printf("Read: %d\n", tail->info);
		return NULL;
	}
	Node* x = tail->next;
	tail->next=x->next;
	int a =x->info;
	printf("Read: %d\n", a);
	x->next = NULL;
	return tail;
}
int PutQueue(Node* tail){
	if (tail == NULL)
		return 0;
	Node* ptr = tail->next;
	while(ptr!=tail){
		printf("%d, ", ptr->info);
		ptr=ptr->next;
	}
	printf("%d ", tail->info);
	return 0;
}

int main(){
	int n;
	int flag = 1;
	Node* tail = NULL; 
	while (flag!=0){
	printf("Input:\n0 to get out\n1 to write to queue\n2 to read from queue\n3 to put all the queue\n");
	flag=getint();
	if (flag == 1)
		tail=WriteQueue(tail);
	if (flag ==2)
		tail=ReadQueue(tail);
	if (flag ==3)
		PutQueue(tail);
	}
	return 0;
}
