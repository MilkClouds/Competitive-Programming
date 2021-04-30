#include <bits/stdc++.h>
using namespace std;
long long N,ret,divv,mod,step=1;
int main(){
	cin>>N;
	for(int i=1;i<=N;i+=step){
		divv=(N-1)/i;
		mod=(N-1)%i;
		step=divv?mod/divv+1:1;
		ret+=(divv+1)*step;
	}
	cout<<ret;
}