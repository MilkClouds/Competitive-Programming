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
const ll INF = 1e9;
const ll MAX = 2e5 + 1;

int N, tree[MAX], tree2[MAX], A[MAX];
ll ans;

int query(int* tree, int u){
	int ret = 0;
	for(;u;u&=u-1) ret += tree[u];
	return ret;
}
void update(int* tree, int u,int v){for(;u<=N;u+=u&-u)tree[u]+=v;}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N){
		cin >> A[i];
		update(tree2, A[i], 1);
	}
	rep(i, 0, N){
		if(i)update(tree, A[i-1], 1);
		update(tree2, A[i], -1);
		ans += 1LL * (query(tree, N) - query(tree, A[i])) * (query(tree2,A[i]-1));
	}
	cout << ans;
}
	