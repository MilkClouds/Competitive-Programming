#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(int a=b;a>c;a--)
using namespace std;
using ll=long long;
const int MAX=3e5+5;
ll N,M,a,b,c;
string S="#o+-.";
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	rep(i,0,N){
		rep(i,0,M){
			cin>>a>>b>>c;
			ll t=(2126*a+7152*b+722*c)/510000;
			cout<<S[min((ll)4,t)];
		}
		cout<<"\n";
	}
}
