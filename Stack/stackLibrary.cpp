#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	stack<int> s;
	cout<<"Nhap n: ";cin>>n;
	cout<<"Nhap "<<n<<" so nguyen: ";
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		s.push(x);
	}while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

