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

const int MAX = 1e4 + 1;
int N, K, A[MAX];
vector<int> ans;
void update(int i){
    ans.eb(i);
    if(ans.size() == K){
        rep(i, 0, N) cout << A[i] << " ";
    }
}
void ssort(){
    rep(i, 1, N){
        int j = i - 1, s = A[i];
        while(0 <= j && s < A[j]){
            A[j + 1] = A[j];
            update(A[j--]);
        }
        if(j + 1 != i){
            A[j + 1] = s;
            update(s);
        }
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    cinA(A, N);
    ssort();
    if(ans.size() < K) cout << -1;
}
