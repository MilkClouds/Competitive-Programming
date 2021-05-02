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
const int dx[]={2,2,1,1,-1,-1,-2,-2};
const int dy[]={1,-1,2,-2,2,-2,1,-1};
map<pi,int> m;
ll Sa,Sb,La,Lb;
string xx;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b;
	rep(i,0,36){
		cin>>xx;
		a=xx[0]-'A'; b=xx[1]-'1';
		if(i==0) {Sa=a; Sb=b;}
		else {
			bool flag = 0;
			rep(k,0,8){
				if(La+dx[k]==a && Lb+dy[k]==b)flag=1;
			}
			if(!flag){cout <<"Invalid";return 0;}
		}
		if(m[{a,b}]) {cout <<"Invalid";return 0;}
		m[{a,b}] = 1;
		La=a; Lb=b;
	}
	rep(k,0,8){
		if(a+dx[k]==Sa && b+dy[k]==Sb){cout<<"Valid";return 0;}
	}
	cout <<"Invalid";
}