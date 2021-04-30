#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
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

const int MAX = 1e6;
ll N, A[MAX], B[MAX], ans;
priority_queue<ll> pq;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) {
		cin >> A[i]; A[i] -= i;
	}
	rep(i, 0, N) {
		pq.push(A[i]); pq.push(A[i]); pq.pop();
		B[i] = pq.top();
	}
	rep2(i, 1, N) B[i - 1] = min(B[i - 1], B[i]);
	rep(i, 0, N) ans += abs(B[i] - A[i]);
	cout << ans;
}