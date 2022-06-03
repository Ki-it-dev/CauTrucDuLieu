#include <iostream>
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

void chenBST(tree *&t,int x){//tim kiem co bo sung
	if(t==NULL){
		t = new tree;
		t->info = x;
		t->left = t->right = NULL;
	}else if(t->info > x) chenBST(t->left,x);
	else if(t->info < x) chenBST(t->right,x);
	else cout<<"Da ton tai gia tri "<<x<<" khong chen!!!";
}

tree *tao(int x,tree *l,tree *r){
	tree *p = new tree;
	p->info = x;
	p->left = l;
	p->right= r;
	return p;
}

void taoCay(tree *&T){
	tree *l1 = tao(23,tao(11,NULL,NULL),tao(25,NULL,NULL));
	tree *l2 = tao(35,tao(31,NULL,NULL),tao(42,NULL,NULL));
	tree *p = tao(30,l1,l2);
	tree *q = tao(70,NULL,tao(80,tao(73,NULL,NULL),tao(85,NULL,NULL)));
	T = tao(50,p,q);
}

//LNR
void LNR(tree *t){
	if(t!=NULL){
		LNR(t->left);
		cout<<t->info<<" ";
		LNR(t->right);
	}
}

int min(tree *t){
	if(t->left == NULL){
		return t->info;
	}
	return min(t->left);
}

int max(tree *t){
	if(t->right == NULL){
		return t->info;
	}
	return max(t->right);
}

int mucCay(tree *t,int muc,int x){
	if(t==NULL) return 0;
	if(t->info == x) return muc;
	int level = mucCay(t->left,muc+1,x);
	if(level!=0) return level;
	level = mucCay(t->right,muc+1,x);
	if(t->info != x) return -1;
	return muc;
}

int getMuc(tree *t,int x){
	return mucCay(t,0,x);
}

main(){
	tree *root;
	taoCay(root);
	cout<<"LNR: ";LNR(root);
	cout<<"\nMin = "<<min(root);
	cout<<"\nMax = "<<max(root);
	int x;
	cout<<"\nNhap gia tri can tim: ";cin>>x;
	if(timBST(root,x)==1){
		cout<<"Co gia tri ";
	}else cout<<"Khong co gia tri can tim";
	cout<<"\nMuc cua "<<x<<" : ";
	if(getMuc(root,x)==-1)
		cout<<"Khong ton tai!!!";
	else cout<<getMuc(root,x);
}
