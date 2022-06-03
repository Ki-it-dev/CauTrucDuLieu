#include <iostream>
using namespace std;

struct stack{
	int a[101];
	int top;
};

void createS(stack &s){
	s.top = 0;
}

int emptyS(stack s){
	return s.top == 0;
}

void push(int x, stack &s){
	if(s.top<100){
		s.top++;
		s.a[s.top]=x;
	}
}

void pop(stack &s){
	if(s.top>0)
		s.top--;
}

int top(stack s){
	return s.a[s.top];
}

int main(){	
	return 0;
}
