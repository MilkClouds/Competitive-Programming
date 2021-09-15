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

int TC, N;
string S;
int give(int cnt){
    if(cnt == 0) return 0;
    if(cnt == 1) return 1;
    else {
        b += cnt & 1;
        a += cnt - (cnt & 1);
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> N >> S;
        int cnt = 0, cnt2 = 0;
        int a = 0, b = 0;
        rep(i, 0, N / 2) {
            if(S[i] != S[N - 1 - i]){
                cnt++;
                S[i] = S[N - 1 - i] = '1';
            }
        }
        rep(i, 0, N) if(S[i] == '0') cnt2++;
        //cout << cnt << " " << cnt2 << endl;
        if(cnt > 1){
            a += 1;
            b += cnt - 1;
            if(cnt2 == 1) a++;
            else if(cnt2) {
                a += cnt2 & 1;
                b += cnt2 - (cnt2 & 1);
            }
        } else if(cnt == 1){
            if(cnt2 == 0) b++;
            else if(cnt2 == 1) {a=b=1;}
            else {
                a++;
                a += cnt2 & 1;
                b += cnt2 - (cnt2 & 1);
            }
        } else { 
            if(cnt2 == 1) b++;
            else if(cnt2){
                b += cnt2 & 1;
                a += cnt2 - (cnt2 & 1);
            }
        }
        if(a > b) cout << "BOB\n";
        else if(a < b) cout << "ALICE\n";
        else cout << "DRAW\n";
    }
}
