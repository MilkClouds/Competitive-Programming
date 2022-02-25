#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

ll N;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    if(N == 1) cout << "Yes\n0 0\n";
    else if(N == 4){
        cout << "Yes\n1 2 1 3 2 0 0 3 ";
    } else if(N == 5){
        cout << "Yes\n4 0 0 2 3 4 2 1 3 1 ";
    } else if(N % 4 == 0 && N > 5){
        cout << "Yes\n";
        ll k = N / 4;
        rep2(i, 1, 2 * k + 1) cout << (2 * i - 1) << " ";
        cout << N - 2 << " ";
        rep(i, 1, 2 * k + 1) cout << (2 * i - 1) << " ";
        cout << 2 * k - 2 << " ";
        rep2(i, 1, 2 * k - 1) if(i != k - 1) cout << i * 2 << " ";
        cout << N - 2 << " " << 2 * k - 2 << " ";
        rep(i, 1, k - 1) cout << i * 2 << " ";
        cout << "0 0 ";
        rep(i, k, 2 * k - 1) cout << i * 2 << " ";
    } else if(N % 4 == 1 && N > 5){
        cout << "Yes\n";
        ll k = N / 4;
        rep2(i, 1, 2 * k + 1) cout << 2 * i << " ";
        cout << 2 * k + 1 << " " << N - 2 << " ";
        rep(i, 1, 2 * k + 1) cout << 2 * i << " ";
        cout << 2 * k + 1 << " ";
        rep2(i, 1, 2 * k) if(i != k + 1) cout << i * 2 - 1 << " ";
        cout << N - 2 << " ";
        rep(i, 1, k + 1) cout << (i * 2 - 1) << " ";
        cout << "0 0 ";
        rep(i, k + 2, 2 * k) cout << (i * 2 - 1) << " ";
    } else cout << "No";
}
