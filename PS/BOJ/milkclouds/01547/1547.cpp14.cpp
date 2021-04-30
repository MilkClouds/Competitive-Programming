#include <iostream>
using namespace std;

int main(){
	int m,a,b,c=1;
	cin>>m; 
	while(m--){
		cin>>a>>b;
		if(a==c)c=b;
		else if(b==c)c=a;
	}
	cout<<c;
}