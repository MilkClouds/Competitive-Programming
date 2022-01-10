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

const int MAX = 1e6;
int N, K, A[MAX];
priority_queue<int> pq;
map<int, int> mapping;
void ssort(){
    rep2(i, 1, N){
        int pos = mapping[pq.top()]; pq.pop();
        if(pos == i) continue;
        mapping[A[i]] = pos;
        mapping[A[pos]] = i;
        swap(A[pos], A[i]);
        if(--K == 0){
            rep(i, 0, N) cout << A[i] << " "; cout << endl;
        }
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    cinA(A, N);
    rep(i, 0, N) pq.push(A[i]), mapping[A[i]] = i;
    ssort();
    if(K > 0) cout << -1;
}
