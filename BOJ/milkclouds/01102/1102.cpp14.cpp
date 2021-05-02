#include <bits/stdc++.h>
using namespace std;
const int INF=1e5;
const int MAX=17;
int N,dist[MAX][MAX],P,dp[1<<MAX];
string status;
inline int mincost(int bit,int dst){
	int ret=INF;
	for(int i=0;i<N;i++){
		if(!(bit&(1<<i)))continue;
		ret=min(ret,dist[i][dst]);
	}
	return ret;
}
int f(int bit,int cur){
	if(~dp[bit])return dp[bit];
	if(P<=cur)return 0;
	int ret=INF;
	for(int i=0;i<N;i++){
		if(bit&(1<<i))continue;
		int tmp=mincost(bit,i);
		if(tmp<INF)
			ret=min(ret,f(bit|(1<<i),cur+1)+tmp);
	}
	return dp[bit]=ret;
}
int main(){
	cin>>N;
	fill(dp,dp+(1<<N),-1);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>dist[i][j];
		}
	}
	cin>>status>>P;
	int bit=0,cur=0;
	for(int i=0;i<N;i++)if(status[i]=='Y')bit|=1<<i,cur++;
	int tmp=f(bit,cur);
	cout<<(tmp>=INF?-1:tmp);
}