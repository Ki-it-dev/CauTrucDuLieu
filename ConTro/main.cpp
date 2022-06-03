#include <iostream>
#include <Math.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node{
	int info;
	Node *next;
};
//tao node co truong info la x, truong next la p, return ve dia chi node do
Node *tao(int x,Node *p){
	Node *q = new Node;
	q->info = x;
	q->next = p;
	return q;
}
//first -> 3 -> 7 -> 12 -> 9 -> 11 -> 8 -> 15 -> 6 -> NULL
void taoDS(Node *&L){
	L = tao(3,tao(7,tao(12,tao(9,tao(11,tao(8,tao(15,tao(6,NULL))))))));
}
void xuatDS(Node *&L){
	Node *q = L;
	while(q!=NULL){//for(Node *q=L;q!=NULL;q=q->next)
		cout<<q->info<<" -> ";
		q = q->next;
	}
	cout<<"NULL\n";
}
void xuatDQ(Node *L){
	if(L!=NULL){
		cout<<L->info<<" -> ";
		xuatDQ(L->next);
	}
	else cout<<"NULL";
}

/*
Cho 1 danh sach lien ket don, truong info chua gia tri nguyen. Hay viet cac yeu cau sau:
x1. Tinh tong cac gia tri 
x2. Tinh tong cac gia tri chan
x3. Tim max
x4. Tim 2 gia tri lien tiep co tong lon nhat
x5. *Tim 2 gia tri co tong lon nhat
x6. Tinh tong cac so nguyen to
7. Kiem tra tinh khong giam
8. Node cuoi cung cua danh sach la chan hay le (danh sach khong rong)
9. Node ke cuoi cua danh sach la chan hay le (danh sach toi thieu 2 node)
*/
int tong(Node *&L){
	int s = 0;
	while(L!=NULL){
		s += L->info;
		L = L->next;
	}
	return s;
}

int tongDQ(Node *L){
	if(L==NULL) return 0;
	return L->info + tongDQ(L->next);
}

int tongChan(Node *L){
	int s = 0;
	while(L!=NULL){
		if(L->info%2 == 0){
			s += L->info;
		}
		L = L->next;
	}
	return s;
}

int tongChanDQ(Node *L){
	if(L == NULL) return 0;
	else if(L->info%2==0) return L->info+tongChanDQ(L->next);
	return tongChanDQ(L->next);
}

int max(Node *L){
	int max = 0;
	while(L!=NULL){
		if(max < L->info)
			max = L->info;
		L = L->next;
	}
	return max;
}

int maxDQ(Node *L){
	if(L->next==NULL) return 0;
	else{
		int x = maxDQ(L->next);
		if(L->info > x) return L->info;
		else return x;
	}
}

int tongLTMax(Node *L){
	int max = L->info + L->next->info;//Tong 2 node dau tien
	for(Node *p=L->next; p->next!=NULL; p=p->next)
		if(max<p->info + p->next->info)
			max = p->info + p->next->info;
	return max;
}

int tongLTMaxDQ(Node *L){
	if(L->next->next == NULL) return L->info + L->next->info;
	else{
		int x = tongLTMaxDQ(L->next);
		if(x>L->info + L->next->info) return x;
		else
			return L->info + L->next->info;
	}
}

int max2PT(Node *L){
	int max = L->info + L->next->info;
	for(Node *q =L; q->next; q = q->next) 
		for(Node *p=q->next; p!=NULL; p=p->next)
			if(max<q->info + p->info)
				max = q->info + p->info;
	return max;
}

int checkSNT(int x){
	if(x<2) return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
}

int tongSNT(Node *L){
	int s = 0;
	for(Node *q=L;q!=NULL;q=q->next)
		if(checkSNT(q->info))
			s += q->info;
	return s;	
}

int tongSNTDQ(Node *L){
	if(L){
		if(checkSNT(L->info)==1)
			return L->info + tongSNTDQ(L->next);
		return tongSNTDQ(L->next);
	}else return 0;
}

void checkUp(Node *L){
	for(Node *p=L;p->next!=NULL;p=p->next) // p->next == p->next!=NULL
		if(p->info > p->next->info) cout<<"Giam";
	cout<<"Tang";
}

int checkUPDQ(Node *L){
	if(L==NULL || L->next==NULL) return 1;
	if(L->info > L->next->info) return 0;
	else return checkUPDQ(L->next);
}

void nodeKeCuoi(Node *L){
	Node *p=L;
	while(p->next->next !=NULL)
		p=p->next;
	if(p->info%2==0) cout<<"Chan";
	else cout<<"Le";
}

void nodeKeCuoiDQ(Node *L){
	if(L->next->next==NULL)
		if(L->info%2==0) cout<<"Chan";
		else cout<<"Le";
	else nodeKeCuoiDQ(L->next);
}

void nodeCuoiDQ(Node *L){
	if(L->next==NULL)
		if(L->info%2==0) cout<<"Chan";
		else cout<<"Le";
	else nodeCuoiDQ(L->next);
}

//---------------------------------------------------------------------------------------------

Node* location(Node *L,int k){
	if(k==1 || L==NULL) return L;
	else return location(L->next,k-1);
}

void insertVTDQ(Node *&L,int x, int k){
	if(L==NULL || k==1){
		Node *q = new Node;
		q->info = x;
		q->next = L;
		L = q;
	}else insertVTDQ(L->next,x,k-1);
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

void xoa(Node *&L,Node *p){
	if(L==p){
		L=L->next;
		delete p;
	}else xoa(L->next,p);
}

Node *timX(Node *L,int x){
	for(Node *p=L;p!=NULL;p=p->next)
		if(p->info == x) return p;
	return NULL;
}

Node *timXDQ(Node *L,int x){
	if(L==NULL || L->info == x) return L;
	return timXDQ(L->next,x);
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

int main(int argc, char** argv) {
	int k,x;
	Node *first;
	nhapDS(first);
	xuatDS(first);
	cout<<"\nNhap vi tri k trong danh sach:";cin>>k;
	cout<<"\nNhap gia tri x trong danh sach:";cin>>x;
	/*
	if(location(first,k)==NULL)
		cout<<k<<" nhieu hon so node trong danh sach";
	else
		cout<<"\nVi tri tai "<<k<<" co gia tri la : "<<location(first,k)->info;
	cout<<"\nNhap gia tri can chen: ";cin>>x;
	insertDQ(first,x,location(first,k));
	xuatDS(first);
	*/
	Node *p = location(first,k);
	Node *tim = timX(first,x);
	/*
	if(p==NULL) cout<<"Vi tri xoa nam ngoai danh sach";
	else{
		xoa(first,p);
		xuatDS(first);
	}*/
}
