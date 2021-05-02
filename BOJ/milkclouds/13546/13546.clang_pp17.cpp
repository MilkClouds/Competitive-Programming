# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int sz = 100;
const int MAXN = 100005;

int N, K, M, G[MAXN];
int A[MAXN], D[1005][1005], T[MAXN];
vector <int> V[MAXN];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		G[i] = i / sz;
		V[A[i]].push_back(i);
	}
	for (int i = 0; i < N; i += sz) {
		for (int j = 1; j <= K; j++) T[j] = -1;
		int Dx = 0;
		for (int j = i; j < N; j++) {
			if (T[A[j]] == -1) T[A[j]] = j;
			else Dx = max(Dx, j - T[A[j]]);
			D[G[i]][G[j]] = max(D[G[i]][G[j]], Dx);
		}
	}
	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		int s, e; scanf("%d%d", &s, &e); s--; e--;
		int ans = D[G[s] + 1][G[e] - 1];
		for (int i = s; i <= s + sz; i++) {
			if (G[s] != G[i]) break;
			int j = upper_bound(V[A[i]].begin(), V[A[i]].end(), e) - V[A[i]].begin() - 1;
			if (~j) ans = max(ans, V[A[i]][j] - i);
		}
		for (int i = e; i >= e - sz; i--) {
			if (G[e] != G[i]) break;
			int j = lower_bound(V[A[i]].begin(), V[A[i]].end(), s) - V[A[i]].begin();
			if (j != V[A[i]].size()) ans = max(ans, i - V[A[i]][j]);
		}
		printf("%d\n", ans);
	}
}