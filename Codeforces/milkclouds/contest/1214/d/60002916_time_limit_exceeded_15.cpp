#include <bits/stdc++.h>
using namespace std;
const int dx[]={0,1},dy[]={1,0},INF=1e9;
int N,M,S,E,ans;
string city[1000001];
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
vector<edge*> adj[2000005];
void make(int u,int v,int c1,int c2){
	edge *uv=new edge(v,c1), *vu=new edge(u,c2);
	uv->dual=vu;
	vu->dual=uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
inline int conv(int i,int j){return i*M+j;}
inline bool can(int i,int j){return 0<=i&&i<N&&0<=j&&j<M &&city[i][j]!='#';}
vector<int> preev;
unordered_map<int,edge*> edges;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>city[i];
	city[0][0]='K'; city[N-1][M-1]='H';
	for(int i=0;i<N;i++)for(int j=0;j<M;j++){
		if(city[i][j]=='K')S=conv(i,j)*2+1;
		if(city[i][j]=='H')E=conv(i,j)*2;
		if(city[i][j]=='#')continue;
		make(conv(i,j)*2,conv(i,j)*2+1,1,0);
		for(int t=0;t<2;t++){
			int nx=i+dx[t],ny=j+dy[t];
			if(can(nx,ny)){
				make(conv(i,j)*2+1,conv(nx,ny)*2,INF,0);
			}
		}
	}
	while(1){
		queue<int> Q;Q.push(S);
		preev.clear();preev.resize(N*M*2+1,-1);
		while(!Q.empty() && preev[E]==-1){
			int u=Q.front();Q.pop();
			for(edge *e:adj[u]){
				int v=e->to;
				if(preev[v]==-1 && e->spare()>0){
					edges[v]=e;
					preev[v]=u;
					Q.push(v);
					if(preev[E]!=-1)break;
				}
			}
		}
		if(preev[E]==-1)break;
		if(preev[E]==S){cout<<-1;return 0;}
		for(int i=E;i!=S;i=preev[i])edges[i]->bleed(1);
		ans++;
	}
	cout<<ans;
}