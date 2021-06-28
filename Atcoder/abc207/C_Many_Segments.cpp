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

const int MAX = 2000;
int N, t, l, r;
ll ans;
pi Q[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N){
        cin >> t >> l >> r;
        l <<= 1; r <<= 1;
        if(t == 1) Q[i] = {l, r + 1};
        else if(t == 2) Q[i] = {l, r};
        else if(t == 3) Q[i] = {l + 1, r + 1};
        else Q[i] = {l + 1, r};
    }
    rep(i, 0, N) rep(j, i + 1, N){
        if(Q[i].y <= Q[j].x || Q[j].y <= Q[i].x) continue;
        ans++;
    }
    cout << ans;
}
