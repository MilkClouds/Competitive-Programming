# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

/*
unsolved
https://atcoder.jp/contests/abc210/tasks/abc210_f
primes less than 2e6: 148933
prime less than 1414: 223
*/
const ll MAX = 3e6;
vector<ll> pn;
ll arr[MAX];
void eratos() {
	for (ll i = 2; i < MAX; i++) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i; j < MAX; j += i) arr[j] = i;
	}
}
set<ll> decom(ll N){
    set<ll> ret;
    while(N > 1){
        ret.insert(lower_bound(all(pn), arr[N]) - pn.begin());
        N /= arr[N];
    }
    return ret;
}
int N, A[60001];
int chk[2000001];
vector<int> pr[148933];
bool dfs(int u){
    bool ret = 0;
    int cnt = 0;
    for(auto v: decom(A[u])){
        for(auto k: pr[v]){
            chk[k]++; cnt++;
            if(chk[k ^ 1]) {
                for(auto v: decom(A[u])){
        for(auto k: pr[v]){
            chk[k]--;
            if((--cnt) == 0) {
                return 0;
            }
        }
    }
                
            }
        }
    }
    int nxt = (u / 2 + 1);
    ret = dfs(2 * nxt) || dfs(2 * nxt + 1);
    for(auto v: decom(A[u])){
        for(auto k: pr[v]){
            chk[k]--;
        }
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    eratos();
    cin >> N;
    rep(i, 0, N) cin >> A[i * 2] >> A[i * 2 + 1];
    rep(i, 0, N){
        for(auto v: decom(A[i * 2])) pr[v].pb(2 * i);
        for(auto v: decom(A[i * 2 + 1])) pr[v].pb(2 * i + 1);
    }
    cout << (dfs(0) || dfs(1) ? "Yes" : "No") << endl;
}
