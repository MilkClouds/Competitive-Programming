#include <iostream>
using namespace std;

int d[501][501];
int main(){
	cin.tie(0);
	int n,t,ret=0;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cin>>t;
			d[i][j]=max(d[i-1][j-1],d[i-1][j])+t;
			if(i==n) ret=max(ret,d[i][j]);
		}
	}
	cout<<ret;
}