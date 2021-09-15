# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;


void solve(){
    int N, M, R = -1;
    string S[51];
    cin >> N >> M;
    rep(i, 0, N) cin >> S[i];
    rep(i, 0, N) rep(j, 0, M){
        if(S[i][j] != '.'){
            //cout << R << " "<<  i << " " << j << " " << (i + j & 1) << " " << ((S[i][j] == 'R') ^ (i + j & 1)) << endl;
            if(R == -1) R = (S[i][j] == 'R') ^ (i + j & 1);
            else{
                if(R == ((S[i][j] == 'R') ^ (i + j & 1))) continue;
                cout << "NO\n";
                return;
            }
        }
    }
    if(R == -1) R = 0;
    cout << "YES\n";
    rep(i, 0, N) {
        rep(j, 0, M){
            cout << ((R ^ (i + j & 1)) ? 'R' : 'W');
        }
        cout << '\n';
    }
}

int TC;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        solve();
    }
}
