#include <bits/stdc++.h>
using namespace std;
const int dx[]={0,0,-1,1},dy[]={1,-1,0,0},INF=1e9;
int N,M,S,E,ans;
string city[101];
struct edge{
	int to,c,f;
	edge *dual;
	edge():edge(0,0){}
	edge(int to,int c):to(to),c(c),f(0),dual(nullptr){}
	int spare(){return c-f;}
	int bleed(int amt){
		f+=amt;
		dual->f-=amt;
	}
};
vector<edge*> adj[20100];
void make(int u,int v,int c1,int c2){
	edge *uv=new edge(v,c1), *vu=new edge(u,c2);
	uv->dual=vu;
	vu->dual=uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
inline int conv(int i,int j){return i*M+j;}
inline bool can(int i,int j){return 0<=i&&i<N&&0<=j&&j<M &&city[i][j]!='#';}
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>city[i];
	for(int i=0;i<N;i++)for(int j=0;j<M;j++){
		if(city[i][j]=='K')S=conv(i,j)*2+1;
		if(city[i][j]=='H')E=conv(i,j)*2;
		if(city[i][j]=='#')continue;
		make(conv(i,j)*2,conv(i,j)*2+1,1,0);
		for(int t=0;t<4;t++){
			int nx=i+dx[t],ny=j+dy[t];
			if(can(nx,ny)){
				make(conv(i,j)*2+1,conv(nx,ny)*2,INF,0);
			}
		}
	}
	while(1){
		edge *edges[20100]={nullptr};
		queue<int> Q;Q.push(S);
		int prev[20100];
		fill(prev,prev+N*M*2,-1);
		while(!Q.empty() && prev[E]==-1){
			int u=Q.front();Q.pop();
			for(edge *e:adj[u]){
				int v=e->to;
				if(prev[v]==-1 && e->spare()>0){
					edges[v]=e;
					prev[v]=u;
					Q.push(v);
					if(prev[E]!=-1)break;
				}
			}
		}
		if(prev[E]==-1)break;
		if(prev[E]==S){cout<<-1;return 0;}
		for(int i=E;i!=S;i=prev[i])edges[i]->bleed(1);
		ans++;
	}
	cout<<ans;
}