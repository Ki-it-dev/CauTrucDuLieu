#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

struct stack{
	Node *top;
};

void createS(stack &s){
	s.top == NULL;
}

int emptyS(stack s){
	return s.top == NULL;
}

void push(int x,stack &s){
	Node *q = new Node;
	q->data = x;
	q->next = s.top;
	s.top = q;
}

int top(stack s){
	return s.top->data;
}

void pop(stack &s){
	if(s.top !=NULL){
		Node *p = s.top;
		s.top = p->next;
		delete(p);
	}
}

int main(){
	int n,x;
	do{
		cout<<"Nhap n>0: ";cin>>n;
	}while(n<=0);
	return 0;
}
