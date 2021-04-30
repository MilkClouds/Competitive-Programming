#include <bits/stdc++.h>
using namespace std;

int D1,D2,ans,chk[2001];

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	cin>>D1>>D2;
	for(int i=D1;i<=D2;i++){
		vector<int> v;
		for(int j=1;j<i;j++){
			int g=gcd(i,j);
			int x=i/g;
			if(chk[x])continue;ans++;v.push_back(x);
		}
		for(auto x:v)chk[x]=1;
	}
	cout<<ans+1;
}