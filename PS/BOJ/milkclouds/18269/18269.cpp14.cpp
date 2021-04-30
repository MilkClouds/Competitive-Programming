# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;

ll N;
string S;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> S;
	rep(length, 1, N + 1){
		bool flag2 = 0;
		rep(i, 0, N - length + 1){
			rep(j, i + 1, N - length + 1){
				bool flag = 0;
				rep(k, 0, length) {
					if(S[i + k] != S[j + k]){
						flag = 1;
						break;
					}
				}
				if(flag == 0) {
					flag2 = 1;
					break;
				}
			}
			if(flag2) break;
		}
		if(!flag2){
			cout << length << endl;
			return 0;
		}
	}
}