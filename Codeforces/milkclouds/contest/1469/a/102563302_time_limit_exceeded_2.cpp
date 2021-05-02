#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)

using namespace std;
typedef long long ll;

int t, cnt;
string S;


bool solve(string S, int i, int cnt){
	if(cnt < 0)return 0;
	if(i == S.length()) return (cnt == 0);
	if(S[i]=='?') return solve(S, i+1, cnt-1) or solve(S, i+1, cnt+1);
	else if (S[i] == '(') return solve(S, i + 1, cnt + 1);
	return solve(S, i + 1, cnt - 1);
}

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> t;
	rep(_, 0, t){
		cin >> S;
		cout << (solve(S, 0, 0) ? "YES" : "NO") << "\n";
	}
}