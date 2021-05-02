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
const ll dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, MAX = 1e9, MAXN = 2e5 + 5;
// from 8:25

ll N, Bx, By, x, y;
char dir;
vector<ti> A;
map<ll, vector<pair<ll, char> > > objx, objy;

pair<pi, char> getnext(ll x,ll y,ll dir){
	ll vmove = dir % 2 == 0;
	ll db = vmove ? dy[dir] : dx[dir];
	ll a = vmove ? x : y;
	ll b = vmove ? y : x;
	auto& objs = (vmove ? objx : objy)[a];
	ll pos = (ll)(lower_bound(objs.begin(), objs.end(), make_pair(b, (char)0)) - objs.begin()) + db;
	char ch = '?';
	if(pos == objs.size()) b = MAX + 1;
	else if(pos < 0) b = -(MAX + 1);
	else b = objs[pos].x, ch = objs[pos].y;
	return {vmove ? make_pair(a, b) : make_pair(b, a), ch};
}

vector<pi> getpath(ll x,ll y,ll dir){
	pi pos(x, y);
	vector<pi> path(1, pos);
	for(;;){
		pair<pi, char> res = getnext(pos.first, pos.second, dir);
		pos = res.x;
		path.pb(pos);
		if(res.y != '/' && res.y != '\\')break;
		dir = ((res.y != '/') ^ (dir % 2)) ? (dir + 3) % 4 : (dir + 1) % 4;
	}
	return path;
}
pi pisort(ll x,ll y){
	return x < y ? make_pair(x, y): make_pair(y, x);
}
vector<pair<ll, pi> > gethorz(vector<pi>& path){
	vector<pair<ll, pi> > ret;
	for(int i = 0; i + 1 < path.size(); i++){
		if(path[i].y == path[i + 1].y) ret.pb({path[i].y, pisort(path[i].x, path[i + 1].x)});
	}
	return ret;
}
vector<pair<ll, pi> > getvert(vector<pi>& path){
	vector<pair<ll, pi> > ret;
	for(int i = 0; i + 1 < path.size(); i++){
		if(path[i].x == path[i + 1].x) ret.pb({path[i].x, pisort(path[i].y, path[i + 1].y)});
	}
	return ret;
}

ll tree[MAXN];
void bit_add(ll x,ll v){
	for(;x < MAXN; x += x & -x) tree[x] += v;
}
ll bit_get(ll x){
	ll ans = 0;
	for(; x; x &= x - 1) ans += tree[x];
	return ans;
}
void printplpi(vector<pair<ll, pi> > aa){
	for(auto i: aa) cout << i.x << " - " << i.y.x << " " << i.y.y << endl;
}
ll count(vector<pair<ll, pi> > horz, vector<pair<ll, pi> > vert){
	vector<ll> ys;
	for(auto i: horz) ys.pb(i.x);
	for(auto i: vert) ys.pb(i.y.x);
	for(auto i: vert) ys.pb(i.y.y);
	sort(ys.begin(), ys.end());
	ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
	for(auto& i : vert){
		i.y.x = lower_bound(ys.begin(), ys.end(), i.y.x) - ys.begin() + 2;
		i.y.y = lower_bound(ys.begin(), ys.end(), i.y.y) - ys.begin() + 2;
	}
	for(auto& i : horz) i.x = lower_bound(ys.begin(), ys.end(), i.x) - ys.begin() + 2;
	sort(vert.begin(), vert.end());
	vector<pair<pi, ll> > events;
	for(auto i: horz){
		events.pb({make_pair(i.y.x, i.x), 1});
		events.pb({make_pair(i.y.y, i.x), -1});
	}
	sort(events.begin(), events.end());
	ll result = 0, j = 0;
	for(auto i: events){
		ll x = i.x.x;
		for(; j < vert.size() && vert[j].x < x; j++) result += bit_get(vert[j].y.y) - bit_get(vert[j].y.x - 1);
		bit_add(i.x.y, i.y);
	}
	return result;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> Bx >> By;
	objx[0].pb({0, 'S'});
	objy[0].pb({0, 'S'});
	objx[Bx].pb({By, 'B'});
	objy[By].pb({Bx, 'B'});
	rep(i, 0, N) {
		cin >> x >> y >> dir;
		objx[x].pb({y, dir});
		objy[y].pb({x, dir});
	}
	for(auto it = objx.begin(); it != objx.end(); it++) sort(it->second.begin(), it->second.end());
	for(auto it = objy.begin(); it != objy.end(); it++) sort(it->second.begin(), it->second.end());
	ll result = 0;
	vector<pi> laser_S = getpath(0, 0, 0);
	rep(dir, 0, 4){
		vector<pi> laser_E = getpath(Bx, By, dir);
		ll res = count(gethorz(laser_S), getvert(laser_E)) + count(gethorz(laser_E), getvert(laser_S));
		if(laser_E[0] == laser_E.back()) result += res;
		else result += res * 2;
	}
	cout << result / 2;
}