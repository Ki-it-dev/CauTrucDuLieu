#include <iostream>
#include <Math.h>
using namespace std;
/*
Cho dslk don, truong Info chua so nguyen
x1. dao 2 node dau va cuoi cho nhau (ds toi thieu 2 node)
x2. dao 2 node cuoi cho nhau (ds toi thieu 2 node)
3. gia su co con tro p tro vao 1 node nao do (p ko tro dau, p ko tro cuoi)
Hay dao ds sao cho Node duoc tao boi p la node dau trong ds moi, node truoc p la node cuoi trong ds moi
x4. dao nguoc danh sach
5. gia su danh sach da duoc sap xep, chen tang 1 gia tri vao x danh sach
6. loai tat ca cac gia tri x ra khoi danh sach
*/
struct Node{
	int info;
	Node *next;
};

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
		insertDQ(L,x,NULL);//chen dau || chen cuoi (L,x,L)
	}
}

void daoDauVaCuoi(Node *L){
	Node *q=L->next;
	for(;q->next!=NULL;q=q->next);
	int t = L->info;
	L->info = q->info;
	q->info = t;	
}

void daoCuoi(Node *L){
	Node *q,*p;
	for(p=L;p->next!=NULL;p=p->next){
		q = p;
	}
	int t = p->info;
	p->info = q->info;
	q->info = t;
}

void daoDS(Node *&L){
	Node *q = NULL, *p= NULL;
	while(L!=NULL){
		p = L->next;
		L->next = q;
		q = L;
		L = p;
	}
	L = q;
}

void sapxep(Node *L){
	for(Node *p=L;p->next!=NULL;p=p->next)
		for(Node *q=p->next;q!=NULL;q=q->next)
			if(p->info > q->info){
				int temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
}

Node* location(Node *L,int k){
	if(k==1 || L==NULL) return L;
	else return location(L->next,k-1);
}

void daoDSVoiConTro( Node *&L, Node *p){
	Node *r =L;
	while(r->next !=p) {
		r=r->next;
	}
	Node *q =p;
	while(q->next!=NULL)    {
		q=q->next;
	}
	r->next=NULL;
	q->next=L;
	L=p;
}

void chenSX( Node *&L, int x){
    Node *p =L;
    while ( p->info <x&&p!=NULL) p=p->next;
    insertDQ(L,x,p);
}

int main(){
	Node *first;
	nhapDS(first);
	xuatDQ(first);
	/*
	cout<<"\nDao dau va cuoi: ";daoDauVaCuoi(first);xuatDQ(first);
	cout<<"\nDao 2 phan tu cuoi danh sach: ";daoCuoi(first);xuatDQ(first);
	cout<<"\nDao danh sach: ";daoDS(first);xuatDQ(first);
	*/
	int x,k;
	//input
	cout<<"\nNhap vi tri k trong danh sach:";cin>>k;
	cout<<"\nNhap gia tri can chen : ";cin>>x;
	Node *p=location(first,k);
	//Output	
	
}


