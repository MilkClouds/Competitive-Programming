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
const int MAX = 1e3 + 1;
const ll INF = 1e9;

ll N, x, y;
struct ABC{ll x, y;};
vector<ABC> v;
unordered_map<ll,double> last, current;
double ans;

ll square(ll x){return x*x;}
double dist(ll x,ll y,ll a,ll b){return sqrt(square(y-b)+square(a-x));}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N) {
		cin >> x >> y;
		v.pb({x, y});
	}
	sort(v.begin(), v.end(), [](ABC& a, ABC& b){return a.x < b.x;});
	ll last_x = v[0].x, cur_x = v[0].x;
	rep(i, 0, N){
		if(v[i].x == v[0].x){
			current[v[i].y] = 0;
			continue;
		}
		if(v[i].x != cur_x){
			last_x = cur_x;
			cur_x = v[i].x;
			last = current;
			current.clear();
		}
		double temp = 0;
		for(auto pos = last.begin(); pos != last.end(); pos++){
			ll y = pos->first; double last_dist = pos->second;
			temp = max(temp, last_dist + dist(last_x, y, cur_x, v[i].y));
		}
		current[v[i].y] = temp;
		ans = max(ans, temp);
	}
	cout.precision(8);
	cout << ans << endl;
}
	
