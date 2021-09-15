# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 1e6 + 1;
int N, ans;
ll A[MAX], L[MAX], R[MAX];
inline int cmp(ll a, ll b){
    return a < b ? -1 : (a > b ? 1 : 0);
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    L[0] = A[0];
    rep(i, 1, N) L[i] = max(L[i - 1], A[i]);
    rep2(i, 0, N) R[i] = max(R[i + 1], A[i]);
    rep(i, 0, N - 1){
        ans += cmp(L[i], R[i + 1]);
    }
    cout << (ans == 0 ? 'X' : (ans < 0 ? 'B' : 'R'));
}
