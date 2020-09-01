#include <stdio.h>
#include <malloc.h>
const int N=8;

typedef struct Gr{
	int v;
	struct Gr* next;
}Gr;
typedef struct bfs{
	int v;
	int color;
	int d;
	Gr* pred;
}bfs;

typedef struct queue{
	int n;
	int* info;
	int head;
	int tail;
}queue;
typedef struct dfs{
	Gr* v;
	int color;
	int d;
	int f;
	Gr* pred;
}dfs;
typedef struct rebro{
	int P;
	int v1;
	int v2;
	struct rebro* next;
}rebro;
typedef struct Bellman{
	int d;
	Gr* pred;
}Bellman;
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
}int findv(Gr* graf, int l, int n){
        for(int i = 0; i<n; i++){
                if (graf[i].v==l)
                        return i;
        }
        return -1;
}
int Insert_queue(queue* Q, int k){
	Q->info[Q->tail]=k;
	Q->tail=(Q->tail+1)%N;
	Q->n+=1;
	return 0;
}
int Read_queue(queue* Q){
	int a = Q->info[Q->head];
	Q->head=(Q->head+1)%N;
	Q->n-=1;
	return a;
}
	
int Addv(Gr* graf, int n){
	printf("input v\n");
	int k; getint(&k);
	if (findv(graf, k, n)!=-1)
		return 0;
	graf[n].v=k;
	return 0;
}
rebro* Addr(Gr* graf, int n, rebro* R){
        int ch1; int ch2; int o,p;
        printf("Введите 1 вершину\n");
        getint(&ch1);
        printf("Введите 2 вершину\n");
        getint(&ch2);
        //for(int i = 0; i<n; i++){
                o = findv(graf, ch1, n);
                p = findv(graf, ch2, n);
        if (o==p){
                printf("Нельзя 1 и ту же вершину\n");
                return 0;
        }
        if(o==-1 || p ==-1){
                printf("Вы ввели несуществующую вершину\n");
                return 0;
        }
        Gr* ptr = graf+o;
        while(ptr->next!=NULL){
                
                if (ptr->v == ch2){
                        printf("Такое ребро уже есть\n");
                        return 0;
                }
                ptr = ptr->next;
        }
	
        ptr->next=(Gr*)malloc(sizeof(Gr));
        ptr=ptr->next;
        ptr->v = ch2;
        ptr->next = NULL;
	if (R==NULL){
		R=(rebro*)malloc(sizeof(rebro));
		printf("input P\n");
		getint(&R->P);
		R->v1=ch1;
		R->v2=ch2;
		R->next = NULL;
		return R;

	}
	rebro* r = R;
	while(r->next!=NULL)
		r = r->next;
	r->next=(rebro*)malloc(sizeof(rebro));
	r=r->next;
	printf("input P\n");
	getint(&r->P);
	r->v1=ch1;
	r->v2=ch2;
	r->next=NULL;
	return R;
	
	/*ptr = graf + p;
	while (ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next = (Gr*)malloc(sizeof(Gr));
	ptr=ptr->next;
	ptr->v=ch1;
	ptr->next=NULL;*/
       
}
int putgraf(Gr* graf, int n){
	for (int i = 0; i<n; i++){
		printf("%d:   ", graf[i].v);
		Gr* ptr = graf[i].next;
		while(ptr!=NULL){
			printf("%d  ", ptr->v);
			ptr=ptr->next;
		}
		printf("\n");
	}
	return 0;
}
int print_path(Gr* graf, int i, int k, bfs* B){
	if (i==k)
		return 0;
	if (B[k].pred==NULL)
		return 0;
	int o = B[k].pred->v;
	print_path(graf, i, o, B);
	printf("%d  ", graf[k].v);
	return 0;
}
int Poisk_v_shir(Gr*graf, int i, int n){
	bfs B[n];
	for (int j = 0; j<n; j++){
		B[j].v=graf[j].v;
		B[j].d=0;
		B[j].color = 0;
		B[j].pred=NULL;
	}
	queue Q;
	Q.tail=0;
	Q.head=0;
	Q.n=0;
	Q.info=(int*)malloc(sizeof(8));
	B[i].color=1;
	Insert_queue(&Q, B[i].v);
	while (Q.n!=0){
		int u = Read_queue(&Q);
		int k = findv(graf, u, n);
		Gr* ptr = graf[k].next;
		while (ptr!=NULL){
			int l = findv(graf, ptr->v, n);
			if (B[l].color==0){
			B[l].color=1;
			B[l].d=B[u].d+1;
			B[l].pred=graf+u;
			Insert_queue(&Q, B[l].v);}
			ptr=ptr->next;
		}
		B[k].color=2;
	}
	printf("inpit node\n");
	int u; getint(&u);
	int k = findv(graf, u, n);
	print_path(graf, i, k, B);
	return 0;
}
int DFS_visit(Gr* graf, int n, dfs* D,int i, int* time){
	D[i].color = 1;
	*time = *time+1;
	D[i].d=*time;
	Gr* ptr = D[i].v->next;
	while(ptr!=NULL){
		int k = findv( graf, ptr->v, n);
		if (D[k].color == 0){
			D[k].pred = graf+i;
			DFS_visit( graf,  n,  D, k,  time);
		}
		ptr = ptr->next;
	}
	D[i].color = 2;
	*time = *time+1;
	D[i].f=*time;
	return 0;
}

