#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
ll N,M,L,K,x,y,ans;
pll star[101];
ll calculate(int x,int y){
	ll cnt=0;
	rep(i,0,K){
		if(x<=star[i].x&&star[i].x<=x+L
			&& y<=star[i].y&&star[i].y<=y+L)cnt++;
	}
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M>>L>>K;
	rep(i,0,K){
		cin>>x>>y;
		star[i]={x,y};
	}
	rep(i,0,K)rep(j,0,K)ans=max(ans,calculate(star[i].x,star[j].y));
	cout<<K-ans;
}
