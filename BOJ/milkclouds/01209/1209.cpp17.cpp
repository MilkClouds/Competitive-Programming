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
ll N, A[MAX], B[MAX], C[MAX], ans, ans2;
priority_queue<ll> pq, pq2;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) {
		cin >> A[i];
	}
	rep(i, 0, N) {
		pq.push(A[i]); pq.push(A[i]); pq.pop();
		pq2.push(-A[i]); pq2.push(-A[i]); pq2.pop();
		B[i] = pq.top();
		C[i] = pq2.top();
	}
	rep2(i, 1, N) {
		B[i - 1] = min(B[i - 1], B[i]);
		C[i - 1] = min(C[i - 1], C[i]);
	}
	rep(i, 0, N) {
		ans += abs(B[i] - A[i]);
		ans2 += abs(C[i] + A[i]);
	}
	cout << min(ans, ans2);
}