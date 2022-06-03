#include<iostream>
#include<string.h>
using namespace std;
struct SV{
	char ma[15], hoTen[30], queQuan[30], ngaySinh[10];
	int gioiTinh;
	float dtb;	
};
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
void nhapMangSV(SV a[], int n){
	for(int i=0; i<n; i++){
		cout<<"Nhap sinh vien thu"<<i+1<<":\n";
		a[i] = nhap1SV();
	}
}

void xuat1SV(SV x){
	printf("\n%12s %20s %20s %10s %5s %3.1f",x.ma,x.hoTen,x.queQuan,x.ngaySinh,((x.gioiTinh==1)?"Nam":"Nu"),x.dtb);
}
void xuatMangSV(SV a[], int n){
	for(int i=0; i<n; i++)
		xuat1SV(a[i]);
}
void congDiem(SV a[], int n){
	for(int i=0; i<n; i++)
		if(strcmp(a[i].queQuan,"Nghe An")==0)
			a[i].dtb = a[i].dtb+0.5;
}
SV max(SV a[], int n){
	SV x= a[0];
	for(int i=1; i<n; i++)
		if(x.dtb<a[i].dtb)
			x = a[i];
	return x;
}
float diemTBC(SV a[], int n){
	float s=0;
	for(int i=1; i<n; i++)
			s = s+ a[i].dtb;
	return s/n;
}
float diemTBCNam(SV a[], int n){
	float s=0, dem=0;
	for(int i=0; i<n; i++)
		if(a[i].gioiTinh==1){
			s = s+ a[i].dtb;
			dem++;
		}
	if(dem==0) return 0;		
	else return s/dem;
}
float diemTBCNu(SV a[], int n){
	float s=0, dem=0;
	for(int i=0; i<n; i++)
		if(a[i].gioiTinh==0){
			s = s+ a[i].dtb;
			dem++;
		}
	if(dem==0) return 0;		
	else return s/dem;
}
void loai(SV a[], int &n, int k){
	for(int j=k; j<n; j++)
		a[j] = a[j+1];
	n--;
}
void loaiSVKem(SV a[], int &n){
	int i=0; 
	float diem = diemTBC(a,n);
	while(i<n)
		if(a[i].dtb<diem)
			loai(a,n,i);
		else i++;
}
void giamTheoDiem(SV a[], int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].dtb<a[j].dtb){
				SV x= a[i];
				a[i] = a[j];
				a[j] = x;
			}
}
void viThu(SV a[], int n){
	int vt=1;
	xuat1SV(a[0]); cout<<" vi thu "<<vt;
	for(int i=1; i<n ; i++){
		if(a[i].dtb<a[i-1].dtb)
			vt=i+1;
		xuat1SV(a[i]); cout<<" vi thu "<<vt;
	}	
}
void ghiFile(char ten[], SV a[], int n){
	FILE *f=  fopen(ten,"wb");
	if(f!=NULL){
		fwrite(a,sizeof(SV),n,f);
		fclose(f);
	}
}
void docFile(char ten[], SV a[], int &n){
	FILE *f=  fopen(ten,"rb");
	if(f!=NULL){
		fseek(f,0,2);
		n = ftell(f)/ sizeof(SV);
		fseek(f,0,0);
		fread(a,sizeof(SV),n,f);
		fclose(f);
	}
}

main(){
	cout<<" Luu van Hien CS211A";
	SV a[100];
	int n;
	//cout<<"Nhap n>0:";
	//cin>>n;
	//nhapMangSV(a,n);
	docFile("SV.Dat",a,n);
	xuatMangSV(a,n);
	//ghiFile("SV.Dat",a,n);
	//congDiem(a,n);
	//cout<<endl;
	//xuatMangSV(a,n);
}
