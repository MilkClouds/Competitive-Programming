#include <bits/stdc++.h>

using namespace std;
int N;
pair<int,int> a[101];
vector<int> v;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i].first>>a[i].second;
	sort(a,a+N,cmp);
	v.push_back(0);
	for(int i=0;i<N;i++){
		auto t=lower_bound(v.begin(),v.end(),a[i].second);
		if(t==v.end()){
			v.push_back(a[i].second);
		}
		else
			*t=a[i].second;
	}
	cout<<N-v.size()+1;
}