#include<iostream>
#include<stack>
using namespace std;

void doiHe(int n,int he){
	stack<int> a;
	while(n!=0){
		a.push(n%he);
		n=n/he;
	}while(!a.empty()){
		int x = a.top();a.pop();
		if(x<10) cout<<x;
		else cout<<(char)(x+55);
	}
}

struct HN{
	int sd;
	char ng,dich,tg;
};

HN gan(int n,char a,char c,char b){
	HN x;
	x.sd=n;x.ng=a;x.dich=c;x.tg=b;
	return x;
}
void thapHN(int n,char a,char c,char b){
	HN x = gan(n,a,c,b);
	stack<HN> s;
	s.push(x);
	while(!s.empty()){
		HN x = s.top();s.pop();
		if(x.sd==1) cout<<"\n"<<x.ng<<" ==> "<<x.dich;
		else{
			HN y = gan(x.sd-1,x.tg,x.dich,x.ng);s.push(y);
			y=x; y.sd=1; s.push(y);
			y = gan(x.sd-1,x.ng,x.tg,x.dich);s.push(y);
		}
	}
}

int main(){
	/*
	int n,he;
	do{
		cout<<"Nhap n>0: ";cin>>n;
	}while(n<=0);
	cout<<"Nhap he can doi: ";cin>>he;
	doiHe(n,he);
	*/
	thapHN(3,'A','C','B');
}
