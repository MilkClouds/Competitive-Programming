#include <bits/stdc++.h>
using namespace std;
int N,depth=1;
string s,ans="(";
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>N>>s;
	if(s[0]==')'||N==1||s[N-1]=='('){cout<<":(";return 0;}
	for(int i=1;i<s.size()-1;i++){
	    if(depth==0){cout<<":(";return 0;}
	    if(s[i]=='('){
	        depth++;
	        ans+='(';
	    }
	    else if(s[i]==')'){
	        depth--;
	        ans+=')';
	    }
	    else{
	        if(depth>1)ans+=')',depth--;
	        else ans+='(',depth++;
	    }
	}
	if(depth!=1){cout<<":(";return 0;}
	cout<<ans<<")";
}