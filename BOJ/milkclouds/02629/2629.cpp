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

const int K = 15000;
int N, A[31], B[31], M, vis[60001];
queue<int> Q;
void add(int i){
    if(!vis[i + K]){
        vis[i + K] = 1;
        Q.push(i);
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    Q.push(0); vis[0 + K] = 1;
    rep(i, 0, N) {
        cin >> A[i];
        int tmp = Q.size();
        rep(_, 0, tmp){
            int u = Q.front(); Q.pop(); Q.push(u);
            add(u + A[i]); add(u - A[i]);
        }
    }
    cin >> M;
    rep(i, 0, M) {
        cin >> B[i];
        cout << (vis[B[i] + K] ? "Y" : "N") << " ";
    }
}
