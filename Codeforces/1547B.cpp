# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

int TC;
string S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> S;
        int ST = -1;
        bool flag = 0;
        rep(i, 0, S.size()) if(S[i] == 'a') ST = i;
        if(ST == -1) {
            cout << "NO\n";
            continue;
        }
        vector<bool> vis(S.size());
        priority_queue<pair<char, int>> Q; Q.emplace(-'a', ST); vis[ST] = 1;
        int cnt = 0;
        while(!Q.empty()){
            if(-Q.top().x != 'a' + cnt) break;
            int u = Q.top().y; Q.pop(); cnt++; 
            for(auto v: {u - 1, u + 1}){
                if(0 <= v && v < S.size() && !vis[v]){
                    Q.emplace(-S[v], v);
                    vis[v] = 1;
                }
            }
        }
        cout << (cnt == S.size() ? "YES" : "NO") << "\n";
    }
}
