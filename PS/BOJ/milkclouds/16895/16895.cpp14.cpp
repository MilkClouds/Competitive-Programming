#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
ll N,P[1005],XOR,cnt,largest;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	rep(i,0,N){cin>>P[i];XOR^=P[i];}
	if(XOR==0){cout<<0;return 0;}
	rep(i,0,33)	{
		if(XOR & (1<<32-i)){largest=32-i;break;}
	}
	rep(i,0,N)if((1<<largest)&P[i])cnt++;
	cout<<cnt;
}