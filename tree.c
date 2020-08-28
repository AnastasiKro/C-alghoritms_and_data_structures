#include <stdio.h>
#include <malloc.h>

typedef struct Node{
	int key;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
}Node;
int DEL(Node* tree, Node* ptr);
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
Node* Insert(Node* tree){
	Node* ptr = tree;
	printf("input key\n");
	int k; getint(&k); int p;
	if (tree==NULL){
		tree=(Node*)malloc(sizeof(Node));
		tree->key = k;
		tree->left = NULL;
		tree->right = NULL;
		tree->parent = NULL;
		return tree;
	}
	Node* ptr0= tree;
	while(ptr0!=NULL){
	if (k==ptr->key){
		printf("already exists\n");
		return tree;
	}
	ptr = ptr0;
	if (k>ptr->key){
		ptr0 = ptr->right;
		p = 1;
	}
	else{ 
		ptr0 = ptr->left;
		p = 0;
	}
	
	}
	ptr0=(Node*)malloc(sizeof(Node));
	ptr0->key = k;
	ptr0->left = NULL;
	ptr0->right = NULL;
	ptr0->parent = ptr;
	if (p==1)
		ptr->right = ptr0;
	else 
		ptr->left = ptr0;
		
	return tree;
}
int Pr (Node* tree){
	if (tree==NULL)
		return 0;
	printf("%d ", tree->key);
	Pr(tree->left);
	Pr(tree->right);
	
	return 0;
}
int Centr(Node* tree){
	if (tree==NULL)
		return 0;
	Centr(tree->left);
		printf("%d ", tree->key);
		Centr(tree->right);
	
	return 0;
}
int Obr(Node* tree){
	if (tree==NULL)
		return 0;
	Obr(tree->left);
	Obr(tree->right);
	printf("%d ", tree->key);
	return 0;
}
int puttree(Node* tree){
	if (tree == NULL)
		return 0;
	if(tree->left!=NULL && tree->right!=NULL){
	printf("key: %d, left: %d, right: %d\n", tree->key, tree->left->key, tree->right->key);}
	if (tree->left!=NULL && tree->right == NULL)
		printf("key: %d, left: %d\n", tree->key, tree->left->key);
	if (tree->left == NULL && tree->right!=NULL)
		printf("key: %d, right:  %d\n", tree->key, tree->right->key);
	puttree(tree->left);
	puttree(tree->right);
	return 0;
}
Node* min(Node* tree){
	if (tree==NULL)
		return 0;
	while( tree->left!=NULL)
		tree=tree->left;
	return tree;
}

Node* NEXT(Node* tree){
	printf("input\n");
	int k; getint(&k);
	Node* ptr = tree;
	if (tree->right!=NULL){
		tree = min(tree->right);
		printf("next element is %d\n", tree->key);
		return tree;
	}
	while(ptr!=NULL){
	ptr=tree->parent;
	if (tree==ptr->left){
		printf("next el is %d\n", ptr->key);
		return ptr;
	}
	tree=ptr;
	}
}	
Node* Find(Node* tree, int k){
	Node* ptr = tree;
	while(ptr!=NULL){
		if (ptr->key == k)
			return ptr;
		if(k>ptr->key)
			ptr=ptr->right;
		else
			ptr=ptr->left;
	}
	printf("key was not found\n");
	return 0;
}

int delete(Node* tree){
	printf("input key\n");
	int k; getint(&k);
	Node* ptr = Find(tree, k);
	if (ptr==NULL){
		printf("was not found\n");
		return 0;
	}
	DEL(tree, ptr);
}


int DEL(Node* tree, Node* ptr){
	if (ptr->left==NULL){
		if (ptr==ptr->parent->left){
			ptr->parent->left=ptr->right;
			free(ptr);
			return 0;
		}
		else{
			ptr->parent->right=ptr->right;
			free(ptr);
			return 0;
		}
	}
	if (ptr->right == NULL){
		if (ptr==ptr->parent->left){
			ptr->parent->left = ptr->left;
			free(ptr);
			return 0;
		}
		else{
			ptr->parent->right=ptr->left;
			free(ptr);
			return 0;
		}
	}
	Node* ptr0=min(ptr->right);
	ptr->key=ptr0->key;
	DEL(tree, ptr0);
	return 0;
}



int main(){
	int flag = 1;
	Node* tree = NULL;
	while (flag!=0){
		printf("\n");
		printf("input\n0 get out\n1 - прямой обход\n2 - центрированный\n3 - обратный\n4 to insert\n5 to put tree\n6 to delete node\n7 to find next\n");
		printf("\n");
		getint(&flag);
		if (flag == 1)
			Pr(tree);
		if (flag ==2)
			Centr(tree);
		if (flag == 3)
			Obr(tree);
		if (flag ==4)
			tree =Insert(tree);
		if (flag == 5)
			puttree(tree);
		if (flag == 6)
			delete(tree);
		if (flag == 7)
			NEXT(tree);
	}
	return 0;
}


