#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll T,TC,C,D,V,a,N,ans;

int main(){
	cin>>T;
	for(int TC=1;TC<=T;TC++){
		cin>>C>>D>>V;
		queue<int> Q;
		for(int i=0;i<D;i++){
			cin>>a;
			Q.push(a);
		}
		N=0;ans=0;
		while(N<V){
			ll X=N+1;
			if(!Q.empty() && Q.front()<=X)X=Q.front(),Q.pop();else ans++;
			N+=X*C;
		}
		printf("Case #%d: %d\n",TC,ans);
	}
}