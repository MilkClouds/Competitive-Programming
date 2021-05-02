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

int TC, N, K, flag;
string S;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> N >> K >> S;
        map<char, int> M, M2;
        if(N % K) { cout << "-1\n"; continue; }
        rep(i, 0, N) M[S[i]]++;
        int tmp = 0;
        for(auto [c, cnt] : M){
            tmp += ((-cnt) % K + K) % K;
        }
        if(tmp == 0){
            rep(j, 0, N) cout << S[j];
            cout << "\n";
            continue;
        }
        flag = 0;
        rep2(i, 0, N) {
            M[S[i]]--;
            if(M[S[i]] == 0) M.erase(S[i]);
            M2.clear();
            int tmp = 0;
            for(auto [c, cnt] : M){
                M2[c] = ((-cnt) % K + K) % K;
                tmp += M2[c];
            }
            rep(j, S[i] + 1, 'z' + 1){
                int bias = 0;
                if(M2[j] == 0){
                    M2[j] = K - 1;
                    bias += K;
                }
                else {
                    M2[j]--;
                }
                if(i + tmp + bias <= N){
                    flag = 1;
                    rep(k, 0, i) cout << S[k];
                    cout << (char)j;
                    rep(_, 0, N - tmp - bias - i) cout << 'a';
                    for(auto [c, cnt]: M2) rep(_, 0, cnt) cout << c;
                    break;
                }
                if(bias) M2[j] = 0;
            }
            if(flag) break;
        }
        cout << "\n";
    }
}
