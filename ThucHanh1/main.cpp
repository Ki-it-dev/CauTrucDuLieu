#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void nhapMang(int a[],int n){
	for(int i=0;i<n;i++)
		a[i]=(int)(rand()*0.001);
}

void xuatMang(int a[],int n){
	if(n==0)
		return;
    xuatMang(a,n-1);
    cout<<" "<<a[n-1];
}

int sumEvenArray(int a[], int n){
	if (n == 0)
		return 0;
	else if (a[n - 1] % 2 == 0)
		return a[n - 1] + sumEvenArray(a, n - 1);
	else
		return sumEvenArray(a, n - 1);
}

int maxNumArray(int a[], int n){
	if(n==1)
		return a[0];
	else{
		int x = maxNumArray(a,n-1);
		if(a[n - 1]>x)
			return a[n - 1];
		return x;
	}
}

int maxLT(int a[],int n){
	if(n==2) return a[n-1]+a[n-2];
	else{
		int x = maxLT(a,n-1);
		if(x>a[n-1]+a[n-2]) 
			return x;
		return a[n-1]+a[n-2];
	}
}

int checkSNT(int x){
	if (x < 2)
        return 1;
    for (int i = 2; i <= sqrt(x); i++){
        if (x % i == 0){
            return 1;
        }
    }
    return 0;
}

void lietKeSoNguyenTo(int a[],int n,int i){
	if (i==n) return;
	if (checkSNT(a[i]) == 0)
		cout<< a[i]<<"\t";
	lietKeSoNguyenTo(a,n,i+1);
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

int sumSDX(int a[],int n){
	if(n==0) return -1;
	if (n == 1)	return a[0];
	else{
		if (isSDX(a[n-1]) == 1){
			return a[n-1] + sumSDX(a,n-1);
		}
	return sumSDX(a,n-1);
	}
}


void lietKeSDX(int a[],int n,int i){
	if (i==n) return;
	if (isSDX(a[i]) == 1)
		cout<<a[i]<<"\t";
	lietKeSDX(a,n,i+1);
}

int sumNum(int n){
	if(n==0) return 0;
	return n%10 + sumNum(n/10);
}

void lietKeSoLonHon10(int a[], int n,int i){
	if (i==n) return;
	if (sumNum(a[i]) > 10)
		cout<< a[i]<<"\t";
	lietKeSoLonHon10(a,n,i+1);
}

//Kiem tra tinh khong giam cua mang
int Tangdan(int a[],int n){
	if(n<1) return 1;
	else if(a[n-1]<a[n-2]) return 0;
	else return Tangdan(a,n-1);
}
//SX xep mang tang dan
void hoanVi(int &a,int &b){
	int t = a; a = b; b = t;
}

void sapXepTangDan(int a[],int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				hoanVi(a[i],a[j]);
}

void sortDeQuy(int a[],int i,int j,int n){
	if(i<n-1){
		if(j<n){
			if(a[i]>a[j])
				hoanVi(a[i],a[j]);
			sortDeQuy(a,i,j+1,n);
		}
		sortDeQuy(a,i+1,i+1,n);
	}
}

//Tim gia tri x dau tien trong mang
int find(int a[],int n,int x){
	if(n==0) return -1;
	else if(a[n-1]==x)
		return n-1;
	return find(a,n-1,x);
}

//Chen
void chenX(int a[],int &n,int x,int k){
	for(int i=n;i>k;i--)
		a[i] = a[i-1];
	a[k] = x;
	n++;
}

void chenDeQuy(int a[],int &n,int x,int k){
	if(n>k){
		a[n] = a[n-1];
		int m = n-1;
		chenDeQuy(a,m,x,k);
	}else a[k]=x;
	n++;
}
//Xoa
void xoa(int a[],int &n,int k){
	for(int i=k;i<n;i++)
		a[i] = a[i+1];
	n--;
}

void xoaDeQuy(int a[],int &n,int k){
	if(k<n){
		a[k] = a[k+1];
		xoaDeQuy(a,n,k+1);
	}
	else n--;
}

int main(int argc, char** argv) {
	int a[100],n,i,j,x,k;
	cout<<"Nhap n >0 : ";cin>>n;
	nhapMang(a,n);
	cout<<"1. Cac so vua tao : ";
	xuatMang(a,n);
	/*
	cout<<"\n2.Tong chan : "<<sumEvenArray(a,n)<<endl;
	cout<<"3.Max = "<<maxNumArray(a,n)<<endl;
	cout<<"4.So doi xung: ";lietKeSDX(a,n,i);
	cout<<"\nTong SDX : "<<sumSDX(a,n);
	cout<<"\n5.SNT: ";lietKeSoNguyenTo(a,n,i);
	cout<<"\n6.Cac so co tong chu so > 10: ";lietKeSoLonHon10(a,n,i);
	cout<<"\n7. Tong lien tiep lon nhat : "<<maxLT(a,n);
	*/
	/*
	cout<<"\nSap xep mang tang dan :";
	sapXepTangDan(a,n);xuatMang(a,n);
	cout<<"\nSap xep mang tang dan = de quy : ";
	sortDeQuy(a,i,j,n);xuatMang(a,n);
	*/
	//----------------------------Them xoa sua -----------------------------//
	cout<<"\nNhap x : ";cin>>x;
	cout<<"\nNhap vi tri : ";cin>>k;
	//chenX(a,n,x,k);xuatMang(a,n);
	cout<<endl;
	//chenDeQuy(a,n,x,k);xuatMang(a,n);
	
	//xoa(a,n,k);xuatMang(a,n);
	cout<<endl;
	xoaDeQuy(a,n,k);xuatMang(a,n);
	//---------------------------------------------------------------------//
	
	cout<<"\nTinh tang dan : "<<Tangdan(a,n);
	
	//cout<<"\nGia tri can tim "<<x<<" : "<<find(a,n,x);
	return 0;
}
