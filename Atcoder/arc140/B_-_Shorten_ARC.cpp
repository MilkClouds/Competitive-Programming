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

int N, cnt;
string S;
vector<int> A;
multiset<int> B;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> S;
    rep(i, 0, N - 1){
        if(S[i] == 'A' && S[i + 1] == 'R') A.eb(i);
    }
    for(auto i: A){
        int j;
        for(j = 0; i - j >= 0 && i + j + 2 < N && S[i - j] == 'A' && S[i + j + 2] == 'C'; j++);
        if(j) B.insert(j);
    }
    while(!B.empty()){
        if(B.size() > 1){
            int r = *B.rbegin();
            B.erase(B.find(r)); if(r > 1) B.insert(r - 1);
            B.erase(B.begin());
            cnt += 2;
        } else {
            int r = *B.begin();
            cnt += (r > 1) + 1;
            B.erase(B.find(r));
        }
    }
    cout << cnt << "\n";
}