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

const ll MAX = 2e5;
vector<ll> pn;
set<ll> chk;
ll arr[MAX];

void eratos() {
	for (ll i = 2; i < MAX; i++) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i; j < MAX; j += i) arr[j] = i;
	}
}

ll gcd(ll x, ll y){
    if(x % y == 0) return y;
    return gcd(x, y % x);
}
int N, M, A[MAX], cnt;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    eratos();
    cin >> N >> M;
    rep(i, 0, N) {
        cin >> A[i];
        while(A[i] > 1){
            chk.insert(arr[A[i]]);
            A[i] /= arr[A[i]];
        }
    }
    fill(arr, arr + M + 1, 0);
    for(auto i: chk){
        for(ll j = i; j <= M; j += i) arr[j] = 1;
    }
    rep(i, 1, M + 1) cnt += arr[i] == 0;
    cout << cnt << "\n";
    rep(i, 1, M + 1) if(arr[i] == 0) cout << i << "\n";
}
