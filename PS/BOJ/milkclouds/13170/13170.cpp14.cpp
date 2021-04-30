#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll N,K,P,W;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>K>>P>>W;
	cout<<P/W+(P%W>0);
}