#include <stdio.h>
#include <string.h>
#include <malloc.h>

const int M = 6;
typedef struct Item{
	int key;
	char* info;
}Item;

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
Item vvod(){
	Item m; int a;
	printf("Input key\n");
	getint(&a);
	m.key = a;
	printf("input info\n");
	m.info = getstr();
	return m;
}
int Poisk(Item* tab, int k, int n){
	int i = 0;
	while(i!=n&& i+1!=n){
		int c = (i + n)/2;
		if(tab[c].key==k)
			return c;
		if(tab[c].key>k)
			n = c;
		else
			i = c;		
	}
	if (tab[i].key == k)
		return i;
	return -1;
}
int Writetab(Item* tab, int* n){
	if (*n==M){
		printf("The table is full\n");
		return 0;
	}
	Item m = vvod();
	if (Poisk(tab, m.key, *n)!=-1){
		printf("the table already has it\n");
		return 0;
	}
	printf("aaa\n");
	if (*n==0){
		tab[0]=m;
		*n=1;
		return 0;
	}
	int j = *n-1;
	while(tab[j].key> m.key){
		tab[j+1]=tab[j];
		j-=1;
	}
	tab[j+1] = m;
	*n+=1;
	return 0;
}
int Findel(Item* tab, int n){
	printf("input key\n");
	int k; getint(&k);
	int g = Poisk(tab, k, n);
	if (g==-1){
		printf("it does not exist\n");
		return 0;
	}
	printf("key:  %d, info: %s\n", tab[g].key, tab[g].info);
	return 0;
}
int Del(Item* tab, int* n){
	printf("input key\n");
	int m; getint(&m);
	int g = Poisk(tab, m, *n);
	if (g ==-1){
		printf("it does not exist\n");
		return 0;
	}
	for (int i = g; i<*n-1; i++){
		tab[i] = tab[i+1];
	}
	*n-=1;
	return 0;
}

int puttab(Item* tab, int n){
	for (int i = 0; i<n; i++){
		printf("key:  %d, info: %s\n", tab[i].key, tab[i].info);
	}
	return 0;
}
	
		
int main(){
	Item tab[M];
	int n = 0; int m; int flag =1;
	for (int i = 0; i<M; i++){
		tab[i].key = 0;
		tab[i].info = NULL;
	}

	while(flag != 0){
            printf("Введите цифру для выполнения указанного действия:\n");
            printf("0 - для завершения\n");
            printf("1 - добавить новую вершину в таблицу\n");
            printf("2 - поиск по ключу\n");
            printf("3 - удаление\n");
            printf("4 - вывод таблицы\n");
            getint(&m);
            if (m == 0)
                    flag = 0;
            if (m==1){
                  Writetab(tab, &n);

            }
            if(m==2)
                   Findel(tab, n);
            if(m == 3)
                    Del(tab, &n);
            if (m == 4){
		    puttab(tab, n);
	    }
	}
	return 0;
}
