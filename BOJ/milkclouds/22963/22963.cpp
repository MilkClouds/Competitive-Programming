# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

const int MAX = 2e5 + 10;
int N, t, l = 1;
pi lis[MAX];
int pre[MAX], chk[MAX], A[MAX];

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    if(N == 2){
        cout << "YES\n1\n1 1";
        return 0;
    }
    if(N == 3){
        cout << "YES\n2\n1 1\n2 1";
        return 0;
    }
    fill(lis, lis + N, pi(numeric_limits<int>::max(), -1));
    fill(pre, pre + N, -1);
    rep(i, 0, N) {
        cin >> t;
        A[i] = t;
        auto pos = upper_bound(lis, lis + N, pi(t, i));
        *pos = pi(t, i);
        if(pos != lis) pre[i] = (pos - 1) -> y;
    }
    int u = lis[N - 4].y;
    if(u == -1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES\n3\n";
    while(~pre[u]){
        chk[u] = 1;
        u = pre[u];
    }
    chk[u] = 1;
    rep(i, 0, N) if(!chk[i]) cout << i + 1 << " " << l << "\n"; else l = A[i];
}
