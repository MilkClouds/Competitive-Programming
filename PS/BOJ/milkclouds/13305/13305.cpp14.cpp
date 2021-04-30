#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+1;
int N,dist[MAX],cost[MAX],m;
long long ans;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=1;i<N;i++)cin>>dist[i];
	for(int i=0;i<N;i++)cin>>cost[i];
	m=1e9;
	for(int i=0;i<N;i++){
		if(i)ans+=(long long)m*dist[i];
		m=min(m,cost[i]);
	}
	cout<<ans;
}