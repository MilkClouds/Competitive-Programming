#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const int MAX = 1e5 + 3;

ll N, M, K, mt, deg[MAX];
string s, tmp, S[MAX];
map<string, ll> m;
vector<ll> adj[MAX], ans;

bool op(string pat, string str){
	rep(i, 0, K){
		if(str[i] == pat[i] || pat[i] == '_') continue;
		return 0;
	}
	return 1;
}

ll Topological_Sort(){
	queue<ll> Q;
	ll cnt = 0;
	rep(i, 1, N + 1){
		if(deg[i] == 0) Q.push(i);
	}
	while(!Q.empty()){
		ll u = Q.front(); Q.pop(); cnt++;
		ans.pb(u);
		for(auto v: adj[u]){
			deg[v]--;
			if(deg[v] == 0){
				Q.push(v);
			}
		}
	}
	if(cnt < N) return 0;
	return 1;
}

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	rep(i, 1, N + 1) {
		cin >> s;
		S[i] = s;
		m[s] = i;
	}
	rep(i, 0, M){
		cin >> s >> mt;
		if(!op(S[mt], s)) {cout << "NO\n"; return 0;}
		rep(k, 0, 1 << K){
			ll j = 0, i = k;
			tmp = s;
			while(i){
				if(i%2){
					tmp[j] = '_';
				}
				j++;i/=2;
			}
			if(m[tmp] == 0 || m[tmp] == mt) continue;
			adj[mt].pb(m[tmp]);
			deg[m[tmp]]++;
		}
	}
	if(Topological_Sort() == 0) {cout << "NO\n"; return 0;}
	cout << "YES\n";
	for(auto i:ans)cout << i << " " ;
}
