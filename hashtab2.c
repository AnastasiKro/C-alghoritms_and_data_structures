#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

const int M = 7;
typedef struct table{
	int t;
	int b;
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
int findpl(table* tab, int k){
	int key = k%M;
	while(tab[key].t!='\0'){
		key=(key+1)%M;
		if (key == k%M){
			printf("the table is full\n");
			return -1;
		}
	}
	return key;
}
int findel(table* tab, int k){
	int key=k%M;
	while((tab[key].t!='\0')|| (tab[key].b==-1)){
		//key = (key+1)%M;
		//if (key == k%M){
			//printf("did not find\n");
		//	return -1;
	//	}
	//	printf("t: %d, key: %d\n", tab[key].t, k);
		if(tab[key].t == k)
			return key;
		key = (key+1)%M;
		if(key == k%M){
			return -1;
		}
	}
	return -1;
	
}
int Insert(table* tab){
	printf("input element\n");
	int k; getint(&k);
	if (findel(tab, k)!=-1){
		printf("already exists\n");
		return 0;
	}
	int key = findpl(tab, k);
	if (key ==-1)
		return 0;
	tab[key].t = k;
	tab[key].b = 1;
	return 0;
}

int Find(table* tab){
	printf("input el\n");
	int k; getint(&k);
	int key = findel(tab, k);
	if (key ==-1)
		return 0;
	printf("place  %d, key  %d\n", key, k);
	return 0;
}
int Del(table* tab){
	printf("input el\n");
	int k; getint(&k);
	int key = findel(tab, k);
	if (key ==-1)
		return 0;
	tab[key].t = '\0';
	tab[key].b = -1;
	return 0;
}
int puttab(table* tab){
	for (int i = 0; i<M; i++){
		printf("%d\n", tab[i].t);
	}
	return 0;
}

int main(){
	int flag = 1;
	table tab[M];
	for (int i = 0; i<M; i++){
		tab[i].b=0;
		tab[i].t='\0';
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
