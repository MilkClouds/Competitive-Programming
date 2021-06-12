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

const int MAX = 2005;
int k, n, a[MAX], b[MAX], s[MAX];
map<int, int> ans, M;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> k >> n;
    rep(i, 0, k) cin >> a[i];
    rep(i, 0, k) s[i + 1] = s[i] + a[i];
    rep(i, 1, k + 1) M[s[i]] = 1;
    rep(i, 0, n) cin >> b[i];
    rep(i, 1, k + 1){
        int bias = b[0] - s[i];
        int flag = 0;
        rep(j, 0, n){
            if(M.find(b[j] - bias) == M.end()) {
                flag = 1;
                break;
            }
        }
        if(!flag) ans[bias] = 1;
    }
    cout << ans.size();
}
