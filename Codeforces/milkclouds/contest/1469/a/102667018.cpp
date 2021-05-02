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
		if(S[0]==')' || S[S.size() - 1] == '(') cout << "NO\n";
		else cout << "YES\n";
	}
}