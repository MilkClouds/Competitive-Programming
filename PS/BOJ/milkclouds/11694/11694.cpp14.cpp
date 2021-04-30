#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
ll N,x,XOR,cnt;
int main(){
	cin>>N;
	rep(i,0,N){cin>>x;XOR^=x;if(x>1)cnt++;}
	cout<<((cnt>0)^(XOR^1)?"koosaga":"cubelover");
}