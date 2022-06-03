#include <iostream>
#include <stdlib.h>
using namespace std;

struct SV{
	char ma[30], hoten[30], stt[10];
	float diem;
};

struct Node{
	SV info;
	Node *next;
};

void insertDQ(Node *&L,SV x, Node *p){
	if(L==p){
		L = new Node; 
		L->info = x;
		L->next = p;
	}else insertDQ(L->next,x,p);
}

SV nhap1SV(){
	SV x;
	cout<<"\nNhap STT: ";fflush(stdin);gets(x.stt);
	cout<<"Nhap ma: ";fflush(stdin);gets(x.ma);
	cout<<"Nhap ho ten: ";fflush(stdin);gets(x.hoten);
	cout<<"Nhap diem: ";cin>>x.diem;
	return x;
}

void taoDS(Node *&L){
	L=NULL;
	SV x;
	int n;
	cout<<"Nhap so luong sinh vien > 0: ";cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"Nhap sinh vien thu "<<i;
		x = nhap1SV();
		insertDQ(L,x,NULL);
	}
}

void xuat1SV(SV x){
	printf("\n%10s %10s %20s %10.1f",x.stt,x.ma,x.hoten,x.diem);
}

void xuatDSSV(Node *L){
	while(L!=NULL){
		xuat1SV(L->info);
		L = L->next;
	}
}

float tinhdiemTB(Node *L){
	float sum =0;
	int dem=0;
	for (Node *q=L;q!=NULL;q=q->next){
		SV x = q->info;
		sum += x.diem;
		dem++;
	}
	return sum/dem;
}

void xoa(Node *&L){
	if(L!=NULL)
		if(L->info.diem<3){
			Node *p = L;
			L=L->next;
			delete(p);
			xoa(L);
	}else xoa(L->next);
}

void SXGiamTheoDiem(Node *L){
	for(Node *p=L;p->next!=NULL;p=p->next){
		Node *min = p;
		for(Node *q=p->next;q!=NULL;q=q->next){
			if(q->info.diem > min->info.diem){
				min = q;
			}
		}
		SV temp = min->info;
		min->info = p->info;
		p->info = temp;
	}
}

void docFile(char ten[], Node *&L){
	L = NULL;
	FILE *f = fopen(ten,"rb");
	if(f!=NULL){
		while(!feof(f)){
			SV x;
			if(fread(&x,sizeof(SV),1,f)>0){
				insertDQ(L,x,NULL);
			}
		}
		fclose(f);
	}
}

void viThu(Node *L){
	int vt = 1, dem = 1;
	xuat1SV(L->info);
	//cout<<"Vi thu "<<vt;
	Node *p = L->next;
	Node *q = L;
	while(p!=NULL){
		dem++;
		if(p->info.diem < q->info.diem)
			vt = dem;
		q = p;
		xuat1SV(p->info);cout<<"Vi thu: "<<vt;
		p = p->next;
	}
}
/*
void suaDiem(Node *&L){
	Node *p = L;
	while(p!=NULL){
		if(strcmp(p->info.ma,"003")==0) p->info.diem = 10;
		p = p->next;
	}
}
*/

void viThu2(Node *L){
	for(Node *p=L;p!=NULL;p=p->next){
		int dem = 0;
		for(Node *q=L;q!=NULL;q=q->next)
			if(q!=p)
				if(q->info.diem > p->info.diem)
					dem++;
		xuat1SV(p->info);cout<<"Vi thu: "<<dem+1;
	}
}

main(){
	Node *L;
	taoDS(L);
	cout<<"\nDanh sach sinh vien: ";xuatDSSV(L);
	/*
	cout<<"\n\nDiem trung binh chung cua sinh vien: "<<tinhdiemTB(L);
	cout<<"\n\nXoa sinh vien co diem < 3: ";xoa(L);xuatDSSV(L);
	cout<<"\n\nSap xep giam dan theo diem: ";SXGiamTheoDiem(L);xuatDSSV(L);
	cout<<"\n\nSap xep vi thu sinh vien: ";viThu(L),xuatDSSV(L);
	*/
}
