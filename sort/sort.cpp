#include <iostream>
#include <time.h>
#include <limits.h>

using namespace std;

void BubbleSort(long a[],int n){
	int i,j,t;
	for(i=1;i<=n-1;i++)
		for(j=n;j>=i+1;j--)
			if(a[j] < a[j-1]){
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
}

int position(long a[],int l,int r){
	int x = a[l];
	int i = l+1;
	int j = r;
	while(i<j){
		while(a[i]<x) i++;
		while(a[j]>=x) j--;
		if(i<j)
			a[i] = a[j];
	}
	a[l] = a[j];
	return j;
}

void quickSort(long a[],int l,int r){
	if(l<r){
		int pos = position(a,l,pos-1);
		quickSort(a,l,pos-1);
		quickSort(a,pos+1,r);
	}
}

int xuat(long a[],int n){
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
}

void docfile(long a[],int n){
    FILE *f;
    f=fopen("songuyen.txt","rt");
    for(int i=1;i<=n;i++)
        fscanf(f,"%ld",&a[i]);
    fclose(f);
}


main(){
	long a[10000];
	int n = 10000;
	docfile(a,n);
		
	clock_t start, end;
	start = clock();
	
	BubbleSort(a,n);
	//xuat(a,n);
	
	end = clock();
	double t = (double)(end-start);
	
	cout<<"\nThoi gian thuc hien noi bot (n^2): "<<t<<endl;
	
	clock_t start2, end2;
	start2 = clock();
	
	quickSort(a,1,n);
	//xuat(a,n);
	
	end2 = clock();
	double t2 = (double)(end2-start2);
	
	cout<<"\nThoi gian thuc hien quicksort (nlogn): "<<t2<<endl;
	
	
	return 0;
}
