# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <atcoder/all>
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
https://atcoder.jp/contests/abc210/tasks/abc210_f
primes less than 2e6: 148933
*/

const int MAXN = 3e4, MAXX = 2e6 + 1, MAXP = 148933;
vector<int> pn, pr[MAXP];
int N, arr[MAXX], A[MAXN * 2];
void eratos() {
	for (int i = 2; i < MAXX; i++) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (int j = i; j < MAXX; j += i) arr[j] = i;
	}
}
set<int> decom(int N){
    set<int> ret;
    while(N > 1){
        ret.insert(lower_bound(all(pn), arr[N]) - pn.begin());
        N /= arr[N];
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    eratos();
    cin >> N;
    atcoder::two_sat ts(30 * N);
    rep(i, 0, N) cin >> A[i * 2] >> A[i * 2 + 1];
    rep(i, 0, N){
        for(auto v: decom(A[i * 2])) pr[v].pb(2 * i);
        for(auto v: decom(A[i * 2 + 1])) pr[v].pb(2 * i + 1);
        ts.add_clause(2 * i, 1, 2 * i + 1, 1);
    }
    int S = 2 * N;
    rep(p, 0, MAXP){
        if(pr[p].empty()) continue;
        rep(i, 0, pr[p].size()){
            int Y = S++, Z = S++;
            ts.add_clause(pr[p][i], 1 ^ 1, Y, 1);
            ts.add_clause(pr[p][i], 1 ^ 1, Z, 1);
            if(i){
                ts.add_clause(Z, 1 ^ 1, Z - 2, 1);
                ts.add_clause(Y - 2, 1 ^ 1, pr[p][i], 0);
            }
            if(i < pr[p].size() - 1){
                ts.add_clause(Y, 1 ^ 1, Y + 2, 1);
                ts.add_clause(Z + 2, 1 ^ 1, pr[p][i], 0);
            }
        }
    }
    cout << (ts.satisfiable() ? "Yes" : "No") << endl;
}
