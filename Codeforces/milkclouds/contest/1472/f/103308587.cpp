#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MAX = 2e5 + 3;
 
vector<pii> v;
ll TC, N, M, r[MAX], c[MAX], last, chk, flag, s, fin;
 
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){ v.clear();
		cin >> N >> M; N++;
		rep(i, 0, M) {cin >> r[i] >> c[i]; v.pb({c[i], r[i]});}		
		v.pb({N, 1}); v.pb({N, 2});
		sort(v.begin(), v.end());
		fin = s = flag = chk = last = 0;
		rep(i, 0, M + 2){
			//cout << v[i].first << " " <<v[i].second <<" "<<chk<<endl;
			if(flag) {flag = 0; continue;}
			if(i < M + 1 && v[i + 1].first == v[i].first) {flag = 1; if(chk){fin = 1;break;} continue;}
			//printf("%d %d %d %d %d\n", flag, chk, last, s, v[i].first - last);
			if(!chk) {chk = 1; last = v[i].first; s = v[i].second; continue;}
			if((v[i].first - last) % 2){
				if(s == v[i].second) chk = 0; 
				else{fin = 1; break;}
			}
			else {
				if(s != v[i].second) chk = 0;
				else {fin = 1; break;}
			}
			last = v[i].first; s = v[i].second;
		}
		if(fin) cout <<"NO\n";
		else cout << "YES\n";
	}
}