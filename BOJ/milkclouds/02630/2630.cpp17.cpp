#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tll = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;

int N, A[128][128];

struct ABC {
	int i, j;
	ABC operator + (ABC o) {
		return ABC(i + o.i, j + o.j);
	}
	ABC() :ABC(0, 0) {}
	ABC(int i, int j) :i(i), j(j) {}
};

ostream& operator << (ostream& outputStream, const ABC A) {
	cout << A.i << "\n" << A.j;
	return outputStream;
}

ABC solve(int a, int b, int c, int d) {
	int chk[2] = { 0, }, sz = c - a >> 1;
	rep(i, a, c)rep(j, b, d) chk[A[i][j]]++;
	if (chk[0] * chk[1] == 0) return { chk[0] > 0, chk[1] > 0 };
	else return solve(a, b, a + sz, b + sz) + solve(a, b + sz, a + sz, b + 2 * sz) + solve(a + sz, b, a + sz * 2, b + sz) + solve(a + sz, b + sz, a + 2 * sz, b + 2 * sz);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];
	cout << solve(0, 0, N, N);
}