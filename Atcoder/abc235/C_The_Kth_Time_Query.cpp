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

const int MAX = 2e5;
int N, Q, A[MAX], a, b;
map<int, vector<int>> M;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> Q;
    cinA(A, N);
    rep(i, 0, N){
        if(M.find(A[i]) == M.end()) M[A[i]] = vector<int>();
        M[A[i]].eb(i + 1);
    }
    rep(i, 0, Q){
        cin >> b >> a; a--;
        if(M.find(b) == M.end()) cout << "-1\n";
        else{
            if(M[b].size() > a) cout << M[b][a] << "\n";
            else cout << "-1\n";
        }
    }
}
