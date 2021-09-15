#include <bits/stdc++.h>
using namespace std;
const int MAX=3e5+5;
int N,op[MAX],req[MAX],p,leap;
vector<int> adj[MAX];
int dfs(int u){
    if(adj[u].size()==0){leap++;return 1;}
    int ret=op[u]==0?0:1e9;
    for(auto v:adj[u]){
        if(op[u]==0)ret+=dfs(v);
        else ret=min(ret,dfs(v));
    }
    return req[u]=ret;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++)cin>>op[i];
    for(int i=1;i<N;i++){
        cin>>p;
        adj[p-1].push_back(i);
    }
    dfs(0);
    cout<<leap+1-dfs(0);
}