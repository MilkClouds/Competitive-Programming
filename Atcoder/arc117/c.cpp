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

int comb(int n, int r){
    int ans = 1;
    rep(i, 0, r) ans *= n - i;
    rep(i, 0, r) ans /= i + 1;
    return ans;
}
int combination(int n, int r){
    int ans = 1;
    while(n || r){
        ans *= comb(n % 3, r % 3);
        ans %= 3;
        n /= 3;
        r /= 3;
    }
    return ans;
}

const char c[] = {'B', 'W', 'R'};
map<char, int> m;
int N, ans;
string C;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> C;
    m['B'] = 0; m['W'] = 1; m['R'] = 2;
    rep(i, 0, N){
        ans += combination(N - 1, i) * m[C[i]];
        ans %= 3;
    }
    if(N % 2 == 0) ans *= -1;
    ans %= 3;
    if(ans < 0) ans += 3;
    cout << c[ans];
}
