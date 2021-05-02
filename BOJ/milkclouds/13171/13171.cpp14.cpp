#include <bits/stdc++.h>

using namespace std;
const int MOD=1e9+7;
int main(){
	long long a,x;
	cin>>a>>x;
	long long ret=1;
	a%=MOD;x%=MOD-1;
	while(x){
		if(x&1)ret*=a;
		x/=2;
		a*=a;
		a%=MOD;ret%=MOD;
	}
	cout<<ret;
}