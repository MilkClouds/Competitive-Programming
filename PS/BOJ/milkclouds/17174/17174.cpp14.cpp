#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,M,ans;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	while(N){
		ans+=N;
		N/=M;
	}
	cout<<ans;
}