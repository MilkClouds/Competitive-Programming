#include <bits/stdc++.h>
using namespace std;
long long N,ans,pSum[100001],a;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a;
		pSum[i]=a+pSum[i-1];
	}
	for(int i=1;i<=N;i++){
		ans+=(pSum[N]-(pSum[i]-pSum[i-1]))*(pSum[i]-pSum[i-1]);
	}
	cout<<ans/2;
}