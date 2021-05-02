#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MAX=1e5+5;
int N,u,v;
bool visit[MAX];
vector<int> adj[MAX];
queue<int> Q;
int main(){
    cin>>N;
    for(int i=1;i<N;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }cin>>u;
    if(u!=1){cout<<0;return 0;}
    Q.push(1);visit[1]=1;
    while(!Q.empty()){
        u=Q.front();Q.pop();
        unordered_set<int> s;
        for(auto v:adj[u]){
                if(visit[v])continue;
                visit[v]=1;
                s.insert(v);
        }
        for(int i=0;i<s.size();i++){
                cin>>u;
                if(s.find(u)!=s.end())Q.push(u);
                else{cout<<0;return 0;}
        }
    }
    cout<<1;
}