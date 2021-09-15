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

const int MAX = 1e5;
int N, W, w[MAX], TC;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> N >> W;
        map<int, int> m;
        rep(i, 0, N) {
            cin >> w[i];
            m[w[i]]++;
        }
        int cnt = 0, cnt2 = 0;
        while(cnt2 < N){
            int tmp = W;
            for(auto p = m.rbegin(); p != m.rend(); p++){
                int t = min(p -> y, tmp / (p -> x));
                (p -> y) -= t;
                tmp -= (p -> x) * t;
                cnt2 += t;
            }
            cnt++;
        }
        cout << cnt << "\n";
    }
}