int print_dfs(Gr* graf, dfs* D){
	for (int i = 0; i<8; i++){
		printf("%d:  %d/%d,  ", graf[i].v, D[i].d, D[i].f);
		if (D[i].pred!=NULL)
			printf("%d", D[i].pred->v);
		printf("\n");
	}
	return 0;
}
int DFS(Gr* graf, int n){
	//printf("input the first\n");
	dfs D[8];
	int time;
	for (int i =0; i<8; i++){
		D[i].v=graf+i;
		D[i].color=0;
		D[i].pred=NULL;
	}
	time = 0;
	for (int i = 0; i<8; i++){
		if (D[i].color==0){
			D[i].color = 1;
			DFS_visit(graf,  n,  D, i, &time);
		}
	}
	print_dfs( graf, D);
	return 0;
}
int ProvL(Gr* graf, int n, int u, rebro* R, int v, Bellman* BF){
	rebro* r = R;
	while (r!=NULL){
		if (r->v1==u){
			int i = findv(graf, v, n);
			int j = findv(graf, u, n);
			if(BF[i].d>BF[j].d + r->P){
				BF[i].d=BF[j].d+r->P;
				BF[i].pred=graf+j;
			}
			ProvL(graf, n, u, R, v, BF);
		}
		r=r->next;
	}
	int k = findv(graf, v, n);
	return BF[k].d;
}
int Bellman_Ford(Gr* graf, int n, rebro* R){
	printf("printf v1\n");
	int u; getint(&u);
	printf("input v2\n");
	int v; getint(&v);
	Bellman BF[N];
	for (int i = 0; i< 8; i++){
		BF[i].d=999999;
		BF[i].pred=NULL;
	}
	int o = findv(graf, u, n);
	//int p = findv(graf, v, n);
	BF[o].d=0;
	int a = ProvL(graf, n, u, R, v, BF);
	printf("минимальное расстояние %d\n", a); 
	return 0;
}	
int findr(rebro * r, int a, int b){
	while (r!=NULL){
		if (r->v1==a &&r->v2==b)
			return r->P;
		r=r->next;
	}
	return 0;
}
int Floid_Warshall(Gr* graf, int n, rebro* R){
	int matrix[n][n];
	int pmatrix[n][n];
	for (int i = 0; i< n; i++){
		for (int j = 0; j<n; j++){
			pmatrix[i][j]='\0';
			if (i==j){
				matrix[i][j]=0;
				//pmatrix[i][i]='\0';
			}
			else{
				int h =findr(R, graf[i].v, graf[j].v);
				if (h==0)
					matrix[i][j] = 999999;
				else{
					matrix[i][j]=h;
					pmatrix[i][j]=i;
				}
			}
		}
	}
	for (int k = 0; k<n; k++){
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				if (matrix[i][j]>matrix[i][k]+matrix[k][j]){
					matrix[i][j]= matrix[i][k]+matrix[k][j];
					//if (k>0){
					pmatrix[i][j]=k;
					//}
				}
				//else{
					//if (matrix[i][j]<matrix[i][k]+matrix[k][j]
			}
		}
	}
	for (int i = 0; i<n; i++){
		for (int j =0; j<n; j++){
			printf("%d     ", matrix[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			printf("%d     ", pmatrix[i][j]);
		}
		printf("\n");
	}
	return 0;
	
}


int main(){
	Gr graf[8];
	for (int i = 0; i<8; i++){
		graf[i].v = '\0';
		graf[i].next = NULL;
	}
	int n = 0;
	int flag = 1;
	rebro* R=NULL;
	while (flag!=0){
		printf("0 to get out\n1 to ins ver\n2 to ins rebro\n4 to put\n5 to bfs\n6 to dfs\n");
		getint(&flag);
		if (flag==1){
			Addv(graf, n);
			n+=1;
		}
		if (flag ==2)
			R=Addr(graf, n, R);
		if (flag ==4)
			putgraf(graf, n);
		if (flag==5){
			printf("input node\n");
			int k; getint(&k);
			int i = findv(graf, k, n);
			Poisk_v_shir(graf, i, n);
		}
		if (flag == 6)
			Bellman_Ford(graf,n, R);
		if (flag==7)
			Floid_Warshall(graf, n, R);

	
	}
	return 0;
}


