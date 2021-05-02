#include <bits/stdc++.h>
using namespace std;
const int INF=1e9,MAX=20005;

inline void conv(int& n){
	n=n<0? -n*2 : n*2-1;
}
inline int nai(int n){return n&1?n+1:n-1;}

int N,M,u,v,dfsn[MAX],sccn[MAX],cnt,scc,p[MAX],save[MAX];
vector<int> adj[MAX];
stack<int> S;

int GetSCC(int u){
	dfsn[u]=++cnt;
	S.push(u);
	int last=cnt;
	for(auto v:adj[u]){
		if(dfsn[v]==0)last=min(last,GetSCC(v));
		else if(sccn[v]==0)last=min(last,dfsn[v]);
	}
	if(dfsn[u]==last){
		sccn[u]=++scc;
		while(S.top()^u){
			sccn[S.top()]=scc;
			S.pop();
		} S.pop();
	}
	return last;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	int limit=N*2+1;
	for(int i=0;i<M;i++){
		cin>>u>>v;
		conv(u);conv(v);
        adj[nai(u)].push_back(v);
        adj[nai(v)].push_back(u);
	}
	for(int i=1;i<limit;i++)if(dfsn[i]==0)GetSCC(i);
	for(int i=1;i<limit;i+=2){
		if(sccn[i]==sccn[nai(i)]){cout<<0;return 0;}
	}
	for(int i=1;i<limit;i++)p[i]=i;
	sort(p+1,p+limit,[](int i,int j){return sccn[i]>sccn[j];});
	fill(save,save+N,-1);
	for(int i=1;i<limit;i++){
		if(~save[(p[i]-1)/2])continue;
		save[(p[i]-1)/2]=!(p[i]&1);
	}
	cout<<1<<"\n";
	for(int i=0;i<N;i++){
		cout<<save[i]<<" ";
	}
}