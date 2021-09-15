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

const int MAX = 1e5 + 1;
int N, M, K, A[11], B[MAX], cnt;
bool vis[MAX];
ld ans;
struct AB{
    ld x, y;
    AB(): AB(0, 0){}
    AB(ld x, ld y): x(x), y(y){}
    AB operator + (AB o){
        return AB(x + o.x, y + o.y);
    }
    AB operator - (AB o){
        return AB(x - o.x, y - o.y);
    }
    AB operator / (ld k){
        return AB(x / k, y / k);
    }
    AB operator +(int i){
        return AB(x, y + i);
    }
} f[MAX], fS[MAX];

AB get(int i){
    if(i >= N) return fS[N];
    return fS[i];
}

AB solution(int n){
    if(n >= N) return {0, 0};
    if(B[n]) {
        fS[n] = fS[n + 1] + AB(1, 0);
        return f[n] = {1, 0};
    }
    if(vis[n]) return f[n];
    vis[n] = 1;
    f[n] = (get(n + 1) - get(n + M + 1)) / M + 1;
    fS[n] = fS[n + 1] + f[n];
    return f[n];
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    rep(i, 0, K) {
        cin >> A[i];
        if(B[A[i] - 1]) cnt++;
        else cnt = 1;
        if(cnt >= M) {cout << -1; return 0;}
        B[A[i]] = i + 1;
    }
    rep2(i, 0, N + 1) solution(i);
    auto p = f[0];
    cout.precision(30);
    cout << p.y / (1 - p.x);
}
