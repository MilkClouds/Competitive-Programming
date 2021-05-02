#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
 
using namespace std;
typedef long long ll;
 
int t, chk, flag;
string S;
 
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> t;
	rep(_, 0, t){
		cin >> S;
		chk = 0;
		if(S.length() & 1) {cout << "NO\n"; continue;}
		for(char s : S) if(chk == 0 && s != '?') chk = (s == '(' ? 1:2);
		if(chk == 1) {cout<<"YES\n"; continue;}
		int cnt = 0;
		for(char s : S) {
			if(s == ')')break;
			cnt++;
		}
		if(cnt &1) cout<<"YES\n";
		else cout <<"NO\n";
	}
}