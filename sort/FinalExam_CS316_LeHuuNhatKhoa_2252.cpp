#include <iostream>
#include <stdlib.h>
#include <string.h>

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

void nhap1SV(Node *L){
	SV x;
	cout<<"\nNhap them 1 sinh vien: ";
	x = nhap1SV();
	insertDQ(L,x,NULL);
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
	printf("\n%10s %10s %20s %10s","STT","MSV","Ho va ten","Diem TB");
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

void sapXepChon(Node *L){
	for(Node *p=L;p->next!=NULL;p=p->next){
		Node *min = p;
		for(Node *q=p->next;q!=NULL;q=q->next){
			if(q->info.diem > min->info.diem){
				min = q;
			}
		}
		if(min!=p){
			SV temp = min->info;
			min->info = p->info;
			p->info = temp;
		}
	}
}

void xoa(Node *&L){
	if(L!=NULL)
		if(L->info.diem<5){
			Node *p = L;
			L=L->next;
			delete(p);
			xoa(L);
	}else xoa(L->next);
}

void xuatSVTXL(SV x,int i){
	char *hl;
	if(x.diem<0||x.diem>10){
		hl="Diem trung binh khong phu hop!!!";
	}else{
		if(x.diem<5) hl = "Yeu";
		else if(x.diem<6.5 && x.diem>=5) hl = "Trung binh";
		else if(x.diem<8 && x.diem >=6.5) hl = "Kha";
		else if (x.diem>=8) hl = "Gioi";
	}
	printf("\n%10s %10s %20s %10.1f %10s",x.stt,x.ma,x.hoten,x.diem,hl);
}

void xuatDSSVTXL(Node *L){
	printf("\n%10s %10s %20s %10s %10s","STT","MSV","Ho va ten","Diem TB","Xep Loai");
	int count =1;
	while(L != NULL){
		xuatSVTXL(L->info, count);
		L = L->next;
		count++;
	}
}

main(){
	cout<<"Le Huu Nhat Khoa - 2252 - CS316E\n";
	Node *L;
	taoDS(L);
	
	cout<<"\nDanh sach sinh vien: ";xuatDSSV(L);
	
	cout<<"\nSap xep giam dan diem trung binh: ";sapXepChon(L);xuatDSSV(L);
	nhap1SV(L);sapXepChon(L);xuatDSSV(L);
	cout<<"\nXep loai danh sach sinh vien: ";xuatDSSVTXL(L);
	cout<<"\nXoa sinh vien co xep loai yeu: ";xoa(L);xuatDSSVTXL(L);
	
}
