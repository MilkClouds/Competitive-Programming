#include <bits/stdc++.h>
using namespace std;

int N;
int a[9],visit[9];
void dfs(int c){
	if(c==N){for(int i=0;i<N;i++)cout<<a[i]<<" ";cout<<"\n";return;}
	for(int i=1;i<=N;i++){
		if(visit[i])continue;
		visit[i]=1;
		a[c]=i;
		dfs(c+1);
		visit[i]=0;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>N;
	dfs(0);
}