#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;

ll N,M,t;
vector<ll> pn;
ll solve(ll i,ll num){
	if( i == pn.size() )return M/num;
	return solve(i+1,num)-solve(i+1, num*pn[i]);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	rep(i,0,N){cin>>t; pn.push_back(t);}
	cout<<M-solve(0,1);
}