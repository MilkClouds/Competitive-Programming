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
const ll INF = 1e9, MOD = 1e9 + 7, MAX = 1e6 + 10, MAX_N = 1e5 + 10;

ll N, Q, A[MAX_N], T, S, E, B[MAX];
bool arr[MAX];
vector<ll> pn;
void erato(){
	for(ll i = 2; i < MAX; i++){
		if(arr[i])continue;
		pn.pb(i);
		for(ll j = i; j < MAX; j += i){
			arr[j] = 1;
			ll t = j, cnt = 0;
			while(t%i==0){t/=i; cnt++;}
			B[j] *= cnt + 1;
		}
	}
}
struct Node{ll v; bool c;} tree[MAX_N];
void init(int node,int l,int r){
	if(l==r){
		tree[node].v = A[l - 1];
		tree[node].c = tree[node].v <= 2;
		return;
	}
	int m = l + r >> 1;
	init(node * 2, l, m); init(node * 2 + 1, m + 1, r);
	tree[node].v = tree[node * 2].v + tree[node * 2 + 1].v;
	tree[node].c = tree[node * 2].c & tree[node * 2 + 1].c;
}
void update(int node,int l,int r,int s,int e){
	if(tree[node].c || r<s || e<l)return;
	if(l==r){
		tree[node].v = B[tree[node].v];
		tree[node].c = tree[node].v <= 2;
		return;
	}
	int m = l + r >> 1;
	update(node * 2, l, m, s, e); update(node * 2 + 1, m + 1, r, s, e);
	tree[node].v = tree[node * 2].v + tree[node * 2 + 1].v;
	tree[node].c = tree[node * 2].c & tree[node * 2 + 1].c;
}
ll query(int node,int l,int r,int s,int e){
	if(r<s || e<l)return 0;
	if(s<=l && r<=e)return tree[node].v;
	int m = l + r >> 1;
	return query(node * 2, l, m, s, e) + query(node * 2 + 1, m + 1, r, s, e);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill(B, B + MAX, 1);
	erato();
	cin >> N >> Q;
	rep(i, 0, N) cin >> A[i];
	init(1,1,N);
	rep(i, 0, Q) {
		cin >> T >> S >> E;
		if(T & 1){
			update(1,1,N,S,E);
		}
		else cout << query(1,1,N,S,E) << "\n";
	}
}
	