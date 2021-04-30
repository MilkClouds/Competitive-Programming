#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
const int MAX=1e4+5;
struct Edge{
	int u,v,d,ee,le;
	Edge():Edge(0,0,0){}
	Edge(int u,int v,int d):u(u),v(v),d(d){}
} e[100005];
int N,M,ee[MAX],le[MAX],cnt,S,E,d;
bool visit[MAX];
vector<Edge*> pre[MAX],suc[MAX];
vector<int> ts;

void DFS(int u){
	if(visit[u])return;
	visit[u]=1;
	for(auto E:suc[u])DFS(E->v);
	ts.push_back(u);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	rep(i,0,M){
		cin>>S>>E>>d;
		e[i]=Edge(S,E,d);
		suc[S].push_back(&e[i]);
		pre[E].push_back(&e[i]);
	}
	cin>>S>>E;
	DFS(S);
	for(int i=ts.size()-1;~i;i--){
		for(auto edge:suc[ts[i]]){
			ee[edge->v]=max(ee[edge->v], ee[edge->u]+edge->d);
		}
	}
	fill(le,le+1+N,1e9);
	le[E]=ee[E];
	for(int i=0;i<ts.size();i++){
		for(auto edge:pre[ts[i]]){
			le[edge->u]=min(le[edge->u], le[edge->v]-edge->d);
		}
	}
	for(int i=0; i<M; i++){
        e[i].ee = ee[e[i].u];
		e[i].le = le[e[i].v] - e[i].d;
		if(e[i].ee == e[i].le) cnt++;
	}
	cout<<ee[E]<<endl<<cnt;
}