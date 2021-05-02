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

int N, R[501], C[501];
struct ABC{
	int n,x,y;
};
vector<ABC> tanks;
vector<pair<int, string> > ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N) {
		cin >> R[i] >> C[i]; R[i]--; C[i]--;
		tanks.pb({i + 1, R[i], C[i]});
	}
	sort(tanks.begin(), tanks.end(), [](ABC& a, ABC& b){
		return a.x < b.x;
	});
	
	vector<pair<int, string> > temp;
	rep(i, 0, N){
		if(i > tanks[i].x){
			rep(_, 0, i - tanks[i].x) temp.pb({tanks[i].n, "D"});
			tanks[i].x = i;
		}
	}
	for(int i = temp.size() - 1; ~i; i--) ans.pb({temp[i].x, temp[i].y});
	
	rep(i, 0, N){
		if (i < tanks[i].x){
			rep(_, 0, tanks[i].x - i) ans.pb({tanks[i].n, "U"});
			tanks[i].x = i;
		}
	}

	temp.clear();
	sort(tanks.begin(), tanks.end(), [](ABC& a, ABC& b){
		return a.y < b.y;
	});

	rep(i, 0, N){
		if(i > tanks[i].y){
			rep(_, 0, i - tanks[i].y) temp.pb({tanks[i].n, "R"});
			tanks[i].y = i;
		}
	}
	for(int i = temp.size() - 1; ~i; i--) ans.pb({temp[i].x, temp[i].y});
	
	rep(i, 0, N){
		if (i < tanks[i].y){
			rep(_, 0, tanks[i].y - i) ans.pb({tanks[i].n, "L"});
			tanks[i].y = i;
		}
	}

	cout << ans.size() << endl;
	for(int j = 0; j < ans.size(); j++){
		cout << ans[j].x << " " << ans[j].y << "\n";
	}
}
	
