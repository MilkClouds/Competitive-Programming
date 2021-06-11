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

const int MAX = 5e5 + 2;
int N, A[MAX], l[MAX], r[MAX], c[MAX], dp[MAX], d[MAX];
void setmax(int& a, int b){
    if(b > a) a = b;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 1, N + 1) cin >> A[i];
    fill(l, l + N + 1, N);
    rep(i, 1, N + 1){
        int j = A[i];
        l[j] = min(l[j], i);
        r[j] = max(r[j], i);
        c[j]++;
    }
    rep2(i, 1, N + 1){
        int j = A[i];
        d[j]++;
        setmax(dp[i], dp[i + 1]);
        if(i != l[j]) setmax(dp[i], d[j]);
        else setmax(dp[l[j]], dp[r[j] + 1] + c[j]);
    }
    cout << N - dp[1];
}
