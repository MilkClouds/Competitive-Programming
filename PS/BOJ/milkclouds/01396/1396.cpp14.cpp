#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> ti3;
int N,M,a,b,c,Q,x,y,hi,parent[100011],sz[100011],querysz[100011];
vector<ti3> v;
pii query[100011];
pii lohi[100011];

//find,merge,init: Union Find(정점,N에 적용)
int find(int u){
	return u==parent[u]?u:parent[u]=find(parent[u]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return;
	if(rand()&1)swap(u,v);
	parent[u]=v;
	sz[v]+=sz[u];
}
void init(int N){
	for(int i=1;i<=N;i++){
		parent[i]=i;
		sz[i]=1;
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	cin>>Q;
	for(int i=0;i<Q;i++){
		cin>>x>>y;
		query[i]={x,y};
		lohi[i]={0,M};
	}
	//edges는 고유값(c) 기준 정렬
	sort(v.begin(), v.end(),[](ti3 &a,ti3 &b){
		return get<2>(a)<get<2>(b);
	});
	while(1){
		vector<vector<int>> qlist(M+2,vector<int>());
		init(N);
		bool flag=false;
		for(int i=0;i<Q;i++){
			auto [l,h]=lohi[i];
			if(l<h){
				flag=true;
				qlist[l+h>>1].push_back(i);
				//cout<<i<<" "<<l<<" "<<h<<" pushed\n";
			}
		}
		if(!flag)break;
		for(int i=0;i<M;i++){
			merge(get<0>(v[i]),get<1>(v[i]));
			for(auto j:qlist[i]){
				x=find(query[j].x),y=find(query[j].y);
				auto& [l,h]=lohi[j];
				if(x==y){
					h=i;
					querysz[j]=sz[x];
				}
				else{
					l=i+1;
				}
			}
		}
	}
	for(int i=0;i<Q;i++){
		if(querysz[i])cout<<get<2>(v[lohi[i].y])<<" "<<querysz[i]<<"\n";
		else cout<<"-1\n";
	}
}