#include <iostream>
using namespace std;

int a[102][102],b[102][102];
int main()
{
	cin.tie(0);
	int n,m,k;
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)
		cin>>a[i][j];
	cin>>m>>k;
	for(int i=0;i<m;i++)for(int j=0;j<k;j++)
		cin>>b[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int ret=0;
			for(int x=0;x<m;x++){
				ret+=a[i][x]*b[x][j];
				//cout<<a[i][x]<<b[x][j]<<endl;
			}
			cout<<ret<<' ';
		}
		puts("");
	}

	return 0;
}