#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int M,N,a,b,S=0,E=1;
long long total;
struct edge{
	int capacity,flow,to;
	edge *dual;
	edge():edge(0,0){}
	edge(int capacity,int to):capacity(capacity),to(to),flow(0),dual(nullptr){}
	int spare(){return capacity-flow;}
	void bleed(int i){
		flow+=i;
		dual->flow-=i;
	}
};
int conv(int person,int i){
	return person*(1+M)+i;
}
vector<edge*> adj[110005];
void make(int u,int v,int c1,int c2){
	edge *e1=new edge(c1,v),*e2=new edge(c2,u);
	e1->dual=e2;e2->dual=e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
//	printf("%d -> %d (%d %d)\n",u,v,c1,c2);
}
int main(){
	cin>>M>>N;
	for(int i=1;i<=M;i++){
		cin>>a;
		make(S,conv(1,i),a,0);
	}
	vector<int> vec;
	for(int i=1;i<=N;i++){
		cin>>a;
		if(!vec.empty()){
			for(int tmp=0;tmp<vec.size();tmp++){
				for(int tmp2=0;tmp2<vec.size();tmp2++){
					int x=vec[tmp],y=vec[tmp2];
					if(x==y)continue;
					make(conv(i-1,x),conv(i,y),INF,0);
				}
			}
			vec.clear();
		}
		if(i>1){
			for(int j=1;j<=M;j++){
				make(conv(i-1,j),conv(i,j),INF,0);
			}
		}
		for(int j=0;j<a;j++){
			cin>>b;
			make(conv(i,b),conv(i,0),INF,0);
			vec.push_back(b);
		}
		cin>>a;
		make(conv(i,0),E,a,0);
	}
	while(1){
		edge *path[110005]={0};
		queue<int> Q;Q.push(S);
		vector<int> prev(110005,-1);
		while(!Q.empty() && prev[E]==-1){
			int u=Q.front();Q.pop();
			for(auto v:adj[u]){
				if(prev[v->to]==-1&&v->spare()>0){
					Q.push(v->to);
					prev[v->to]=u;
					path[v->to]=v;
					if(v->to==E)break;
				}
			}
		}
		if(prev[E]==-1)break;
		int flow=INF;
		for(int i=E;i!=S;i=prev[i])flow=min(flow,path[i]->spare());
		for(int i=E;i!=S;i=prev[i])path[i]->bleed(flow);
		total+=flow;
	}
	cout<<total;
}