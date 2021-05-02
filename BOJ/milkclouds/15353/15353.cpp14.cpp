#include <iostream>
#include <algorithm>
using namespace std;
string a,b,ret="";
string stmul(int n){
	string ret="";
	while(n-->0)
		ret+="0";
	return ret;
}
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>a>>b;
	int temp=a.size()-b.size();
	a=stmul(-temp)+a;
	b=stmul(temp)+b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int olim=0;
	for (int i = 0; a[i]; i++) {
	    temp=a[i]+b[i]+olim-'0'*2;
	    olim=temp/10;
	    ret=to_string(temp%10)+ret;
	}
	if(olim)
	    cout<<olim;
	cout<<ret;
}