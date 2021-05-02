#include<bits/stdc++.h>
using namespace std;

int n,t,cnt;
string s;

int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		t+=(s[i]=='(')-(s[i]==')');
		if(t<0)cnt++;
	}
	if(t){cout<<"No";return 0;}
	cout<<(cnt<2?"Yes":"No");
}