#include <iostream>
using namespace std;

int n,m,t,ret;
int pref[30][30];

int main(){
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>pref[i][j];
	for(int i=0;i<m;i++){
		for(int j=1+i;j<m;j++){
			for(int k=1+j;k<m;k++){
				int sum=0;
				for(int a=0;a<n;a++)
					sum+=max(pref[a][i],max(pref[a][j],pref[a][k]));
				ret=max(ret,sum);
			}
		}
	}
	cout<<ret;
	return 0;
}