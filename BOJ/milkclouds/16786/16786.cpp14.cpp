#include <iostream>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

int N,X[105],M,t;
int main(){
	cin>>N;
	rep(i,1,N+1){
		cin>>X[i];
	}
	cin>>M;
	while(M--){
		cin>>t;
		if( X[t+1] == X[t] + 1) continue;
		if( X[t] == 2019) continue;
		X[t]++;
	}
	rep(i,1,N+1)cout<<X[i]<<endl;
}