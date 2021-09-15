# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 2e5 + 5, MOD = 1e9 + 7;
int N, Q, x, i, arr[MAX];
ll ret = 1;
vector<ll> pn;

void eratos() {
	rep(i, 2, MAX){
		if (arr[i]) continue;
		pn.push_back(i);
		arr[i] = i;
		if(i > 10000) continue;
		for (ll j = i * i; j < MAX; j += i) if(arr[j] == 0) arr[j] = i;
	}
}
map<int, int> M[MAX];
multiset<int> S[MAX];

inline int minm(multiset<int>& S){
	if(S.size() < N) return 0;
	return *S.begin();
}
void upd(int i, int x){
	while(x > 1){
		int a = arr[x], b = 0;
		while(arr[x] == a) {b++; x /= a;}
		int tmp = minm(S[a]);
		if(M[a][i]) S[a].erase(S[a].find(M[a][i]));
		M[a][i] += b;
		S[a].insert(M[a][i]);
		if(S[a].size() == N) rep(_, 0, (*S[a].begin()) - tmp) ret = (ret * a) % MOD;
	}
}


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    eratos();
    cin >> N >> Q;
	rep(i, 0, N){
		cin >> x;
		upd(i, x);
	}
	while(Q--){
		cin >> i >> x;
		upd(--i, x);
		cout << ret << "\n";
	}
}
