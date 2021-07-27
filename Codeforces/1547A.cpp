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


istream& operator >>(istream& is, pi& a){
	return is >> a.x >> a.y;
}

ll dist(pi a, pi b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}
void solve(){
	pi a, b, f;
	cin >> a >> b >> f;
	if(a.y > b.y) swap(a, b);
	if(a.x == b.x && f.x == a.x){
		if(a.y < f.y && f.y < b.y) cout << dist(a, b) + 2 << "\n";
		else cout << dist(a, b) << "\n";
		return;
	}
	if(a.x > b.x) swap(a, b);
	if(a.y == b.y && a.y == f.y){
		if(a.x < f.x && f.x < b.x) cout << dist(a, b) + 2 << "\n";
		else cout << dist(a, b) << "\n";
		return;
	}
	cout << dist(a, b) << "\n";
}


int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
	int TC;
    cin >> TC;
	while(TC--) solve();
}
