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

const int MAX = 1e4;
int N, T, x, y, E[MAX], C[MAX];
pi P[MAX];
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> T;
    rep(i, 0, N) {
        cin >> P[i].x >> P[i].y;
        E[i] = P[i].y;
    }
    sort(P, P + N);
    sort(E, E + N);
    rep(i, 0, N) C[i] = P[i].y - T;
    rep(i, 0, N){
        int l = E[i] - T, k = N - 1;
        rep2(j, 0, N){
            if(P[j].y > E[i]) continue;
            while(k >= 0 && P[k].x > l){
                l = min(l, C[k]);
                k--;
            }
            if(l < P[j].x) {
                cout << "no";
                return 0;
            }
            if(P[j].x + T > l) C[j] = min(C[j], l - T);
            l -= T;
        }
    }
    cout << "yes";
}
