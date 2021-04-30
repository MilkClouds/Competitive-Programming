# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;

int L, C;
char S[16];
string ans;
bool valid(string s){
	int mo=0;
	for(auto i:s) if(i=='a' || i=='e' || i=='o' || i=='i' || i=='u') mo++;
	return mo && s.size()-mo>1;
}
void solution(int l,int cur){
	if(l == L){
		if(valid(ans))
		cout << ans << "\n";
		return;
	}
	rep(i, cur + 1, C){
		ans += S[i];
		solution(l + 1, i);
		ans.erase(--ans.end());
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> L >> C;
	rep(i, 0, C) cin >> S[i];
	sort(S, S + C);
	solution(0, -1);
}