#include <iostream>
#include <math.h>
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
	Tree *q = tao(10,tao(7,NULL,tao(20,tao(21,NULL,NULL),NULL)),tao(5,NULL,NULL));
	Tree *p = tao(13,tao(4,NULL,tao(17,NULL,NULL)),tao(11,NULL,NULL));
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
//LNR
void LNR(Tree *t){
	if(t!=NULL){
		LNR(t->left);
		cout<<t->info<<" ";
		LNR(t->right);
	}
}
//LRN
void LRN(Tree *t){
	if(t!=NULL){
		LRN(t->left);
		LRN(t->right);
		cout<<t->info<<" ";
	}
}

//NRl
void NRL(Tree *t){
	if(t!=NULL){
		cout<<t->info<<" ";
		NRL(t->right);
		NRL(t->left);
	}
}
//RNL
void RNL(Tree *t){
	if(t!=NULL){
		RNL(t->right);
		cout<<t->info<<" ";
		RNL(t->left);
	}
}
//RLN
void RLN(Tree *t){
	if(t!=NULL){
		RLN(t->right);
		RLN(t->left);
		cout<<t->info<<" ";
	}
}

int isSNT(int x){
	if(x<2) return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}

void lietkeSNT(Tree *t){
	if(t!=NULL){
		if(isSNT(t->info)==1){
			cout<<t->info<<" ";
		}
		lietkeSNT(t->left);
		lietkeSNT(t->right);
	}
}

int demLa(Tree *t){   
	if(t==NULL) return 0;
    else
       if(t->left==NULL && t->right==NULL) return 1;
    else return demLa(t->left)+demLa(t->right);
}

int demNode1Con(Tree *t){
	if(t==NULL) return 0;
	if(t->left && t->right == NULL)
		return 1+demNode1Con(t->left);
	if(t->right && t->left == NULL)
		return 1+demNode1Con(t->right);
	return demNode1Con(t->left)+demNode1Con(t->right);
}

main(){
	Tree *root;
	taoCay(root);
	cout<<"Cau 1: ";
	cout<<"\n\nNLR: ";NLR(root);
	cout<<"\nLNR: ";LNR(root);
	cout<<"\nLRN: ";LRN(root);
	cout<<"\n\nNRL: ";NRL(root);
	cout<<"\nRNL: ";RNL(root);
	cout<<"\nRLN: ";RLN(root);
	cout<<"\n\nCau 2: Liet ke so nguyen to: ";lietkeSNT(root);
	cout<<"\nCau 3: So la co trong cay: "<<demLa(root);
	cout<<"\nCau 4: Node 1 con: "<<demNode1Con(root);
}
