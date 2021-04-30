#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
ll N,ans,bonus;
string S;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>S;
	rep(i,0,N){
		if(S[i]=='X'){
			bonus=0;
		}
		else{
			ans+=i+1+bonus;
			bonus++;
		}
	}
	cout<<ans;
}
