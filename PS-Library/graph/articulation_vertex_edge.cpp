#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

const int MAX = 1e5 + 1;

set<int> adj[MAX];


int S[MAX];
bool isCut[MAX];
int dfs(int u, int nth = 0){
    S[u] = ++nth;
    int ret = S[u], childs = 0;
    for(auto v: adj[u]){
        if(S[v] == 0){
            childs++;
            int child = dfs(v, nth);
            if(nth > 1 && S[u] <= child) isCut[u] = 1;
            ret = min(ret, child);
        }
        else ret = min(ret, S[v]);
    }
    if(nth == 1 && childs >= 2) isCut[u] = 1;
    return ret;
}

set<pi> isCut;
int dfs(int u, int pre, int nth = 0){
    S[u] = ++nth;
    int ret = S[u];
    for(auto v: adj[u]){
        if(v == pre) continue;
        if(S[v] == 0){
            int child = dfs(v, u, nth);
            if(S[u] < child) isCut.emplace(min(u, v), max(u, v));
            ret = min(ret, child);
        }
        else ret = min(ret, S[v]);
    }
    return ret;
}