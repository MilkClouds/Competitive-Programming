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
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e6;
int N, A[MAX], B[MAX], ans;
struct myset{
    int l = MAX, r = -1;
    int insert(int i){
        return (r = max(r, i)) - (l = min(l, i));
    }
};
struct twoset{
    myset odd, even;
    int insert(int i){
        return (i % 2 ? odd : even).insert(i);
    }
};
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N);
    rep2(i, 0, 20){
        map<int, twoset> M;
        M[0].insert(-1);
        rep(j, 0, N){
            if(A[j] & (1 << i)){
                ans = max(ans, M[B[j]].insert(j));
            } else {
                M.clear();
                M[B[j]].insert(j);
            }
            B[j] = (j ? B[j - 1] : 0) ^ (A[j] >> i << i);
        }
    }
    cout << ans << endl;
}
