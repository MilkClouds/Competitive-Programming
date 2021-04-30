#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;

ll a,k;
int main(){
	cin>>a>>k;
	if(k==0)cout<<a;
	else{
		if(a&1) cout<<a;
		else cout<<1;
	}
}