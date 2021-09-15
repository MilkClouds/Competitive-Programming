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

int TC, N, C[11], D[11], cnt;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> N;
        set<int> S;
        cnt = 0;
        rep(i, 0, N) {
            cin >> C[i];
            C[i] += C[i] & 1;
            S.insert(C[i]);
        }
        while(S.size() > 1){
            fill(D, D + N, 0);
            rep(i, 0, N) {
                D[(1 + i) % N] += C[i] / 2;
                D[i] += C[i] / 2;
            }
            rep(i, 0, N) D[i] += D[i] & 1;
            S.clear();
            rep(i, 0, N) {
                C[i] = D[i];
                S.insert(C[i]);
            }
            cnt++;
        }
        cout << cnt << "\n";
    }
}
