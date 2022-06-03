#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

struct Queue{
	Node *front, *rear;
};

void CreateQ(Queue &Q){
	Q.front = Q.rear = NULL;
}

int EmptyQ(Queue &Q){
	return Q.front == NULL;
}

void PushQ(int x,Queue &Q){
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	if(Q.front == NULL)
		Q.rear == p;
	else
		Q.rear->next = p;
	Q.rear = p;
}

void PopQ(Queue &Q){
	if(Q.front!=NULL){
		Node *p = Q.front;
		Q.front = p->next;
		delete p;
	}
	if(Q.front==NULL)
		Q.rear = NULL;
}

int Front(Queue Q){
	return Q.front->data;
}

main(){
	Queue q;
	CreateQ(q);

	PushQ(10,q);
	PushQ(20,q);
	PushQ(30,q);
	PushQ(40,q);
	
	while(!EmptyQ(q)){
		cout<<Front(q)<<" ";
		PopQ(q);
	}cout<<"\n";
	
	return 0;
}


