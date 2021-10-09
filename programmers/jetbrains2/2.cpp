#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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


vector<int> solution(int n, long long left, long long right) {
    vector<int> ans;
    if(left / n == right / n){
        rep(l, left % n, right % n + 1) ans.eb(max(l, left / n) + 1);
        return ans;
    }
    rep(l, left % n, n) ans.eb(max(left / n, l) + 1);
    rep(l, left / n + 1, right / n){
        rep(k, 0, n) ans.eb(max(l, k) + 1);
    }
    rep(l, 0, right % n + 1) ans.eb(max(right / n, l) + 1);
    return ans;
}