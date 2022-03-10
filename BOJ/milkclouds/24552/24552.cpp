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

const int MAX = 1e5 + 1;
string S;
int A[MAX], B[MAX];
int solve(){
    int k = 0, ret = 0;
    rep(i, 0, S.length()){
        k += (S[i] == '(') - (S[i] == ')');
        A[i] = k;
    }
    B[S.length() - 1] = A[S.length() - 1];
    rep2(i, 0, S.length() - 1){
        B[i] = min(B[i + 1], A[i]);
    }
    rep(i, 0, S.length()){
        if(S[i] == '(') ret += B[i] == 1;
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> S;
    int tmp = solve();
    reverse(all(S));
    rep(i, 0, S.length()) S[i] = S[i] == '(' ? ')' : '(';
    cout << solve() + tmp << "\n";
}
