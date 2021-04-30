#include <bits/stdc++.h>
using namespace std;

int T,N,M,a,b,in[505],t[505],r[505],flag,cnt;
queue<int> Q;
stack<int> ans;
vector<int> adj[505];
bool inv[505][505],visit[505];
int main(){
	cin>>T;
	while(T--){
		cin>>N;
		fill(in,in+N+1,0);
		for(int i=1;i<=N;i++)fill(inv[i],inv[i]+N+1,0),adj[i].clear();
		for(int i=1;i<=N;i++){cin>>t[i];r[t[i]]=i;}
		cin>>M;
		for(int i=0;i<M;i++){
			cin>>a>>b;
			if(r[a]<r[b])swap(a,b);
			adj[b].push_back(a);
			inv[a][b]=inv[b][a]=1;
			in[a]++;
		}
		for(int i=1;i<N;i++){
			for(int j=i+1;j<=N;j++){
				if(inv[t[i]][t[j]])continue;
				adj[t[j]].push_back(t[i]);
				in[t[i]]++;
			}
		}
		while(!Q.empty())Q.pop();while(!ans.empty())ans.pop();
		fill(visit+1,visit+N+1,0);
		flag=cnt=0;
		for(int i=1;i<=N;i++)if(in[i]==0)Q.push(i),visit[i]=1;
		while(!Q.empty()&&!flag){
			if(Q.size()>1)
			{
				cout<<"?\n";
				flag=1;
				break;
			}
			int u=Q.front();Q.pop();
			cnt++;
			ans.push(u);
			for(auto v:adj[u])
			{
				in[v]--;
				if(in[v]==0)Q.push(v),visit[v]=1;
			}
		}
		if(flag)continue;
		if(cnt!=N){cout<<"IMPOSSIBLE\n";continue;}
		while(!ans.empty())cout<<ans.top()<<" ",ans.pop();
		cout<<"\n";
	}
}