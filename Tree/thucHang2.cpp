#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include <stdlib.h>

using namespace std;

struct Node{
	int info;
	Node *next;
};

struct tree{
	int info;
	tree *left,*right;
};

void nhapMang(int a[],int n){
	if (n > 0){
		for (int i = 0; i < n; i++){
			a[i] = rand() % 100;
		}
	}
}

void xuatMang(int a[], int n){
	for (int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
}

void insertDQ(Node *&L,int x, Node *p){
	if(L==p){
		L = new Node; 
		L->info = x;
		L->next = p;
	}else insertDQ(L->next,x,p);
}

Node *sapXepChanTruocLeSau(int a[], int n){
	Node *L=NULL;
	for(int i=0;i<n;i++){
		if(a[i]%2==0)
			insertDQ(L,a[i],L);
		else insertDQ(L,a[i],NULL);
	}
	return L;
}

void xuatDS(Node *L,int a[],int n){
	L=sapXepChanTruocLeSau(a,n);
	while(L!=NULL){
		cout<<L->info<<"->";
		L=L->next;
	}cout<<"NULL";
}

//LNR
void LNR(tree *t){
	if(t!=NULL){
		LNR(t->left);
		cout<<t->info<<" ";
		LNR(t->right);
	}
}

void insertBST(tree *&t, int x){
	if(t==NULL){
		t=new tree;
		t->info=x;
		t->left=t->right=NULL;
	}
	else if(t->info>x) insertBST(t->left,x);
	else if(t->info<x) insertBST(t->right,x);
	
}
void chenCay(tree *&t,tree *&T, Node *n){//t chan : T le
	while(n!=NULL){
		if(n->info%2==0)
			insertBST(t, n->info);
		else insertBST(T, n->info);
		n=n->next;
	}
}

int main(){
	int a[100], n;
	cout<<"Nhap n: ";cin>>n;
	nhapMang(a,n);
	cout<<"Mang 10 so ngau nhien : ";xuatMang(a,n);
	Node *first;
	tree *root;
	cout<<"\nDanh sach lien ket: ";xuatDS(first,a,n);
	
	Node *N=sapXepChanTruocLeSau(a,n);
		
	tree *t=NULL;
	tree *T=NULL;
	chenCay(t,T,N);
	cout<<endl;
	cout<<"\nCay BST chan: ";LNR(t);
	cout<<"\nCay BST le: ";LNR(T);
	
}
