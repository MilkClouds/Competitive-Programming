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

int TC;
string N;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N;
        if((N[N.size() - 1] - '0') % 2 == 0) cout << "0\n";
        else{
            if((N[0] - '0') % 2 == 0) cout << "1\n";
            else {
                bool flag = 0;
                rep(i, 0, N.size()) if((N[i] - '0') % 2 == 0) flag = 1;
                cout << (flag ? 2 : -1) << "\n";
            }
        }
    }
}
