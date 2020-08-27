#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

const int M = 7;
typedef struct Node{
        int N;
        struct Node* next;
}Node;
typedef struct table{
        Node* next;
        int key;
}table;
int getint(int *pa){
        int n;
        do{
                n = scanf("%d%*c", pa);
                if(n==0){
                        printf("Введите пожалуйста цифру\n");
                        scanf("%*[^\n]");
                }
        }while (n==0);
        return 0;
}
Node* findel(table tab, int k){
	Node* ptr = tab.next;

	while(ptr!=NULL){
		
		if(ptr->N==k)
			return ptr;
		ptr=ptr->next;
	}
	return NULL;
}
int Insert(table* tab){
	printf("input element\n");
	int k; getint(&k);
	int c = k%M;
	if(tab[c].next == NULL){
		tab[c].next = (Node*)malloc(sizeof(Node));
		tab[c].next->N = k;
		tab[c].next->next = NULL;
		return 0;
	}
	if(findel(tab[c], k) !=NULL){
		printf("already exists\n");
		return 0;
	}
	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->N=k;
	ptr->next=tab[c].next;
	tab[c].next = ptr;
	return 0;
}

int Find(table* tab){
	printf("input element\n");
	int k; getint(&k);
	int c = k%M;
	Node* ptr = findel(tab[c], k);
	if (ptr==NULL){
		printf("it does not exist\n");
		return 0;
	}
	printf("key: %d, element: %d\n", c, ptr->N);
	return 0;
}

int Del(table* tab){
	printf("input element\n");
	int k; getint(&k);
	int c = k%M;
	if (tab[c].next == NULL){
		printf("does not exist\n");
		return 0;
	}
	if (tab[c].next->N == k){
		free(tab[c].next);
		tab[c].next = NULL;
		return 0;
	}
	Node* ptr = tab[c].next;
	while(ptr->next!=NULL){
		Node* ptr0 = ptr->next;
		if(ptr0->N == k){
			ptr->next=ptr0->next;
			free(ptr0);
			return 0;
		}
		ptr=ptr->next;
	}
	printf("does not exist\n");
	return 0;
}			
int puttab(table* tab){
	for (int i = 0; i< M; i++){
		if (tab[i].next!=NULL){
			printf("key:  %d  ", tab[i].key);
			Node* ptr = tab[i].next;
			while (ptr!=NULL){
				printf("%d  ", ptr->N);
				ptr=ptr->next;
			}
			printf("\n");
		}
	}
	return 0;
}
		
int main(){
	int flag = 1;
	table tab[M];
	for (int i = 0; i<M; i++){
		tab[i].key = i;
		tab[i].next = NULL;
	}
	while (flag !=0){
		printf("Input:\n0 to get out\n1 to insert\n2 to find\n3 to delete\n4 to put table\n");
		getint(&flag);
		if (flag == 1)
			Insert(tab);
		if (flag == 2)
			Find(tab);
		if (flag == 3)
			Del(tab);
		if (flag == 4)
			puttab(tab);
	}
	return 0;
}

