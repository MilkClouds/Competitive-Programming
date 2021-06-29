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

const ll MOD = 123'456'789, MAX = 4e4 + 1;
ll N, dp[MAX];

vector<ll> pn;
bool arr[MAX];
void eratos() {
	pn.push_back(2);
	for (ll i = 3; i < MAX; i += 2) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i * i; j < MAX; j += i) arr[j] = 1;
	}
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    dp[0] = 1;
    eratos();
    rep(i, 0, pn.size()){
        if(pn[i] > N) break;
        rep(j, 0, N - pn[i] + 1){
            dp[j + pn[i]] = (dp[j] + dp[j + pn[i]]) % MOD;
        }
    }
    cout << dp[N] << endl;
}
