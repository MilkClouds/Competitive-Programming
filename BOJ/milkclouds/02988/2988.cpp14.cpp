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
using pi=pair<int,int>;
const ll INF = 1e9;
const int MAX = 1e5 + 1;

// 6:45 ~ 7:48
int N, a[3][MAX], vis[MAX], cnt;
vector<int> adj[MAX];
queue<int> jobs;
unordered_map<int,int> freq[3];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, 3)rep(j, 0, N){
		cin >> a[i][j]; a[i][j]--;
		adj[a[i][j]].pb(j);
		freq[i][a[i][j]]++;
	}
	rep(i, 0, N){
		if(freq[1][i]==0 || freq[2][i]==0) jobs.push(i);
	}
	while(!jobs.empty()){
		int u = jobs.front(); jobs.pop();
		for(auto v: adj[u]){
			if(vis[v])continue;
			vis[v] = 1; cnt++;
			rep(i, 0, 3) if(--freq[i][a[i][v]] == 0)jobs.push(a[i][v]);
		}
	}
	cout << cnt;
}