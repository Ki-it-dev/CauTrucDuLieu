#include <iostream>

using namespace std;

struct Tree{
	int info;
	Tree *left,*right;
};

Tree *tao(int x,Tree *l,Tree *r){
	Tree *p = new Tree;
	p->info = x;
	p->left = l;
	p->right= r;
	return p;
}

void taoCay(Tree *&T){
	Tree *q = tao(12,NULL,tao(22,tao(17,NULL,NULL),tao(25,NULL,tao(19,NULL,NULL))));
	Tree *p = tao(21,tao(11,NULL,NULL),tao(13,NULL,NULL));
	T = tao(15,q,p);
}

//NLR
void NLR(Tree *t){
	if(t!=NULL){
		cout<<t->info<<" ";
		NLR(t->left);
		NLR(t->right);
	}
}

int tongNode(Tree *t){
	if(t==NULL) return 0;
	else return 1+tongNode(t->left)+tongNode(t->right);
}

int nodeLe(Tree *t){
	int count = 0;
	if (t!=NULL) {
    	if (t->info % 2 != 0)
    		count++;
    	count += nodeLe(t->left);
    	count += nodeLe(t->right);
	}
	return count;
}

int tongNodeChan(Tree *t){
	int s = 0;
	if(t!=NULL){
		if(t->info % 2 ==0)
			s += t->info;
		s += tongNodeChan(t->left);
		s += tongNodeChan(t->right);
	}
	return s;
}

int demLa(Tree *t){
	if(t==NULL) return 0;
	else if(t->right == NULL && t->left == NULL)
		return 1;
	return demLa(t->left)+demLa(t->right);
}

int tongNode2Con(Tree *t){
	int s = 0;
	if(t==NULL) return 0;
	else{
		if(t->left && t->right)
			s += t->info;
		s += tongNode2Con(t->left);
		s += tongNode2Con(t->right);
	}
	return s;
}

int cayCao(Tree *t){
	if(t==NULL) return 0;
	else{
		int a = cayCao(t->left);
		int b = cayCao(t->right);
		if(a>b) return 1+a;
		else return 1+b;
	}
}

main(){
	int x;
	Tree *root;
	taoCay(root);
	cout<<"Le Huu Nhat Khoa\n";
	cout<<"NLR: ";NLR(root);
	cout<<"\nDem tong Node: "<<tongNode(root);
	cout<<"\nDem Node le: "<<nodeLe(root);
	cout<<"\nTong Node chan: "<<tongNodeChan(root);
	cout<<"\nTong la tren Node: "<<demLa(root);	
	cout<<"\nTong Node co 2 con: "<<tongNode2Con(root);
	cout<<"\nCao = "<<cayCao(root);
}
