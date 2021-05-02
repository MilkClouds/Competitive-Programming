#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,t;
int dec_oct(int n){
	int ret=0,idx=1;
	while(n){
		if(n%10==9 or n%10==8) return 0;
		ret+=idx*(n%10);
		n/=10;idx*=8;
	}
	return ret;
}
int dec_hex(int n){
	int ret=0,idx=1;
	while(n){
		ret+=idx*(n%10);
		n/=10;idx*=16;
	}
	return ret;
}
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>n;
	for (int i = 0; i <= n; ++i)
	{
		cin>>i>>t;
		cout<<i<<" "<<dec_oct(t)<<" "<<t<<" "<<dec_hex(t)<<"\n";
	}
	return 0;
}