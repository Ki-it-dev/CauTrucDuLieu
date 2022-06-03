#include <iostream>
#include <math.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long gt(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * gt(n - 1);
}
long F(int n)
{
	long s = 1;
	while (n > 0)
	{
		s *= n;
		n--;
	}
	return s;
}
//Bai1 : 1 + 1/2 + ... + 1/n
double ques1(int n)
{
	if (n == 0)
		return 0;
	return 1.0 / n + ques1(n - 1);
}
double ques1W(int n)
{
	double s = 0;
	while (n > 0)
	{
		s += 1.0 / n;
		n--;
	}
	return s;
}
//Bai2: 1 - 1/2 + 1/3 - ... + (-1)^(n+1)/n
double ques2(int n)
{
	if (n == 0)
		return 0;
	return pow((-1), n + 1) / n + ques2(n - 1);
}
double ques2W(int n)
{
	double s = 0;
	while (n > 0)
	{
		s += pow((-1), n + 1) / n;
		n--;
	}
	return s;
}
//Bai3: 1 + 2 + 3 + ... + n
int ques3(int n)
{
	if (n == 0)
		return 0;
	return n + ques3(n - 1);
}
int ques3W(int n)
{
	int s = 0;
	while (n > 0)
	{
		s += n;
		n--;
	}
	return s;
}
//Bai4 : 1 + 3 + 5 + ... + (2k+1) voi 2k+1 <= n
int ques4(int n)
{
	if (n <= 1)
		return n;
	if (n % 2 == 0)
		return ques4(n - 1);
	return n + ques4(n - 2);
}
int ques4W(int n)
{
	int s = 0;
	if (n % 2 == 0)
	{
		n--;
	}
	while (n >= 1)
	{
		s += n;
		n -= 2;
	}
	return s;
}
//Fibonacci
int Fibonacci(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return (Fibonacci(n - 1) + Fibonacci(n - 2));
}
//Tim UCLN cua a va b
int UCLN(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	return UCLN(b, a % b);
}
//Tinh 2^n
int soMu(int n)
{
	if (n == 0)
		return 1;
	return pow(2, n - 1) + pow(2, n - 1);
}
//Tinh x^y
int xMuY(int x, int y)
{
	if (y == 0)
		return 1;
	return xMuY(x, y - 1) * x;
}
//Chia nguyen cua 2 so nguyen duong
int chiaNguyen(int a, int b)
{
	/*
	if (a * b < 0)
		return 0;
	return a / b;
	*/
	if (a < b)
		return 0;
	return 1 + chiaNguyen(a - b, b);
}
//Chia du cua 2 so nguyen duong
int chiaDu(int a, int b)
{
	/*
	if (a * b < 0)
		return 0;
	return a % b;
	*/
	if (a < b)
		return a;
	return chiaDu(a - b, b);
}
//Tong cac chu so cua 1 so nguyen duong
int sumNum(int n)
{
	if (n == 0)
		return 0;
	return n % 10 + sumNum(n / 10);
}

//Mang

//tong cac gia tri tren mang
int sumArray(int a[], int n)
{
	if (n == 0)
		return 0;
	return a[n - 1] + sumArray(a, n - 1);
}

//tong cac gia tri chan
int sumEvenArray(int a[], int n)
{
	if (n == 0)
		return 0;
	else if (a[n - 1] % 2 == 0)
		return a[n - 1] + sumEvenArray(a, n - 1);
	else
		return sumEvenArray(a, n - 1);
}

//GTLN tren mang
int maxNumArray(int a[], int n)
{
	if (n == 0)
		return -1;
	if (n == 1)
		return a[0];
	else
	{
		if (a[n - 1] > maxNumArray(a, n - 1))
			return a[n - 1];
		else
			return maxNumArray(a, n - 1);
	}
}
int maxNumArray1(int a[], int n){
	if(n==1)
		return a[0];
	else{
		int x = maxNumArray1(a,n-1);
		if(a[n - 1]>x)
			return a[n - 1];
		return x;
	}
}
int maxNumArray2(int a[], int n){
	int m = a[0];
	for(int i=1;i<n;i++)
		if(a[i]>m)
			m = a[i];
	return m;
}
//Tim 2 phan tu lien tiep co tong lon nhat tren mang
int sumMax(int a[], int n)
{
	
}
//Kiem tra tinh tang cua mang
bool up(int a[], int n)
{
}

//----------------------------------------------------------------------------------------------------
//Dao nguoc so
void daoNguoc(int x){
	if(x>0){
		cout<<x%10;
		daoNguoc(x/10);
	}
}
//Doi so nguyen n he 10 --> he 2
void doiSangHe2(int x){
	if(x>0){
		doiSangHe2(x/2);
		cout<<x%2;
	}
}
//Doi he 10 --> he n
void doiHe(int x,int he){
	if(x>0){
		doiHe(x/he,he);
		int du = x%he;
		if(du<10)
			cout<<du;
		cout<<(char)(du+55);
		//'A' : 65, 'B':65
	}
}
int main(int argc, char **argv)
{	/*
	int a[100];
	int n = 100;

	for(int i=0;i<n;i++)
		a[i] = rand();
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";

	cout << "\nTong cac gia tri trong mang : " << sumArray(a, n) << endl;
	cout << "Tong cac gia tri chan trong mang : " << sumEvenArray(a, n) << endl;
	cout << "GTLN tren mang = de quy: " << maxNumArray1(a, n) << endl;
	cout << "GTLN tren mang = vong lap: " << maxNumArray2(a, n) << endl;
	*/

	/*
	int x;cout<<"\nNhap so dao nguoc : ";cin>>x;
	cout<<"So dao nguoc:";daoNguoc(x);
	cout<<"\nDoi "<<x<<" sang he 2:";doiSangHe2(x);
	*/

	int a,b;
	cout<<"\nNhap so de doi : ";cin>>a;
	cout<<"Nhap he de doi : ";cin>>b;
	cout<<"He 10 --> he "<<b<<" la: ";doiHe(a,b);

	/*
	int n;
	cout << "Nhap n : ";
	cin >> n;

	cout << "Bai1: " << ques1(n) << " , " << ques1W(n) << endl;
	cout << "Bai2: " << ques2(n) << " , " << ques2W(n) << endl;
	cout << "Bai3: " << ques3(n) << " , " << ques3W(n) << endl;
	cout << "Bai4: " << ques4(n) << " , " << ques4W(n) << endl;
	cout << "Fibonacci cua " << n << " : " << Fibonacci(n) << endl;
	cout << "2^" << n << " = " << soMu(n) << endl;
	cout << "Tong cac chu so cua 1 so nguyen duong : " << sumNum(n) << endl;

	int x, y;
	cout << "Nhap x va y : ";
	cin >> x >> y;
	cout << x << "^" << y << " : " << xMuY(x, y) << endl;

	int a, b;
	cout << "Nhap a va b : ";
	cin >> a >> b;
	cout << "UCLN cua " << a << " va " << b << " la :" << UCLN(a, b) << endl;
	cout << "Chia du cua 2 so nguyen duong: " << chiaDu(a, b) << endl;
	cout << "Chia nguyen cua 2 so nguyen duong: " << chiaNguyen(a, b) << endl;
	*/
	return 0;
}
