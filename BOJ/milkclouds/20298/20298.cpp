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
using pi = pair<int, int>;
using vi = vector<int>;

int N, M, v, C;
vector<pi> Bs;
vi A, B, smaller, bigger, same;
inline bool equals(int i, int j, vi& A){
    if(~same[j]) return A[i - j + same[j]] == A[i];
    return !((~smaller[j] && A[i - j + smaller[j]] >= A[i]) || (~bigger[j] && A[i - j + bigger[j]] <= A[i]));
}
vi getPi(vi& A){
    int n = A.size();
    vi nxt(C), prv(C), cnt(C), pos(C);
    rep(i, 0, C){
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }
    rep2(i, 0, n){
        pos[A[i]] = i;
        cnt[A[i]]++;
    }
    rep2(i, 0, n){
        int v = A[i];
        if(--cnt[v]) same[i] = pos[v];
        else{
            if(prv[v] != -1) smaller[i] = pos[prv[v]], nxt[prv[v]] = nxt[v];
            if(nxt[v] != C) bigger[i] = pos[nxt[v]], prv[nxt[v]] = prv[v];
        }
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
    cin >> N >> M;
    Bs.resize(M); A.resize(N + M - 1); B.resize(M);
    smaller.assign(M, -1); bigger.assign(M, -1); same.assign(M, -1);
    cinA(A, N);
    rep(i, 1, M) A[i + N - 1] = A[i - 1];
    rep(i, 0, M) cin >> Bs[i].x, Bs[i].y = i;
    sort(all(Bs)); 
    rep(i, 0, M) B[Bs[i].y] = (i && Bs[i].x == Bs[i - 1].x) ? B[Bs[i - 1].y] : C++;
    auto&& ret = kmp(A, B);
    cout << ret.size() << endl;
}
