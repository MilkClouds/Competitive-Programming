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

const ll MAX = 5e5 + 1;
vector<ll> pn;
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
    return gcd(y, x % y);
}
int N, ans[MAX], cnt;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    eratos();
    cin >> N;
    ans[1] = ++cnt;
    rep(j, 2, N + 1){
        int i = j;
        map<int, int> M;
        while(i > 1){
            M[arr[i]]++;
            i /= arr[i];
        }
        if(ans[M.begin()->x]) ans[j] = ans[M.begin()->x];
        else ans[j] = ++cnt;
    }
    cout << cnt << "\n";
    rep(j, 1, N + 1) cout << ans[j] << " ";
}