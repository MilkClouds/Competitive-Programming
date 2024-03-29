#include <bits/stdc++.h>
#include <atcoder/convolution>
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

const int MAX = 1e6 + 1;
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
    eratos();
    vector<int> a(MAX);
    for(auto p: pn) a[p] = 1;
    auto&& A = atcoder::convolution(a, a);
    int T, u;
    cin >> T;
    while(T--){
        cin >> u;
        cout << (A[u] + 1) / 2 << "\n";
    }
}