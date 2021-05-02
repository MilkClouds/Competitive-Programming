#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
int N,t,cur,len;
priority_queue<pii> pq;
vi root;
vector<vi> branch;
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>t;
		pq.push({t,i});
	}
	len=N; for(int i=0;i<len;i++) branch.pb({});
	root.resize(len);
	while(!pq.empty()){
		int d=pq.top().first, i=pq.top().second; pq.pop();
		if(cur+d>=len){
			len++;
			root.pb(2*i-1);branch.pb({});
		}
		else{
			branch[cur+d-1].pb(2*i-1);
		}
		root[cur++]=2*i;
	}
	for(int i=0;i<len;i++){
		for(auto j:branch[i]) cout<<root[i]<<" "<<j<<"\n";
		if(i)cout<<root[i-1]<<" "<<root[i]<<"\n";
	}
}