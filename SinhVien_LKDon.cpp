#include<iostream>
#include<string.h>
using namespace std;
struct SV{
	char ma[15], hoTen[30], queQuan[30], ngaySinh[10];
	int gioiTinh;
	float dtb;	
};
struct Node{
	SV info;
	Node *next;
};
void chen(Node *&l, SV x, Node *p){
	if(l==p){
		l = new Node;
		l->info = x;
		l->next =p;
	}else chen(l->next,x,p);
}
SV nhap1SV(){
	SV x;
	cout<<"Nhap ma:"; fflush(stdin); gets(x.ma);
	cout<<"Nhap ho ten:"; fflush(stdin); gets(x.hoTen);
	cout<<"Nhap que quan :"; fflush(stdin); gets(x.queQuan);
	cout<<"Nhap ngay sinh (dd/mm/yyyy):"; fflush(stdin); gets(x.ngaySinh);
	cout<<"Nhap gioi tinh (1:nam,0: nu):"; cin>>x.gioiTinh;
	cout<<"Nhap diem : "; cin>>x.dtb;
	return x;
}
void taoDS(Node *&l){
	l =NULL;
	SV x;
	int n;
	cout<<"Nhap so luong SV >0:";
	cin>>n;
	for(int i=1; i<=n; i++){
		cout<<"Nhap sinh vien thu "<<i;
		x = nhap1SV();
		chen(l,x,NULL);
	}
}

void xuat1SV(SV x){
	printf("\n%12s %20s %20s %10s %5s %3.1f",x.ma,x.hoTen,x.queQuan,x.ngaySinh,((x.gioiTinh==1)?"Nam":"Nu"),x.dtb);
}
void xuatDSSV(Node *l){
	while(l!=NULL){
		xuat1SV(l->info);
		l = l->next;
	}
}
void docFile(char ten[], Node *&L){
	L = NULL;
	FILE *f=  fopen(ten,"rb");
	if(f!=NULL){
		while(!feof(f))
		{
			SV x;
			if(fread(&x,sizeof(SV),1,f)>0){
				chen(L,x,NULL);
			}
		}
		fclose(f);
	}
}

float diemTBChung(Node *l){
	float s =0, dem=0;
	for(Node *p=l; p!=NULL; p=p->next){
		s = s + p->info.dtb;
		dem++;
	}
	return s/dem;
}
void xoaSVKem1(Node *&l){
	float dtbchung = diemTBChung(l);
	Node *l1= NULL;
	while(l!=NULL){
		Node *p = l;
		l=l->next;
		if(p->info.dtb >= dtbchung)
			chen(l1,p->info,NULL);
		delete (p);
	}
	l = l1;
}
void xoa(Node *&l, Node*p){
	if(l!=NULL)
		if(l==p) {
			l=l->next;
			delete(p);
		}else xoa(l->next,p);
}
void xoaSVKem(Node *&l){
	Node *p=l;
	float dtbchung = diemTBChung(l);
	while(p!=NULL)
		if(p->info.dtb<dtbchung){
			Node *q = p->next;
			xoa(l,p);
			p=q;
		}else p=p->next;
}
void sapXep(Node *l){
	for(Node *p=l; p->next!=NULL; p=p->next)
		for(Node *q=p->next; q!=NULL; q=q->next){
			if(p->info.dtb<q->info.dtb){
				SV x = p->info;
				p->info = q->info;
				q->info = x;
			}
		}
}
void xacDinhViThu1(Node *l){ // tren ds da sap xep
	int vt=1, dem=1;
	xuat1SV(l->info); cout<<" vi thu "<<vt;
	Node *p=l->next, *q=l;
	while(p!=NULL){
		dem++;
		if(p->info.dtb<q->info.dtb) vt=dem;
		q= p;
		xuat1SV(p->info); cout<<" vi thu "<<vt;
		p=p->next;
	}	
}
void suaDiem(Node *l){
	Node *p=l;
	while(p!=NULL){
		if(strcmp(p->info.ma,"003")==0) p->info.dtb = 9.5;
		if(strcmp(p->info.ma,"002")==0) p->info.dtb = 8.8;
		if(strcmp(p->info.ma,"005")==0) p->info.dtb = 8.8;
		p=p->next;
	}
}
void xacDinhViThu2(Node *l){
	for(Node *p=l; p!=NULL; p=p->next){
		int dem=0;
		for(Node *q=l; q!=NULL; q=q->next)
			if(q!=p)
				if(q->info.dtb>p->info.dtb)
					dem++;
		xuat1SV(p->info); cout<<" vi thu "<<dem+1;	
	}
		
}
main(){
	Node *l;
	//taoDS(l);
	docFile("SV.Dat",l);
	xuatDSSV(l);
//	cout<<"\n diem TBC ="<<diemTBChung(l);
//	xoaSVKem1(l);
	suaDiem(l);
	//sapXep(l);
	//cout<<"\n ds sv sau sap xep:\n";
	
	//xuatDSSV(l);
	xacDinhViThu2(l);
}
