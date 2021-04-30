#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

using ll = long long;
const ll MAX = 1e5 + 2;

int N, M, x;
vector<int> tree[4*MAX];

void update(int node, int l, int r, int x, int v){
	if(x < l || r < x) return;
	tree[node].pb(v);
	if(l == r) return;
	int m = l + r >> 1;
	update(node * 2, l, m, x, v);
	update(node * 2 + 1, m + 1, r, x, v); 
}
int query(int node, int l, int r, int s, int e, int k){
	if(e < l || r < s) return 0;
	if(s <= l && r <= e) {
		return upper_bound(all(tree[node]), k) - tree[node].begin();
	}
	int m = l + r >> 1;
	return query(node * 2, l, m, s, e, k) + query(node * 2 + 1, m + 1, r, s, e, k);
}
int query2(int s, int e, int k){
	int l = -1e9, r = 1e9;
	while(l < r) {
		int m = l + r >> 1;
		if(query(1, 1, N, s, e, m) < k) l = m + 1;
		else r = m; 
	}
	return r;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	rep(i, 0, N) {cin >> x; update(1, 1, N, i + 1, x);}
	rep(i, 0, N * 4) sort(all(tree[i]));
	rep(m, 0, M){
		int i, j, k;
		cin >> i >> j >> k;
		cout << query2(i, j, k) << "\n";
	}
}