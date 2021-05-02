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

int A[10], cnt;
string S[3];
set<char> C;
map<char, int> cToi;
map<int, char> iToc;
bool flag;
ll eval(string S){
    ll ans = 0;
    for(auto c: S) {
        ans = (ans * 10 + A[cToi[c]]);
        if(ans == 0) flag = 1;
    }
    return ans;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> S[0] >> S[1] >> S[2];
    rep(i, 0, 3) for(auto c: S[i]) C.insert(c);
    if(C.size() > 10){
        cout << "UNSOLVABLE";
        return 0;
    }
    for(auto c: C) {
        cToi[c] = cnt;
        iToc[cnt++] = c;
    }
    rep(i, 0, 10) A[i] = i;
    do {
        flag = 0;
        if(eval(S[0]) + eval(S[1]) == eval(S[2]) && !flag){
            rep(i, 0, 3) cout << eval(S[i]) << "\n";
            return 0;
        }
    } while(next_permutation(A, A + 10));
    cout << "UNSOLVABLE";
}
