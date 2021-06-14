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

const int INF = 2e9;
int N, K, dist[501], pre[501], ans, r, vis[501];
vector<int> v;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    fill(dist, dist + N + 1, INF);
    fill(pre, pre + N + 1, -1);
    queue<int> Q; Q.push(0); dist[0] = 0;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int d = K; d >= -K; d -= 2){
            int v = u + d;
            if(v > N || v < 0 || u < (K - d) / 2 || (K - (K - d) / 2) + u > N) continue;
            if(dist[u] + 1 < dist[v]){
                dist[v] = dist[u] + 1;
                Q.push(v);
                pre[v] = u;
            }
        }
    }
    if(pre[N] == -1){
        cout << -1;
        return 0;
    }
    int t = N;
    while(t){
        v.pb(t);
        t = pre[t];
    }
    v.pb(0);
    reverse(all(v));
    rep(i, 0, v.size() - 1){
        int d = v[i + 1] - v[i];
        int ovl = (K - d) / 2, rem = K - ovl;
        cout << "? ";
        rep(i, 0, N){
            if(vis[i] && ovl){
                cout << i + 1 << " ";
                vis[i] ^= 1;
                ovl--;
            }
            else if(!vis[i] && rem){
                cout << i + 1 << " " ;
                vis[i] ^= 1;
                rem--;
            }
            if(ovl == 0 && rem == 0) break;
        }
        cout << endl;
        cin >> r;
        ans ^= r;
    }
    cout << "! " << ans;
}
