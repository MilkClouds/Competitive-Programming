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

const int MAX = 2e5;
int N;
ll H, A[MAX], B[MAX], ans;
pl LR[MAX];
priority_queue<ll> pq_M;
priority_queue<ll, vector<ll>, greater<ll> > pq_m;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> H;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) {
		if (pq_M.size() * pq_m.size() == 0) {
			pq_M.push(A[i] + i * H);
			pq_m.push(A[i] - i * H);
		}
		else if (A[i] <= pq_M.top() - i * H) {
			pq_m.push(pq_M.top() - i * H * 2);
			pq_M.pop();
			pq_M.push(A[i] + i * H);
			pq_M.push(A[i] + i * H);
		}
		else if (A[i] >= pq_m.top() + i * H) {
			pq_M.push(pq_m.top() + i * H * 2);
			pq_m.pop();
			pq_m.push(A[i] - i * H);
			pq_m.push(A[i] - i * H);
		}
		else {
			pq_M.push(A[i] + i * H);
			pq_m.push(A[i] - i * H);
		}
		LR[i] = { pq_M.top() - i * H, pq_m.top() + i * H };
	}
	B[N - 1] = LR[N - 1].x;
	rep2(i, 0, N - 1) {
		if (B[i + 1] + H < LR[i].x) B[i] = B[i + 1] + H;
		else if (LR[i].y < B[i + 1] - H) B[i] = B[i + 1] - H;
		else if (LR[i].x < B[i + 1] - H) B[i] = LR[i].y;
		else B[i] = LR[i].x;
	}
	rep(i, 0, N) ans += abs(A[i] - B[i]);
	cout << ans;
}