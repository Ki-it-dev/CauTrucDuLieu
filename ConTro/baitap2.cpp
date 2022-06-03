#include<iostream>
#include<math.h>
using namespace std;

//Cho 1 DSLK don L. Hay chuyen sang DSLK don noi vong


struct Node{
	int info;
	Node *next;
};

struct Node2ptr{
	int Info;
	Node2ptr *Pre,*Next;
};

Node2ptr *first,*last;

void xuatDQ(Node *L){
	if(L!=NULL){
		cout<<L->info<<" -> ";
		xuatDQ(L->next);
	}
	else cout<<"NULL";
}

void insertDQ(Node *&L,int x, Node *p){
	if(L==p){
		L = new Node; 
		L->info = x;
		L->next = p;
	}else insertDQ(L->next,x,p);
}

void nhapDS(Node *&L){
	int n;
	cout<<"Nhap n>0: ";cin>>n;
	L=NULL;
	cout<<"Nhap n so : ";
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		insertDQ(L,x,NULL);
	}
}
// Don -> Vong
void donVong(Node *L){
	Node *q;
	for(q=L;q->next!=NULL;q=q->next);
	q->next=L;
}

void xuatDonVong(Node *L){
	Node *q=L;
	do{
		cout<<q->info<<" ";
		q=q->next;
	}while(q!=L);
}
// Vong -> Don
void vongDon(Node *L){
	Node *q;
	for(q=L;q->next!=NULL;q=q->next);
	q->next=NULL;
}
//------------------Kep--------------------
/*
void xuatXuoi(){
	Node2ptr *p = first;
	while(p!=NULL){
		cout<<p->Info;
		p = p->Next;
	}
}
void xuatNguoc(){
	Node2ptr *p = last;
	while(p!=NULL){
		cout<<p->Info;
		p = p->Pre;
	}
}
*/

void chen(Node2ptr *p,int x){
	Node2ptr *q = new Node2ptr;
	q->Info = x;
	q->Next = p;
	if(p==first){
		first->Pre = q;
		first = q;
		q->Pre = NULL;
	}else{
		Node2ptr *r = p->Pre;
		r->Next = q;
		q->Next = r;
		p->Pre = q;
	}
}

/* 1. Cho 1 danh sach don truong Info chua cac gia tri nguyen. Hay dao cac gia tri trong danh sach sao cho 
- Cac SNT nam o dau danh sach con lai  nam o sau danh sach
   2. Gia su co 2 danh sach L1 L2 da sap xep tang dan. Hay tao danh sach L3 co cac gia tri tu L1 va L2 sao cho
- L3 tang dan
*/

bool checkSNT(int x){
	if(x<2) return false;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return false;
	return true;
}

void daoSNTF(Node *L){

}

int main(){
	Node *first;
	Node2ptr *second;
	nhapDS(first);
	cout<<"\nXuat danh sach: ";
	xuatDQ(first);
	cout<<"\nDanh sach dao SNT: ";
	daoSNTF(first);
	//donVong(first);xuatDonVong(first);
	//vongDon(first);xuatDQ(first);
	return 0;
}
