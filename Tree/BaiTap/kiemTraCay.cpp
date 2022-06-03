#include<iostream>
using namespace std;

struct tree{
	int info;
	tree *left,*right;
};

int soNode(tree *t){
	if(t==NULL) return 0;
	else return 1+soNode(t->left)+soNode(t->right); 
}

int cao(tree *t){
	if(t==NULL) return 0;
	int a = cao(t->left);
	int b = cao(t->right);
	return 1 + (a>b?a:b);
}

int checkTang(int a[],int n){
	for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]) return 0;
    }
    return 1;	
}

void cayTrongMang(tree *t,int a[],int &n){
	if(t!=NULL){
		cayTrongMang(t->left,a,n);
		a[n++] = t->info;
		cayTrongMang(t->left,a,n);
	}
}

int BST(tree *t){
	int a[100],n=0;
	cayTrongMang(t,a,n);
	return checkTang(a,n);
}

int isCanBang(tree *t){
	if(t==NULL || (t->left==NULL && t->right==NULL)) return 1;
	else if(abs(cao(t->left)-cao(t->right))>1) return 0;
	else isCanBang(t->left) && isCanBang(t->right);
}

int isCanBangHoanToan(tree *t){
	if(t==NULL || (t->left==NULL && t->right==NULL)) return 1;
	else if(abs(soNode(t->left)-soNode(t->right))>1) return 0;
	else isCanBangHoanToan(t->left) && isCanBangHoanToan(t->right);
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

main(){
	tree *t;
	cout<<"LNR: ";LNR(t);
}
