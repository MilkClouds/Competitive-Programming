#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5 + 1;
int N;
double L[MAX], R[MAX], S[MAX];
pair<double, double> A[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cout.precision(16);
    cout << fixed;
    rep(i, 0, N) cin >> A[i].x >> A[i].y;
    rep(i, 0, N){
        L[i] = (i ? L[i - 1] : 0) + A[i].x / A[i].y;
        S[i] = (i ? S[i - 1] : 0) + A[i].x;
    }
    rep2(i, 0, N - 1){
        R[i] = R[i + 1] + A[i + 1].x / A[i + 1].y;
    }
    rep(i, 0, N){
        if(L[i] >= R[i]){
            double tl = (i ? L[i - 1] : 0);
            double tr = R[i];
            cout << ((i ? S[i - 1] : 0) + (A[i].x - (tl - tr) * A[i].y) / 2) << "\n";
            return 0;
        }
    }
}
