#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,T,a[100][100];
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>a[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) {cin>>T;cout<<a[i][j]+T<<" ";}
		cout<<'\n';
	}
}