#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)

using namespace std;
typedef long long ll;

int t, cnt;
string S;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> t;
	rep(_, 0, t){
		cin >> S;
		cnt = 0;
		for(char s : S){
			if(s == '?'){
				if(cnt == 0) cnt++;
				else cnt--;
			}
			else if (s == '('){
				cnt++;
			}
			else {
				cnt--;
			}
			if(cnt < 0) {cout << "NO\n"; break;}
		}
		if(cnt >= 0) cout << (cnt==0 ? "YES" : "NO") << "\n";
	}
}