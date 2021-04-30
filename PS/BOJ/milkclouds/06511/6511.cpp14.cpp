#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,c;
ll o(ll a,ll b){return a/b+(a%b>0);}
int main(){
	while(~scanf("%d %d %d",&n,&m,&c) && n){
		if(c)cout<<(n-7)*((m-7)/2)+((m-7)&1?o(n-7,2):0)<<"\n";
		else cout<<(n-7)*((m-7)/2)+((m-7)&1?(n-7)/2:0)<<"\n";
	}
}