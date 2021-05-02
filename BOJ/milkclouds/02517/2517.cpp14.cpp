#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5;
int N,a[MAX],bs,tree[MAX];
map<int,int> b;
void update(int u,int diff){
	for(;u<=bs;u+=u&-u)tree[u]+=diff;
}
int query(int u){
	int sum=0;
	for(;u;u&=u-1)sum+=tree[u];
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
		if(b[a[i]]==0)b[a[i]]=1;
	}
	for(auto [i,j]:b)b[i]=++bs;
	for(int i=0;i<N;i++){
		a[i]=b[a[i]];
		cout<<i-query(a[i])+1<<"\n";
		update(a[i],1);
	}
}