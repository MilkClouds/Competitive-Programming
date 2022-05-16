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

const int MAX = 2e5 + 111;
int N, X, A[MAX], m, a, L[MAX], ans[MAX];
vector<int> aans[MAX];
/*
    vector<int> B(N); rep(i, 0, N) B[i] = i;
    do {
        int idx = 0;
        rep(i, 1, N){
            int tmp = abs(B[i] - B[i - 1]);
            if(idx == 0) L[idx++] = tmp;
            else{
                if(L[idx - 1] < tmp) L[idx++] = tmp;
                else{
                    L[lower_bound(L, L + idx, tmp) - L] = tmp;
                }
            }
        }
        if(ans[B[0]] < idx){
            ans[B[0]] = max(ans[B[0]], idx);
            aans[B[0]] = B;
        }
    } while (next_permutation(all(B)));
    rep(i, 0, N){
        cout << ans[i] << "\n";
        for(auto j: aans[i]) cout << j + 1 << " ";cout<<'\n';
    }
*/
void solve(int N, int ex = MAX){
    rep(i, 1, N) A[i] = A[i - 1] + (i % 2 ? 1 : -1) * (N % 2 == 0 && X == N / 2 + 1 ? -1 : 1) * i;
    m = *min_element(A, A + N);
    rep(i, 0, N) if((A[i] += 1 - m) == X) a = i;
    if(a && ex == MAX){
        cout << X << " "; solve(N - 1, X);
    } else {
        rep(i, 0, N) cout << (A[i] >= ex ? A[i] + 1 : A[i]) << " ";
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> X;
    solve(N);
}
