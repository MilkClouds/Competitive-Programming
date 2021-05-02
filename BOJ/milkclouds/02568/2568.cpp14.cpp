#include <bits/stdc++.h>

using namespace std;
int N;
pair<int,int> a[100001];
int fu[500001];
bool chk[100001];
vector<int> v;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i].first>>a[i].second;
	sort(a,a+N,cmp);
	for(int i=0;i<N;i++){
		auto t=lower_bound(v.begin(),v.end(),a[i].second);
		fu[a[i].first]=t-v.begin();
		if(t==v.end()){
			v.push_back(a[i].second);
		}
		else
			*t=a[i].second;
	}
	cout<<N-v.size()<<'\n';
	int cur=v.size()-1;
	for(int i=N;i;i--){
		if(cur==fu[a[i-1].first]){
			cur--;
			chk[i]=1;
		}
	}
	for(int i=1;i<=N;i++){
		if(!chk[i])
		cout<<a[i-1].first<<'\n';
	}
}