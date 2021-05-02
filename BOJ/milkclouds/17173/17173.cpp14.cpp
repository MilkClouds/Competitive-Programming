#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;
int N,M,K[1005],ans,chk[1005];
int main(){
	cin>>N>>M;
	rep(i,0,M){cin>>K[i];
		for(int j=K[i];j<=N;j+=K[i]){
			if(!chk[j]){chk[j]=1;ans+=j;}
		}
	}
	cout<<ans;
}