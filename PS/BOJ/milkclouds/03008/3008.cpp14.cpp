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

struct point {
	ll x,y,quadrant;
	point operator - (const point& o){
		return {x-o.x, y-o.y};
	}
	bool operator < (const point& o) const {
		return y*o.x - x*o.y < 0;
	}
	ll operator * (const point& o){
		return x*o.x + y*o.y;
	}
	bool operator ==(const point& o){
		return y*o.x == x*o.y;
	}
	void rotate(){
		quadrant = (quadrant + 1) % 4;
		swap(x,y); y=-y;
	}
} P[1501], Q[1501];

ll N, ans, cnt[4];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N)cin >> P[i].x >> P[i].y;
	rep(i, 0, N){
		int flag = 0;
		rep(j,0,N){
			if(i==j){ flag=1; continue;}
			Q[j-flag]=P[j]-P[i];
		}
		rep(j,0,N-1){
			while(!(Q[j].x>0 && Q[j].y>=0)) Q[j].rotate();
		}
		sort(Q, Q+N-1);
		for(int j = 0, k; j<N-1; j=k){
			fill(cnt,cnt+4,0);
			for(k=j; (k<N-1) && Q[j]==Q[k]; k++)cnt[Q[k].quadrant]++;
			ans += cnt[0]*cnt[1] + cnt[1]*cnt[2] + cnt[2]*cnt[3] + cnt[3]*cnt[0];
		}
	}
	cout << ans;
}