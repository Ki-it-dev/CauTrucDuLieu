#include <iostream>
#include <math.h>
#include<queue>
using namespace std;

struct Tree{
	int info;
	Tree *left,*right;
};

Tree *tao(int x,Tree *l,Tree *r){
	Tree *p = new Tree;
	p->info = x;
	p->left = l;
	p->right= r;
	return p;
}

void taoCay(Tree *&T){
	Tree *q = tao(15,tao(6,NULL,NULL),tao(6,tao(2,NULL,NULL),tao(12,tao(33,NULL,tao(17,NULL,NULL)),NULL)));
	Tree *p = tao(13,NULL,tao(20,tao(11,NULL,NULL),tao(3,NULL,NULL)));
	T = tao(10,q,p);
}

//NLR
void NLR(Tree *t){
	if(t!=NULL){
		cout<<t->info<<" ";
		NLR(t->left);
		NLR(t->right);
	}
}

int tongNodeChan(Tree *t){
	int s = 0;
	if(t!=NULL){
		if(t->info % 2 ==0)
			s += t->info;
		s += tongNodeChan(t->left);
		s += tongNodeChan(t->right);
	}
	return s;
}

void lietkeLa(Tree *t){
	if(t!=NULL){
		if(t->right == NULL && t->left == NULL)
			cout<<t->info<<" ";
		lietkeLa(t->left);
		lietkeLa(t->right);
	}
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
    if(x>9){
		if (x == SDX(x)) return 1;
	}
    return 0;
}

int isSNT(int x){
	if(x<2) return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}

int tongSDX(Tree *t){
	if(t!=NULL){
		int a= tongSDX(t->left);
		int b= tongSDX(t->right);
		if(isSDX(t->info)==1)return t->info+a+b;
		return a+b;
	}
	return 0;
}

void lietkeSNT(Tree *t){
	if(t!=NULL){
		if(isSNT(t->info)==1){
			cout<<t->info<<" ";
		}
		lietkeSNT(t->left);
		lietkeSNT(t->right);
	}
}

void slSNT(Tree *t,int &dem){
	if(t!=NULL){
		if(isSNT(t->info)==1){
			dem++;
		}
		slSNT(t->left,dem);
		slSNT(t->right,dem);
	}
}

int tongSNT(Tree *t){
	if(t!=NULL){
		int a= tongSNT(t->left);
		int b= tongSNT(t->right);
		if(isSNT(t->info)==1)return t->info+a+b;
		return a+b;
	}
	return 0;
}

int timMax(Tree *t){
	if(t->left == NULL && t->right == NULL)
		return t->info;
	int max = t->info;
	if(t->left!=NULL){
		int left = timMax(t->left);
		if(max < left){
			max = left;
		}
	}
	if(t->right!=NULL){
		int right = timMax(t->right);
		if(max < right){
			max = right;
		}
	}
	return max;
}

int timMin(Tree *t){
	if(t->left == NULL && t->right == NULL)
		return t->info;
	int min = 32769;
	if(t->left!=NULL){
		int left = timMin(t->left);
		if(min > left){
			min = left;
		}
	}
	if(t->right!=NULL){
		int right = timMin(t->right);
		if(min > right){
			min = right;
		}
	}
	return min;
}

bool duyetX(Tree *T, int x){
	queue<Tree*> q;
	q.push(T);
	while(!q.empty()){
		Tree *t=q.front();
		q.pop();
		if((t->info)==x) return true;
		if(t->left!=NULL) q.push(t->left);
		if(t->right!=NULL) q.push(t->right);
	}
	return false;
}

main(){
	Tree *root;
	int dem = 0;
	int x;
	taoCay(root);
	cout<<"Le Huu Nhat Khoa\n";
	cout<<"NLR: ";NLR(root);
	cout<<"\nTong cac so chan: "<<tongNodeChan(root);
	cout<<"\nNode la = ";lietkeLa(root);
	cout<<"\nTong SDX = "<<tongSDX(root);
	slSNT(root,dem);
	cout<<"\nTBC SNT = ";cout<<double(1.0*tongSNT(root)/dem);
	cout<<"\nMax = "<<timMax(root);
	cout<<"\nMin = "<<timMin(root);
	cout<<"\nNhap so can tim: "; cin>>x;
	if(duyetX(root, x)) cout<<x<<": Yes";
	else cout<<x<<": NO";
}
