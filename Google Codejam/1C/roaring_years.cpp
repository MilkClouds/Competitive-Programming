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

int TC;
ll Y;
string S;
vector<int> v;
bool choose(int n, int N){
    if(n == N){
        if(v.size() == 1) return 0;
        int prev = -1, k = 0;
        for(auto i: v) {
            string tmp = S.substr(k, i);
            if(tmp[0] == '0') return 0;
            if(~prev && stoi(tmp) != prev + 1) return 0;
            prev = stoi(tmp);
            k += i;
        }
        return 1;
    }
    bool ans = 0;
    rep(i, 1, N - n + 1){
        v.push_back(i);
        ans |= choose(n + i, N);
        if(ans) return 1;
        v.pop_back();
    }
    return 0;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    rep(tc, 1, TC + 1){
        cin >> Y;
        while(1){
            Y++;
            v.clear();
            S = to_string(Y);
            if(choose(0, S.size())){
                printf("Case #%d: %d\n", tc, Y);
                break;
            }
        }
    }
}
