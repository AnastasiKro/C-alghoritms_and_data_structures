#include <stdio.h>
#include <malloc.h>
#include <string.h>

const int M = 6;
typedef struct Item{
	int busy;
	int key;
	int release;
	char* info;
}Item;
int getint(){
	int n = 0; int pa;
	do{
		n = scanf("%d%*c", &pa);
		if (n==0){
			printf("I need a digit\n");
			scanf("%*[^\n]");
		}
	} while (n ==0);
	return pa;
}
char* getstr(){
        char* name =(char*)malloc(1);
        *name='\0'; int n; int len = 1;
        char buf[100];
        do{
                n = scanf("%99[^\n]", buf);
                if (n<0){
                        free(name); name = NULL;
                        continue;
                }
                if (n==0)
                        scanf("%*c");
                if (n>0){
                        len+=strlen(buf);
                        name = (char*)realloc(name, len);
                        strcat(name, buf);
                }
        }while(n>0);
        return name;
}
int findk(Item* tab){
	printf("input key\n");
	int k = getint();
	printf("input release\n");
	int r = getint();
	for (int i = 0; i<M; i++){
		if ((tab[i].key ==k)&& (tab[i].busy == 1)&& (tab[i].release == r)){
			return i;
		}
	}
	return -1;
}

int insert(Item* tab, Item m){
	printf("insert\n");
	int i =0;
	while(tab[i].info != NULL){
		i+=1;
	}
	tab[i]=m;
	return 0;
}
int sborkamus(Item* tab){
	printf("sborka\n");
	for (int i = 1; i< M; i++){
		if (tab[i].busy == 1){
			int j = i;
			while ((tab[j-1].busy ==0)&& (j >0)){
			       tab[j-1] = tab[j];
			       tab[j].busy=0;
			       j=j-1;
			}
		}
	}
	int i = 0;
	while(tab[i].busy == 1)
		i+=1;
	while(i<M){
		tab[i].info = NULL;
		tab[i].key = 0;
		tab[i].release = 0;
		i+=1;
	}
	return 0;
}
int Writetab(Item* tab){
	Item m; int v = 0;
	printf("Input key\n");
	m.key = getint();
	printf("Input info\n");
	char* ptr =getstr();
	m.info = ptr;
	for (int i = 0; i<M; i++){
		if((tab[i].key == m.key)&& (tab[i].busy ==1)){
			if (v< tab[i].release){
				v=tab[i].release +1;
			}
			else
				v+=1;
		}
	}
	if (v==0){
		m.release = 1;
	}
	else 
		m.release = v;
	m.busy=1;
	if (tab[M-1].info == NULL){
		insert(tab, m);
		return 0;
	}
	sborkamus(tab);
	if(tab[M-1].info==NULL){
		insert(tab, m);
		return 0;
	}
	printf("Table is full\n");
	return 0;
}

int Findel(Item* tab){
	int g = findk(tab);
	if (g ==-1){
		printf("there is no such element\n");
		return 0;
	}
	printf("Busy:  %d, key:  %d, release:  %d, info:  \n", tab[g].busy, tab[g].key, tab[g].release, tab[g].info);
	return 0;

}
int DelEl(Item* tab){
	int g =findk(tab);
	if (g ==-1){
		printf("no such element\n");
		return 0;
	}
	tab[g].busy = 0;
	return 0;

}

int puttab(Item* tab){
	for (int i=0; i<M; i++){
		printf("busy:  %d, key:  %d, release:  %d, info: %s\n", tab[i].busy, tab[i].key, tab[i].release, tab[i].info);
	}
	return 0;
}

int main(){
	int flag = 1;
	Item tab[M];
	for (int i = 0; i<M; i++){
		tab[i].key = 0;
		tab[i].busy = 0;
		tab[i].release=0;
		tab[i].info = NULL;
	}
	while (flag !=0){
		printf("input:\n0 to get out\n1 to write element\n2 to find element\n3 to delete element\n4 to put table\n");
		flag =getint();
		if (flag == 1)
			Writetab(tab);
		if(flag ==2)
			Findel(tab);
		if(flag ==3)
			DelEl(tab);
		if(flag ==4)
			puttab(tab);
	}
	return 0;
}






