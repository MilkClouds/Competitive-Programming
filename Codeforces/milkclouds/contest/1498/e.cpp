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
using pp = pair<int, pi>;

int N, K[501];
vector<pp> v;
string S;
bool query(int i, int j){
    cout << "? " << i << " " << j << endl;
    cin >> S;
    return S == "Yes";
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> K[i];
    rep(i, 0, N) rep(j, i + 1, N){
        v.pb({-abs(K[i] - K[j]), {i + 1, j + 1}});
    }
    sort(all(v));
    for(auto [ans, p] : v){
        int i = p.x, j = p.y;
        if(query(i, j)) {cout << "! " << i << " " << j << endl; return 0;}
    }
    cout << "? 0 0" << endl;
}
