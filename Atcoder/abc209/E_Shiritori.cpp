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

const int MAX = 2e5, NUM = 52, MAXT = 140608;
int N, ans[MAX], deg[MAXT];
bool selff[MAXT];
vector<int> adj[MAXT];
inline int conv(char c){
    if(c >= 'a') return c - 'a' + 26;
    return c - 'A';
}
struct ABC{
    string S;
    int a, b;
    void exec(){
        a = NUM * NUM * conv(S[0]) + NUM * conv(S[1]) + conv(S[2]);
        b = NUM * NUM * conv(S[S.size() - 3]) + NUM * conv(S[S.size() - 2]) + conv(S[S.size() - 1]);
        adj[b].pb(a);
        deg[a]++;
        if(a == b) selff[a] = 1;
    }
} S[MAX];
istream& operator >> (istream& cin, ABC& o){
    cin >> o.S;
    o.exec();
    return cin;
}
queue<int> Q;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> S[i];
    fill(ans, ans + MAXT, -1); // Draw
    rep(i, 0, MAXT) if(deg[i] == 0) {
        ans[i] = 0;
        Q.push(i);
    }
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(auto v:adj[u]){
            if(ans[v] == -1){
                deg[v]--;
                if(ans[u] == 0){
                    ans[v] = 1; Q.push(v);
                } else if(deg[v] == 0){
                    ans[v] = 0; Q.push(v);
                }
            }
        }
    }
    rep(i, 0, N){
        int tmp = ans[S[i].b];
        if(tmp == -1) cout << "Draw\n";
        else if(tmp == 0) cout << "Takahashi\n";
        else cout << "Aoki\n";
    }
}
