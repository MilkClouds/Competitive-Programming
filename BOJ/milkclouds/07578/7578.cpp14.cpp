#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+5;
int N,A[MAX],tree[MAX],b;
long long ret;
unordered_map<int,int> pos;
void update(int u,int v){
	for(;u<=N;u+=u&-u)tree[u]+=v;
}
int query(int u){int ret=0;for(;u;u&=u-1)ret+=tree[u];return ret;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
		pos[A[i]]=i+1;
	}
	for(int i=0;i<N;i++){
		cin>>b;
		ret+=query(N)-query(pos[b]);
		update(pos[b],1);
	}
	cout<<ret<<endl;
}