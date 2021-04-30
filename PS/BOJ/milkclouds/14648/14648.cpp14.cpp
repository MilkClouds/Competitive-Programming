#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAX=1e5;
ll N,Q,A[MAX],tree[MAX],t,a,b,c,d;

void update(int u,int v){
	for(;u<=N;u+=u&-u)tree[u]+=v;
}
ll query(int u){
	ll ret=0;
	for(;u;u&=u-1)ret+=tree[u];
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N;i++){cin>>A[i];
		update(i,A[i]);
	}
	while(Q--){
		cin>>t>>a>>b;
		if(t==1){
			cout<<query(b)-query(a-1)<<"\n";
			update(b,-A[b]); update(a,-A[a]); update(b, A[a]); update(a, A[b]);
			swap(A[a],A[b]);
		}
		else{
			cin>>c>>d;
			cout<<query(b)-query(a-1)-query(d)+query(c-1)<<"\n";
		}
	}
}