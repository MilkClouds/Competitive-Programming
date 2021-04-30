#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N,P,Q;
unordered_map<ll,ll> dp;
ll GET(ll N){
	ll& ret=dp[N];
	if(ret)return ret;
	return ret=GET(N/P)+GET(N/Q);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>P>>Q;dp[0]=1;
	cout<<GET(N);
}