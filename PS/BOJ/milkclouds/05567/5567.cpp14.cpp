#include <iostream>
#include <queue>
using namespace std;

bool adj[501][501];
bool ans[501];
int N,M,a,b,r;

int main()
{
	cin>>N>>M;
	while(M--){
		cin>>a>>b;
		adj[a][b]=1;
		adj[b][a]=1;
	}
	for(int i=2;i<=N;i++){
		if(adj[1][i]){
			ans[i]=1;
			for(int j=2;j<=N;j++)if(adj[i][j])ans[j]=1;
		}
	}
	for(int i=1;i<=N;i++)r+=ans[i];
	cout<<r;
}