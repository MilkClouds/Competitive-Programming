# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

const int MAX = 1e5;
ll N, M, p, flag;
pl A[MAX];
ll gcd(ll a, ll b){
    if(a % b == 0) return b;
    return gcd(b, a % b);
}
ll solve(ll N){
    if(N == 1) return 0;
    while(p < M && A[p].x % N == 0) p++;
    if(p == M) {
        flag = 1;
        return -1;
    }
    ll k = A[p].x %= N;
    ll g = gcd(N, k);
    return (N - g) * A[p].y + solve(g);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M;
    rep(i, 0, M) {
        cin >> A[i].x >> A[i].y;
    }
    sort(A, A + M, [](pl& a, pl& b){
        return a.y < b.y;
    });
    ll tmp = solve(N);
    if(flag) cout << "-1\n";
    else cout << tmp << endl;
}
