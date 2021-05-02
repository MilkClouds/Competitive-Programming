#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
ll N,x,XOR;
int main(){
	cin>>N;
	rep(i,0,N){cin>>x;XOR^=x;}
	cout<<(XOR?"koosaga":"cubelover");
}