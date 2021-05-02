#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(int a=b;a>c;a--)
using namespace std;
using ll=long long;
const int MAX=3e5+5;
ll n,v[MAX];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	rep(i,0,n)cin>>v[i];
	rep2(i,n-1,-1){
		if(v[i] < v[i+1]){
			v[i]*=v[i+1]/v[i]+(v[i+1]%v[i]>0);
		}
	}
	cout<<v[0];
}
