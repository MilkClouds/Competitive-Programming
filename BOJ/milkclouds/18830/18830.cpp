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

const int DIM = 11, MAX = 1e6;
using arr = array<int, DIM>;
arr l, r, t;

int D[DIM], DM[DIM + 1], Q;
ll S[MAX];

istream& operator >> (istream& is, arr& A){
    rep(i, 0, DIM) is >> A[i];
    return is;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    rep(i, 0, DIM) cin >> D[i];
    DM[DIM] = 1;
    rep2(i, 0, DIM) DM[i] = DM[i + 1] * D[i];
    rep(i, 0, DM[0]) cin >> S[i];
    rep(i, 1, DIM + 1){
        rep(j, 0, DM[0] - DM[i]){
            if(j / DM[i - 1] == (j + DM[i]) / DM[i - 1]) S[j + DM[i]] += S[j];
        }
    }
    cin >> Q;
    function<ll(arr, int)> query = [&](arr A, int i){
        if(i == DIM){
            int p = 0;
            rep(k, 0, DIM){
                if(A[k] == -1) return (ll)0;
                p += A[k] * DM[k + 1];
            }
            return S[p];
        }
        ll ret = 0;
        A[i] = l[i] - 2;
        ret -= query(A, i + 1);
        A[i] = r[i] - 1;
        ret += query(A, i + 1);
        return ret;
    };
    while(Q --> 0){
        cin >> l >> r;
        cout << query(t, 0) << "\n";
    }
}
