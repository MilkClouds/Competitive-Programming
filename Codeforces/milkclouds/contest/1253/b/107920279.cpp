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

const int MAX = 1e5 + 3;
int N, A[MAX], last = -1;
vector<int> ans;
set<int> M, vis;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N)cin >> A[i];
	rep(i, 0, N) {
		if (A[i] > 0) {
			if (M.find(A[i]) != M.end() || vis.find(A[i]) != vis.end()) {
				cout << -1;
				return 0;
			}
			M.insert(A[i]);
			vis.insert(A[i]);
		}
		else {
			A[i] *= -1;
			if (M.find(A[i]) == M.end() || vis.find(A[i]) == vis.end()) {
				cout << -1;
				return 0;
			}
			M.erase(A[i]);
		}
		if (M.empty()) {
			vis.clear();
			ans.push_back(i - last);
			last = i;
		}
	}
	if (!M.empty()) {
		cout << -1;
		return 0;
	}
	cout << ans.size() << "\n";
	for (auto i : ans) cout << i << " ";
}