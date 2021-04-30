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
const int MAX=1e4+1;

ll N, Q, tree[MAX];

void update(int i,int v){
	for(;i<=N;i+=i&-i) tree[i] += v;
}
ll query(int i){
	ll ret = 0;
	for(;i;i&=i-1) ret += tree[i];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> Q;
	while(Q--){
		int c, a, b;
		cin >> c >> a >> b;
		if(c & 1){
			update(a, b);
		}
		else cout << query(b) - query(a-1) << "\n";
	}
}