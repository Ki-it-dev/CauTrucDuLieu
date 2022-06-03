#include <iostream>
#include <Math.h>
#include <limits.h>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
int i,j,m,n;
int a[10][10];
//i la hang, j la cot
void nhapMT(){
	cout<<"Nhap so hang : ";cin>>m;
	cout<<"Nhap so cot : ";cin>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			a[i][j] = (rand()%100);
}

void xuatMT(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			cout<<a[i][j]<<"\t";
		cout<<"\n";
	}
}
//Tim gia tri max
int timMax(int a[][10],int n,int m){
	int max = a[1][1];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(max < a[i][j])
				max = a[i][j];
	return max;
}
//Tim hang co tong lon nhat
void maxHang(){
	int max = 0, hang;
	for(int i=1;i<=m;i++){
		int s = 0;
		for(int j=1;j<=n;j++)
			s+= a[i][j];
		if(max < s){
			max = s;
			hang = i;
		}
	}
	cout<<"\nHang co tong lon nhat: ";
	for(int j=1;j<=n;j++)
		cout<<a[hang][j]<<" ";
	cout<<"Tong la = "<<max;
}
//Tim cot co tong nho nhat
int MinCot(int a[][10],int n,int m){
	int min = INT_MAX, s , cot = 0;
	for (int j = 1 ; j <= n ; j++){
		s = 0;
		for (int i = 1 ; i <= m ; i++)
			s += a[i][j];
		if (min > s){
			min = s;
			cot = j;	
		}
	}
	return cot;
}
//Tim mang chua cac gia tri nho nhat tren moi hang
void minNumRow(){
	for(int i=1;i<=m;i++){
		int min = a[i][1];
		for(int j=1;j<=n;j++)
			if(a[i][j] < min)
				min = a[i][j];
		cout<<min<<" ";
	}
}
//Tim mang chua cac gia tri max tren moi cot
void maxNumCol(){
	for(int j=1;j<=n;j++){
		int max = 0;
		for(int i=1;i<=m;i++)
			if(a[i][j] > max)
				max = a[i][j];
		cout<<max<<" ";
	}
}
*/
//Dung mang 1 chieu de luu tru da thuc 1 bien
/*
VD: f(x)= 7x^5 - 6x^3 + 3x - 5
Luu tru: 
C1 : {5,7,0,-6,0,3,-5}
Phan tu dau tien luu bac n cua da thuc
n+1 phan tu tiep theo luu cac he so tu an -> a0
--> Yeu cau: 
1. Nhap da thuc tu ban phim
2. Xuat da thuc ra man hinh
3. Tinh f(x0)
4. Tinh f'(x0)

C2: {7,5,-6,3,3,1,-5,0}
*/

void nhapHeSo(int a[],int n){
	for(int i=n;i>=0;i--){
		cout<<"Nhap he so cua x^"<<i<<" = ";
		cin>>a[i];
	}
}

void xuatHeSo(int a[],int n){
	for(int i=n;i>=0;i--){
		if(i==0){
			cout<<a[i];
		}else
			cout<<a[i]<<"x^"<<i<<" + ";
	}	
}

int tinhFx(int a[],int n,int x){
	int s = 0;
	for(int i=n;i>=0;i--){
		s += a[i]*pow(x,i);
	}
	return s;
}

int tinhDaoHam(int a[],int n,int  x){//2x^2 + 3x^1 + 5 => f' = 4x^1 + 3x || x = 3
	int s = a[1];
	int xMuJ = 1;
	for(int i=2;i<=n;i++){
		xMuJ *= x;
		s += a[i] * i * xMuJ;
	}
	return s;
}

int main(int argc, char** argv) {
	/*
	nhapMT();
	xuatMT();
	cout<<"\nGia tri lon nhat co trong ma tran : "<<timMax(a,n,m);
	maxHang();
	cout<<"\nCot co tong nho nhat : "<<MinCot(a,n,m);
	cout<<"\nMang chua cac gia tri max tren moi cot : ";maxNumCol();
	cout<<"\nMang chua cac gia tri nho nhat tren moi hang: ";minNumRow();
	*/
	
	int n,a[100],x;
	cout<<"Nhap bac cua da thuc : ";cin>>n;
	nhapHeSo(a,n);
	cout<<"Phuong trinh : ";
	xuatHeSo(a,n);
	cout<<"\nNhap gia tri x = ";cin>>x;
	cout<<"f("<<x<<")="<<tinhFx(a,n,x);
	cout<<"\nDao ham f'("<<x<<")= "<<tinhDaoHam(a,n,x);
	return 0;
}

