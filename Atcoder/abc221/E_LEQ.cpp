#include <bits/stdc++.h>
#include <atcoder/modint>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using mi = atcoder::modint998244353;

const int MAX = 3e5 + 1, MOD = 998244353;
int N, A[MAX], id = 1;
mi P[MAX], PI[MAX], tree[MAX], ans;
pi B[MAX];
void upd(int i, mi x){
    for(; i <= N; i += i & -i) tree[i] += x;
}
mi query(int i){
    mi ret = 0;
    for(; i; i &= i - 1) ret += tree[i];
    return ret;
}
long long poww(long long a, long long b) {
	long long ret = 1;
	while (b) {
	if (b & 1) ret *= a;
		a *= a;
		a %= MOD;
		ret %= MOD;
		b >>= 1;
	}
	return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> B[i].x, B[i].y = i;
    sort(B, B + N);
    rep(i, 0, N) {
        if(i && B[i].x != B[i - 1].x) ++id;
        A[B[i].y] = id;
    }
    P[0] = 1;
    rep(i, 1, MAX) P[i] = P[i - 1] * 2;
    PI[MAX - 1] = poww(P[MAX - 1].val(), MOD - 2);
    rep2(i, 1, MAX) PI[i - 1] = PI[i] * 2;
    rep(i, 0, N){
        if(i){
            ans += query(A[i]) * P[i - 1];
        }
        upd(A[i], PI[i]);
    }
    cout << ans.val() << endl;
}
