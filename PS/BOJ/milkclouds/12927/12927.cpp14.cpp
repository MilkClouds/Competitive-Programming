#include <bits/stdc++.h>
using namespace std;
string S;
int ans;
int main(){
	cin>>S;
	for(int i=1;i<=S.size();i++){
		if(S[i-1]=='Y'){for(int j=i;j<=S.size();j+=i)S[j-1]=(S[j-1]=='Y'?'N':'Y');ans++;}
	}
	cout<<ans;
}