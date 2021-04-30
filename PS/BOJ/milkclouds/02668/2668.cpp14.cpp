#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

int N,suc[105],cnt,visit[105],chk[105],dfsn,cycle[105];
int DFS(int u){
	if(visit[u]){
		return u;
	}
	if(chk[u])return 0;
	visit[u]=1;
	chk[u]=++dfsn;
	int next=DFS(suc[u]);
	visit[u]=0;
	if(next>0){
		cycle[u]=1;
		if(next^u)return next;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	rep(i,0,N)cin>>suc[i+1];
	rep(i,0,N)DFS(i+1);
	rep(i,0,N)if(cycle[i+1])cnt++;
	cout<<cnt<<"\n";
	rep(i,0,N)if(cycle[i+1])cout<<i+1<<"\n";
}
	