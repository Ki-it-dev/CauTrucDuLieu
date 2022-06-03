#include <iostream>
using namespace std;

struct stack{
	int A[101];
	int top;
};

void CreateS(stack &S){
	S.top = 0;
}

int EmptyS(stack S){
	return S.top==0;
}
	
void Push(int x,stack &S){
	if(S.top<100){
		S.top++;
		S.A[S.top]=x;
	}
}
	
void Pop(stack &S){
	if(S.top>0)
		S.top--;
}
	
int Top(stack &S){
	return S.A[S.top];
}

int count(stack S){
	int dem = 0;
	stack S1; CreateS(S1);
	while (!EmptyS(S)){
		Push(Top(S),S1);
		dem++;
		Pop(S);
	}
	while(!EmptyS(S1)){
		Push(Top(S1),S);
		Pop(S1);
	}
	return dem;
}

void daoNguocStack(stack S){
	stack S1,S2; 
	CreateS(S1);
	CreateS(S2);
	while (!EmptyS(S)){
		Push(Top(S),S1);		
		Pop(S);
	}
	while(!EmptyS(S1)){
		Push(Top(S1),S2);
		Pop(S1);
	}
	while(!EmptyS(S2)){
		Push(Top(S2),S);
		Pop(S2);
	}
	while(!EmptyS(S)){
		cout<<Top(S)<<" ";
		Pop(S);
	}
}

void xuatStack(stack S){
	while(!EmptyS(S)){
		cout<<Top(S)<<" ";
		Pop(S);
	};
}

int main(){
	int n,x;
	stack S;
	CreateS(S);
	do{
		cout<<"Nhap n >0 :" ;cin>>n;
	}while(n<=0);
	cout<<"Nhap n so: ";
	for(int i=1;i<=n;i++){
		cin>>x;
		Push(x,S);
	}
	cout<<"Stack co trong danh sach: ";xuatStack(S);
	cout<<"\nSo phan tu co trong stack:"<<count(S);
	cout<<"\nDao nguoc danh sach: ";daoNguocStack(S);
}
