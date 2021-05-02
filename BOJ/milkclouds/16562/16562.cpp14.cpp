#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int MAX=1e4+5;
int N,M,k,u,v,par[MAX],money[MAX],ans;
int find(int u){return u^par[u]?par[u]=find(par[u]):u;}
void merge(int u,int v){
	u=find(u);v=find(v);
	if(u==v)return;
	if(rand()&1)swap(u,v);
	par[u]=v; money[v]=min(money[v],money[u]); money[u]=0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M>>k;
	rep(i,0,N)cin>>money[i];
	rep(i,0,N)par[i]=i;
	rep(i,0,M){
		cin>>u>>v;
		u--;v--;
		merge(u,v);
	}
	rep(i,0,N)ans+=money[i];
	if(ans>k){cout<<"Oh no";return 0;}
	cout<<ans;
}
	