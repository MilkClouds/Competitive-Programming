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


vector<int> v[20];
int N;
string mask;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> mask;
    v[0].pb(0); v[0].pb(1); v[0].pb(0); v[0].pb(1);
    rep(i, 1, N){
        rep(j, 0, 1 << i) v[i].pb(j & 1);
        rep(j, 0, 1 << i) v[i].pb(j & 1 ^ 1);
        rep(j, 0, 1 << i) v[i].pb(j & 1 ^ 1);
        rep(j, 0, 1 << i) v[i].pb(j & 1);
    }
    rep(i, 0, 1 << N){
        rep(j, 1, N + 1) cout << (v[j - 1][i % (1 << j + 1)] ^ (mask[j - 1] - '0'));
        cout << "\n";
    }
}
