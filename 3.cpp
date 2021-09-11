#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
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
//3+~-1
//4+4-1
//4+5--1
//5+0-2
//5+1-2
int N, in, deg[6], out, ina[6];
pi A[11];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) {
        cin >> A[i].x >> A[i].y;
        if(A[i].x > A[i].y) swap(A[i].x, A[i].y);
        if(A[i].x + 1 != A[i].y && A[i].y - 4 != A[i].x) in++, ina[A[i].x]++, ina[A[i].y]++;
        else out++;
        deg[A[i].x]++;
        deg[A[i].y]++;
    }
    if(in <= 1) cout << 0;
    else if(in == 2){
        rep(i, 1, 6) if(ina[i] == 2){cout << 0; return 0;}
        cout << 1;
    }
    else if(in == 3) cout << 1;
    else if(in == 4){
        if(out == 5) cout << 1;
        else cout << 1;
    } else {
        if(out == 5) cout << -1;
        else cout << 2;
    }
}
