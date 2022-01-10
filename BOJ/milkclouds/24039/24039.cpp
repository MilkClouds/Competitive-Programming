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
int arr[MAX], N;
vector<int> pn;
void eratos(){
    pn.eb(2);
    for(int i = 3; i < MAX; i += 2){
        if(arr[i]) continue;
        pn.eb(i);
        for(int j = i * i; j < MAX; j += i) arr[j] = 1;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    eratos();
    cin >> N;
    rep(i, 0, pn.size()){
        if(pn[i] * pn[i + 1] > N){
            cout << (pn[i] * pn[i + 1]) << endl;
            return 0;
        }
    }
}
