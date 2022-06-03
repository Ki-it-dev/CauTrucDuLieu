#include<iostream>
#include<math.h>
#include <stdlib.h>
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
	for(int i=1;i<=n;i++){
		int x;
		x = (rand()*0.001);
		insertDQ(L,x,NULL);
	}
}

void xuatDQ(Node *L){
	if(L!=NULL){
		cout<<L->info<<" -> ";
		xuatDQ(L->next);
	}
	else cout<<"NULL";
}

int tongChanDQ(Node *L){
	if(L == NULL) return 0;
	else if(L->info%2==0) return L->info+tongChanDQ(L->next);
	return tongChanDQ(L->next);
}

int SDX(int x) {
    int temp = 0;
    while (x > 0) {
        temp = temp * 10 + x % 10;
        x /= 10;
    }
    return temp;
}
 
int isSDX(int x) {
    if (x == SDX(x))
        return 1;
    return 0;
}

int sumSDX(Node *L){
	if(L==NULL) return 0;
	else{
		if (isSDX(L->info) == 1){
			return L->info + sumSDX(L->next);
		}
	return sumSDX(L->next);
	}
}

int maxDQ(Node *L){
	if(L->next==NULL) return 0;
	else{
		int x = maxDQ(L->next);
		if(L->info > x) return L->info;
		else return x;
	}
}

int minDQ(Node *L){
	if(L->next==NULL) return 0;
	else{
		int x = minDQ(L->next);
		if(L->info < x) return L->info;
		else return x;
	}
}

int checkSNT(int x){
	if(x<2) return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
}

void SNT(Node *L){
	for(Node *q=L;q!=NULL;q=q->next)
		if(checkSNT(q->info))
			cout<<q->info<<" ";	
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

void sapXepChanTruocLeSau(Node *L){
	for(Node *p=L;p->next!=NULL;p=p->next)
		for(Node *q=p->next;q!=NULL;q=q->next){
			if(p->info % 2 != 0 && q->info % 2 == 0) {
				int t = p->info;
				p->info = q->info;
				q->info = t;
			}
		}
}

int main(){
	int k,x;
	Node *first;
	cout<<"\nLe Huu Nhat Khoa"<<endl<<endl;
	nhapDS(first);
	xuatDQ(first);
	
	cout<<"\n1.Tong chan: "<<tongChanDQ(first);
	cout<<"\n2.Tong cac so doi xung: "<<sumSDX(first);
	cout<<"\n3.GTLN: "<<maxDQ(first);
	cout<<"\n4.Hieu max min: "<<maxDQ(first)<<" - "<<minDQ(first)<<" = "<<maxDQ(first)-minDQ(first);
	cout<<"\n5.Cac SNT: ";SNT(first);
	cout<<"\n6.Chan truoc le sau: ";sapXepChanTruocLeSau(first);xuatDQ(first);
	cout<<"\n7.Danh sach sau loai cac so chan: ";
	cout<<"\n8.Danh sach tang dan: ";sapxep(first);xuatDQ(first);
}
