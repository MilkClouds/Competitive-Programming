#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int MAX=1e5+5;
ll n,p,x[MAX],y[MAX],dots;
mt19937 rd;
int f(pii a,pii b){
	int cnt=0;
	rep(i,0,n){
		cnt += (b.y-a.y)*(x[i]-a.x) == (b.x-a.x)*(y[i]-a.y);
	}
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>p;
	if(n==1){cout<<"possible";return 0;}
	dots=n*p%100 ? n*p/100 + 1 : n*p/100;
	rep(i,0,n)cin>>x[i]>>y[i];
	rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> ran(0, n-1);
	rep(i,0,130){
		int a=ran(rd);
		int b=ran(rd);
		while(a==b)b=ran(rd);
		if(f({x[a],y[a]},{x[b],y[b]})>=dots){cout<<"possible";return 0;}
	}
	cout<<"impossible";
}