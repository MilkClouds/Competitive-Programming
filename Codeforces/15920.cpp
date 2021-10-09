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

const int MAX = 1000;
ll TC, N, H, A[MAX];

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC --> 0){
        cin >> N >> H;
        rep(i, 0, N) cin >> A[i];
        sort(A, A + N, greater<int>());
        ll div = H / (A[0] + A[1]);
        ll mod = H % (A[0] + A[1]);
        cout << ((mod > A[0] ? 2 : (mod > 0 ? 1: 0)) + div * 2) << '\n';
    }
}
