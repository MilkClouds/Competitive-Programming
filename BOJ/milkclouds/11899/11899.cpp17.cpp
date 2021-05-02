#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

string S;
int s, ans;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> S;
	rep(i, 0, S.size()) {
		if (S[i] == ')') s--;
		else s++;
		while (s < 0) { ans++; s++; }
	}
	cout << ans + s;
}