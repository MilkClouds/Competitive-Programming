#include <iostream>
using namespace std;
int n,s[100001],m,a,b;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]+=s[i-1];
	}
	cin>>m;
	while(m--){
		cin>>a>>b;
		cout<<s[b]-s[a-1]<<'\n';
	}
}