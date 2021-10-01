#include <bits/stdc++.h>
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

const int MAX = 1e5 + 1;
ll N, A[MAX], S[MAX], X;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N + 1) cin >> A[i], S[i] = S[i - 1] + A[i];
    cin >> X;
    cout << ((X / S[N]) * N + upper_bound(S, S + N + 1, X % S[N]) - S) << endl;
}
