#include <bits/stdc++.h>
using namespace std;

long long a,b,t,r;
priority_queue<pair<long long,long long> > Q;
unordered_map<long long,bool> m;

int main(){
	cin>>a>>b;
	if(a>b){
		cout<<-1;
		return 0;
	}
	Q.push({-a,1});
	while(!Q.empty()){
		t=-Q.top().first;r=Q.top().second;Q.pop();
		m[t]=1;
		if(t==b){cout<<r;return 0;}
		if(t>b){cout<<-1;return 0;}
		if(!m[t<<1])Q.push({-(t<<1),r+1});if(!m[t*10+1])Q.push({-(t*10+1),r+1});
	}
}