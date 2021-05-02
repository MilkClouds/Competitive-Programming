#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N,P,Q,X,Y;
unordered_map<ll,ll> dp;
ll GET(ll N){
	if(N<=0)return 1;
	ll& ret=dp[N];
	if(ret)return ret;
	return ret=GET(N/P-X)+GET(N/Q-Y);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>P>>Q>>X>>Y;
	cout<<GET(N);
}