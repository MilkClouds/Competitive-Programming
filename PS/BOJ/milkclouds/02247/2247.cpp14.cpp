#include <iostream>
using namespace std;
const int MOD=1e6;
typedef long long ll;
ll solve(ll n){
	ll ret=1-n*(n+3)/2;
	ret=(MOD+ret)%MOD;
	for(ll d=1;d<=n;d++){
		ll div=n/d, mod=n%d;
		ll step=mod/div;
		ret+=div*(1+step)*(d*2+step)/2;
		ret%=MOD;
		d+=step;
	}
	return ret%MOD;
}

int main()
{
	ll N;
	cin>>N;
	cout<<solve(N);
	return 0;
}