#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
using namespace std;
using ll=long long;
const ll MAX=1e3+5;

ll T,n,m,a[MAX],b[MAX],c[MAX],d[MAX],ans;
unordered_map<int,int> save;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
		c[i+1]=c[i]+a[i];
	}
	cin>>m;
	rep(i,0,m){
		cin>>b[i];
		d[i+1]=d[i]+b[i];
	}
	rep(i,0,n)rep(j,i,n)save[c[j+1]-c[i]]++;
	rep(i,0,m)rep(j,i,m)ans+=save[T-d[j+1]+d[i]];
	cout<<ans;
}