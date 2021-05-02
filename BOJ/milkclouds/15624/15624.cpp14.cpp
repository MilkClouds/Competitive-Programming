#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mod=1e9+7;
int main(){
	int n;
	cin>>n;
	int a=0,b=1,c;
	for (int i = 1; i < n; ++i)
	{
		c=a;
		a=b;
		b=(a+c)%mod;
	}
	if(n==0){
		cout<<0;
		return 0;
	}
	cout<<b;
}