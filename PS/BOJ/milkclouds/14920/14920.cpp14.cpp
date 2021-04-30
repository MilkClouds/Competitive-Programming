#include <iostream>
using namespace std;
int main(){
	int n,idx=1;
	cin>>n;
	while(n!=1){
		idx++;
		n=n&1 ? 3*n+1 : n/2;
	}
	cout<<idx;
}