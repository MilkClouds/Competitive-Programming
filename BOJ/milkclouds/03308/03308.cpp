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
using vi = vector<int>;

int N, M, v;
vi A, B, smaller, bigger;
inline bool equals(int i, int j, vi& A){
    return !((smaller[j] != -1 && A[i - j + smaller[j]] >= A[i]) || (bigger[j] != -1 && A[i - j + bigger[j]] <= A[i]));
}
vi getPi(vi& A){
    int n = A.size();
    vi nxt(n), prv(n), pos(n);
    rep2(i, 0, n){
        nxt[i] = i + 1;
        prv[i] = i - 1;
        pos[A[i]] = i;
    }
    smaller.resize(n); bigger.resize(n);
    rep2(i, 0, n){
        int v = A[i];
        bigger[i] = nxt[v] == n ? -1 : pos[nxt[v]];
        smaller[i] = prv[v] == -1 ? -1 : pos[prv[v]];
        if(prv[v] != -1) nxt[prv[v]] = nxt[v];
        if(nxt[v] != n) prv[nxt[v]] = prv[v];
    }
    vi fail(n, 0);
    for(int j = 0, i = 1; i < n; i++){
        while(j > 0 && !equals(i, j, A)) j = fail[j - 1];
        if(equals(i, j, A)) fail[i] = ++j;
    }
    return fail;
}
vi kmp(vi& A, vi& B){
    int n = A.size(), m = B.size();
    vi&& fail = getPi(B);
    vi ret;
    for(int j = 0, i = 0; i < n; i++){
        while(j > 0 && !equals(i, j, A)) j = fail[j - 1];
        if(equals(i, j, A)) j++;
        if(j == m) {ret.eb(i - m + 1); j = fail[j - 1];}
    }
    return ret;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M; A.resize(N); B.resize(M);
    rep(i, 0, N){
        cin >> v;
        A[v - 1] = i;
    }
    rep(i, 0, M) cin >> B[i];
    auto&& ret = kmp(B, A);
    cout << ret.size() << "\n";
    for(auto i: ret) cout << i + 1 << " ";
}
