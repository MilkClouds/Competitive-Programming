#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(int a = c - 1; a >=b; a--)
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

int TC, flag, flag2, s, e;
string S;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> TC;
	while (TC--) {
		flag = 0;
		cin >> S;
		rep(i, 0, S.size() / 2) {
			if (S[i] == S[S.size() - i - 1]) continue;
			flag = 1;
			break;
		}
		if (!flag) {
			cout << 0 << "\n"; continue;
		}
		flag = flag2 = 0;
		s = 0, e = S.size() - 1;
		while (s < e) {
			if (S[s] == S[e]) {
				s++; e--; continue;
			}
			if (flag) { flag2 = 1; break; }
			s++;
			flag = 1;
		}
		if (!flag2) {
			cout << "1\n"; continue;
		}

		flag = flag2 = 0;
		s = 0, e = S.size() - 1;
		while (s < e) {
			if (S[s] == S[e]) {
				s++; e--; continue;
			}
			if (flag) { flag2 = 1; break; }
			e--;
			flag = 1;
		}
		if (!flag2) {
			cout << "1\n"; continue;
		}
		cout << "2\n";
	}
}