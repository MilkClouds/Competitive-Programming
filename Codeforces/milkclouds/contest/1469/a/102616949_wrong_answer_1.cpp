#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
 
using namespace std;
typedef long long ll;
 
int t, cnt, flag;
string S;
 
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> t;
	rep(_, 0, t){
		cin >> S;
		cnt = 0;
		flag= 0;
		for(char s : S){
			if(s == '?'){
				if(cnt == 0) cnt++;
				else cnt--;
				if(cnt < 0){ cout << "NO\n"; flag = 1; break;}
			}
			else if (s == '('){
				cnt++;
			}
			else {
				cnt--;
			}
		}
		if(flag == 0)cout << (cnt==0 ? "YES" : "NO") << "\n";
	}
}