#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct tree{
	int info;
	tree *left,*right;
};

int timBST(tree *t,int x){
	if(t==NULL) return 0;
	if(t->info==x) return 1;
	if(t->info < x) return timBST(t->right,x);
	else return timBST(t->left,x);
}

int soNode(tree *t){
	if(t==NULL) return 0;
	else return 1+soNode(t->left)+soNode(t->right); 
}

void chen(tree *&t,int x){
	if(t==NULL){
		t = new tree;
		t->info = x;
		t->left = t->right = NULL;
	}else if(soNode(t->left)<soNode(t->right)) chen(t->left,x);
	else chen(t->right,x);
}

//NLR
void NLR(tree *t){
	if(t!=NULL){
		cout<<t->info<<" ";
		NLR(t->left);
		NLR(t->right);
	}
}

void lietkeLa(tree *t){
	if(t!=NULL){
		if(t->right == NULL && t->left == NULL)
			cout<<t->info<<" ";
		lietkeLa(t->left);
		lietkeLa(t->right);
	}
}

tree* xoaLa(tree *t){
    if (t == NULL)
        return NULL;
    if (t->left == NULL && t->right == NULL) {
        free(t);
        return NULL;
    }
    t->left = xoaLa(t->left);
    t->right = xoaLa(t->right);
 
    return t;
}

void nodeNoi(tree *t,tree *root){
	if(t){
		if(!(t->right == NULL && t->left == NULL) && t!=root)
			cout<<t->info<<" ";
		nodeNoi(t->left,root);
		nodeNoi(t->right,root);
	}
}

main(){
	tree *t;
	int a[20] = {7,15,9,11,21,34,43,28,16,17,18,25,34,62,41};
	t=NULL;
	for(int i=0;i<15;i++)
		chen(t,a[i]);
	cout<<"Le Huu Nhat Khoa\n";
	cout<<"\nNLR: ";NLR(t);
	cout<<"\nCac Node la = ";lietkeLa(t);
	
	//xoaLa(t);
	cout<<"\nNode noi = ";nodeNoi(t,t);
}
