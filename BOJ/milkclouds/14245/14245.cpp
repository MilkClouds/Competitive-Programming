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


const int MAX = 5e5;
int N, M, t, a, b, c, A[MAX], tree[MAX + 1];
int query(int i){
    int ret = 0; i++;
    for(; i; i ^= i & -i) ret ^= tree[i];
    return ret;
}
void update(int i, int x){ i++;
    for(; i <= N; i += i & -i) tree[i] ^= x;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    cin >> M;
    while(M--){
        cin >> t;
        if(t == 1){
            cin >> a >> b >> c;
            update(a, c);
            update(b + 1, c);
        } else {
            cin >> t;
            cout << (query(t) ^ A[t]) << "\n";
        }
    }
}
