# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const ll MAX=402, INF=1e15;

ll V, E, u, v, d, dist[MAX][MAX], ans=INF;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> V >> E;
	fill(dist[0],dist[V+1],INF);
	rep(i, 0, E){
		cin >> u >> v >> d;
		dist[u][v]=d;
	}
	rep(m,1,V+1)rep(s,1,V+1)rep(e,1,V+1)
		if(dist[s][e] > dist[s][m]+dist[m][e]) dist[s][e]=dist[s][m]+dist[m][e];
	rep(i,1,V+1) ans = min(ans, dist[i][i]);
	cout << (ans < INF ? ans : -1);	
}