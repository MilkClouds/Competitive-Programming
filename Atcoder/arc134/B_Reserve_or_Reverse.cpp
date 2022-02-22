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

const int MAX = 2e5 + 1;
int N;
string S;
set<pi> pq;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> S;
    rep(i, 1, N){
        pq.emplace(-S[i], i);
    }
    int i = 0, j = N;
    while(!pq.empty()){
        if(-pq.rbegin()->x < S[i]){
            int tmp = pq.rbegin()->y;
            rep(k, pq.rbegin()->y, j){
                pq.erase(pi(-S[k], k));
            }
            swap(S[i], S[tmp]);
            j = tmp;
        }
        i++;
        pq.erase(pi(-S[i], i));
    }
    cout << S << endl;
}
