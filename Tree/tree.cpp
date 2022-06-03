#include <iostream>
using namespace std;

struct Tree{
	char info;
	Tree *left,*right;
};

Tree *tao(char x,Tree *l,Tree *r){
	Tree *p = new Tree;
	p->info = x;
	p->left = l;
	p->right= r;
	return p;
}

void taoCay(Tree *&T){
	Tree *p = tao('F',tao('G',NULL,NULL),tao('H',NULL,NULL));
	Tree *q = tao('C',tao('D',NULL,NULL),tao('E',NULL,NULL));
	Tree *r = tao('B',NULL,p);
	T  = tao('A',r,q); 
}
//LrN
void F(Tree *t){
	if(t!=NULL){
		F(t->left);
		F(t->right);
		cout<<t->info<<" ";
	}
}

main(){
	Tree *root;
	taoCay(root);
	F(root);
}
