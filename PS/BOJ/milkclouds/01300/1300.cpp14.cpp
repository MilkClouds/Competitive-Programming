#include <iostream>
using namespace std;
typedef long long ll;
ll n,k,l,r,m;
ll solve(int m){
	ll ret=0;
	for(ll i=1;i<=n;i++){
		ret+=min(n, m/i);
	}
	return ret;
}
int main()
{
	cin>>n>>k;r=k;
	while(l<=r){
		m=l+r>>1;
		if(solve(m)>=k)r=m-1;
		else l=m+1;
	}
	cout<<l;
	return 0;
}