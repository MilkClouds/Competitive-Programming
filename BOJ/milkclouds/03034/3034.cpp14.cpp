#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;

int N,W,H,T;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>W>>H;
	rep(i,0,N){
		cin>>T;
		cout<<( W*W+H*H>=T*T ? "DA":"NE")<<"\n";
	}
}