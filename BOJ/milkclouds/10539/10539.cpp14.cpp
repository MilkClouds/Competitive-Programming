#include <iostream>
using namespace std;
long long N,c,p;
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>c;
		cout<<c*i-p<<" ";
		p=c*i;
	}
}