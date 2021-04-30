#include <iostream>
using namespace std;

int n,v=1000,V,t;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		v=min(v,t);V=max(V,t);
	}
	cout<<V-v;
}