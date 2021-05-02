#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MAX = 5e5 + 3, INF = 1e9;

int N, A[MAX], tree[MAX * 4], ans = -1, lbound;

int construct(int l, int r, int node) {
    if (l + 1 == r) return tree[node] = A[l + 4] + A[l + 3] + A[l + 2] + A[l + 1] - A[l];
    int m = l + r >> 1;
    return tree[node] = max(construct(l, m, node * 2), construct(m, r, node * 2 + 1));
}
int query(int l, int r, int node, int x) {
    if (r <= lbound)return INF;
    if (l + 1 == r) if (l >= lbound) return tree[node] > x ? l : INF;
    else return INF;
    int m = l + r >> 1;
    int ans = INF;
    if (tree[node * 2] > x) ans = min(ans, query(l, m, node * 2, x));
    if (ans == INF && tree[node * 2 + 1] > x) ans = min(ans, query(m, r, node * 2 + 1, x));
    return ans;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    sort(A, A + N, greater<int>());
    construct(0, N - 4, 1);
    rep(i, 1, N - 5) {
        lbound = i + 1;
        ll t = query(0, N - 4, 1, A[i]);
        if (t == INF) continue;
        ll j = upper_bound(A, A + N, A[i] + A[t], greater<int>()) - A;
        if (j >= i) continue;
        ans = max(ans, A[j] + A[i] + A[t] + A[t + 1] + A[t + 2] + A[t + 3] + A[t + 4]);
    }
    cout << ans;
}