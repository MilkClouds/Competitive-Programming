#include <bits/stdc++.h>
using namespace std;
int N,T,a[32][32],r[32],c[32],same,flag;
int main(){
	cin>>N>>T;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>a[i][j];
	while(1){
		flag=0;
		for(int i=0;i<N;i++){
			if(r[i]==0){
				same=0;
				for(int j=0;j<N;j++)same+=a[i][j]==T;
				if(same>N/2){flag=1;for(int j=0;j<N;j++)a[i][j]=T;r[i]=1;}
			}
		}
		for(int i=0;i<N;i++){
			if(c[i]==0){
				same=0;
				for(int j=0;j<N;j++)same+=a[j][i]==T;
				if(same>N/2){flag=1;for(int j=0;j<N;j++)a[j][i]=T;c[i]=1;}
			}
		}
		if(flag==0)break;
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(a[i][j]!=T){cout<<0;return 0;}
	cout<<1;
}