#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int n,x,y,t,tree[100000],range,mm[75001];
vector<pii> v(75001);

int sum(int u){
	int ret=0;
	for(;u;u&=u-1)ret+=tree[u];
	return ret;
}
void update(int u,int value){
	for(;u<=range;u+=u&-u)tree[u]+=value;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		range=1;
		long long ret=0;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			v[i]={x,y};
		}
		sort(v.begin(), v.begin()+n, [](pii &a,pii &b){
			return a.second<b.second;
		});
		for(int i=0;i<v.size();i++){
			if(i>0 and v[i].second!=v[i-1].second)range++;
			mm[i]=range;
		}
		for(int i=0;i<n;i++)v[i].second=1+range-mm[i];
		for(int i=1;i<=range;i++)tree[i]=0;
		sort(v.begin(),v.begin()+n);
		for(int j=0;j<n;j++){
			auto i=v[j];
			x=i.first,y=i.second;
			ret+=sum(y);
			update(y,1);
		}
		cout<<ret<<'\n';
	}

}