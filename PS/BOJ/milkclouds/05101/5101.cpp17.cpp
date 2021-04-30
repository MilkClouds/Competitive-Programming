#include <bits/stdc++.h>
#pragma warning(suppress : 4996)
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;

int a, b, c;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	while (~scanf("%d %d %d", &a, &b, &c) && (a || b || c)) {
		if ((c - a) % b || (c-a)/b <0) cout << "X\n";
		else cout << (c - a) / b + 1 << "\n";
	}
}