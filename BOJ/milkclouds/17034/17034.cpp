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

const int MAX = 1e5 + 1, INF = 1e9;
int N, k, i, B;
vector<int> L;
set<int> S[MAX];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    for(; i < N; i++){
        cin >> k;
        int j = lower_bound(all(L), k) - L.begin();
        if(j == L.size()){
            L.eb(k);
            S[j].insert(k);
        }
        else if(k < B){
            break;
        } else {
            if(*S[j].begin() < k){
                B = *--S[j].upper_bound(k);
                S[j].insert(k);
            } else {
                S[j].insert(k);
            }
        }
    }
    cout << i << endl;
}
