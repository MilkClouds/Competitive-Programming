#include <bits/stdc++.h>
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
using pi = pair<int, int>;
using ld = long double;

const int MAX = 2e5 + 3;
int N, M, A[MAX];
ll cur;
vector<ll> B;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	B.assign(M, 0);
	rep(i, 0, N)cin >> A[i];
	sort(A, A + N);
	rep(k, 0, N) {
		B[k % M] += A[k];
		cur += B[k % M];
		cout << cur << " ";
	}
}