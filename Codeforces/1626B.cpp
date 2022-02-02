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

int T;
string X;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> X;
        bool flag = 0;
        rep2(i, 0, X.size() - 1){
            int tmp = X[i] + X[i + 1] - '0' - '0';
            if(tmp >= 10){
                rep(j, 0, i) cout << X[j];
                cout << tmp;
                rep(j, i + 2, X.size()) cout << X[j];
                cout << "\n";
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        cout << (X[0] + X[1] - '0' - '0');
        rep(i, 2, X.size()) cout << X[i];
        cout << "\n";
    }
}
