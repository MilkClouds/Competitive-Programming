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

const int MAX = 2e5 + 1;
int a[2], b[2];
char ans[MAX], ans2[MAX];
int TC, N;
string S;
char inv(char c){
    if(c == '(') return ')';
    return '(';
}
bool pos(char* c){
    int S = 0;
    while(*c){
        if(*c == '(') S++;
        else S--;
        if(S < 0) return 0;
        c++;
    }
    return S == 0;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> N >> S;
        fill(a, a + 2, 0);
        fill(b, b + 2, 0);
        fill(ans, ans + N + 1, 0);
        fill(ans2, ans2 + N + 1, 0);
        rep(i, 0, N) a[S[i] - '0']++;
        if(S[0] == '0' || (a[0] & 1)) {cout << "NO\n"; continue;}
        rep(i, 0, N) {
            b[S[i] - '0']++;
            if(S[i] == '0'){
                ans[i] = b[S[i] - '0'] % 2 ? '(' : ')';
                continue;
            }
            if(a[1] >= b[1] * 2) ans[i] = '(';
            else ans[i] = ')';
        }
        rep(i, 0, N){
            if(S[i] == '0') ans2[i] = inv(ans[i]);
            else ans2[i] = ans[i];
        }
        if(!(pos(ans) && pos(ans2))) {cout << "NO\n"; continue;}
        cout << "YES\n";
        cout << ans << "\n";
        cout << ans2 << "\n";
    }
}
