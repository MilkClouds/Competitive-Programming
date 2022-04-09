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

const int MAX = 2e5 + 2;
int N, D[MAX], C[MAX];
ll s;
pi A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i].x, A[i].y = i;
    sort(A, A + N);
    fill(D, D + N, 1);
    rep(i, N / 2, N){
        D[A[i].y] = -1; s += A[i].x;
    }
    rep(i, 0, N) C[i + 1] = C[i] + D[i];
    cout << (min_element(C, C + N) - C) << " " << s << endl;
}
