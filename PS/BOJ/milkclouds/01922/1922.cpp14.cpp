#include <bits/stdc++.h>
using namespace std;
int N,M,parents[1001],ranks[1001],a,b,c,ans;
struct edge{
	int a,b,c;
	const bool operator < (edge x) const {
		return c>x.c;
	}
};
priority_queue<edge> pq;
void init(int n){while(n--){parents[n]=n;ranks[n]=1;}}
int find(int u){
	if(parents[u]==u)return u;
	return parents[u]=find(parents[u]);
}
bool merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return 0;
	if(ranks[u]<ranks[v])swap(u,v);
	parents[v]=u;
	if(ranks[u]==ranks[v])ranks[u]++;
}
int main(){
	cin>>N>>M;
	init(N+1);
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		pq.push({a,b,c});
	}
	while(!pq.empty()){
		edge t=pq.top();pq.pop();
		a=t.a,b=t.b,c=t.c;
		a=find(a),b=find(b);
		if(a==b) continue;
		merge(a,b);
		ans+=c;
	}
	cout<<ans;
}