#include <iostream>
#include <queue>
using namespace std;

struct edge{
	int x,y,z;
	const bool operator <(edge b) const{
		return z<b.z;
	}
};
long long tot,ans;
int n,m,x,y,z,parent[100001],ranks[100001];
const int MOD=1e9;
priority_queue<edge> pq;

void init(int n){
	while(n--){parent[n]=n;ranks[n]=1;}
}
int find(int u){
	if(parent[u]==u)return u;
	return parent[u]=find(parent[u]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y>>z;
		pq.push({x,y,z});
		tot+=z;
	}
	init(n+1);
	while(!pq.empty()){
		edge t=pq.top();pq.pop();
		x=t.x,y=t.y,z=t.z;
		x=find(x),y=find(y);
		if(x!=y){
			ans=(ans+tot*ranks[x]*ranks[y])%MOD;
			parent[y]=x;
			ranks[x]+=ranks[y];
		}
		tot-=z;
	}
	cout<<ans<<endl;
	return 0;
}