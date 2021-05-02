#include <iostream>
using namespace std;

int n,m,preSum[1025][1025],t,a[1024][1024];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++){
		int tot=0;
		for(int j=1;j<=n;j++){
			tot+=a[i-1][j-1];
			preSum[i][j]=preSum[i-1][j]+tot;
		}
	}
	int a,b,c,d;
	while(m--){
		cin>>a>>b>>c>>d;
		cout<<preSum[c][d]-preSum[c][b-1]-preSum[a-1][d]+preSum[a-1][b-1]<<'\n';
	}
	return 0;
}