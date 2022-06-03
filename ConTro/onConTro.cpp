#include <iostream>
using namespace std;

struct Node{
	int info;
	Node *next;
};

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

void xuatDQ(Node *L){
	if(L!=NULL){
		cout<<L->info<<" -> ";
		xuatDQ(L->next);
	}
	else cout<<"NULL";
}

int tongDQ(Node *L){
	if(L==NULL) return 0;
	return L->info + tongDQ(L->next);
}

int tongChan(Node *L){
	if(L==NULL) return 0;
	if(L->info %2 ==0)
		return L->info + tongChan(L->next);
	return tongChan(L->next);
}

int max(Node *L){
	int m = 0;
	while(L!=NULL){
		if(L->info > m)
			m = L->info;
		L = L->next;
	}
	return m;
}

int main(){
	int k,x;
	Node *first;
	nhapDS(first);
	xuatDQ(first);
	cout<<max(first);
}
