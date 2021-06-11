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

const int MAX = 3005;
int N;
vector<int> cand;
string S;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, 1 << 14){
        int tmp = i, cnt = 0;
        while(tmp) {
            cnt += tmp & 1; tmp >>= 1;
        }
        if(cnt != 7) continue;
        cand.pb(i);
    }
    rep(i, 1, N){
        cin >> S;
        rep(j, 0, i) if(S[j] == '1'){
            rep(k, 0, 14) if((cand[j] & (1 << k)) && !(cand[i] & (1 << k))) { cout << (char) ('a' + k); break; }
        } else {
            rep(k, 0, 14) if((cand[i] & (1 << k)) && !(cand[j] & (1 << k))) { cout << (char) ('a' + k); break; }
        }
        cout << "\n";
    }
}
