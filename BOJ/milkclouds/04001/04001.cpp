#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e6 + 1;
ll N, a, b, c, S[MAX], dp[MAX], x;
typedef pair<ll, ll> Line;
struct CHT{
	vector<Line> lines;
	vector<int> idx;
    CHT(): CHT(0){}
    CHT(int N): lines(N), idx(N) {}
	int top = 0;

	ll f(Line line, ll x){
		return line.x * x + line.y;
	}
	ld intersect(Line a, Line b){ // aware div-by-0
		return (ld) (b.y - a.y) / (a.x - b.x);
	}

	int nth(Line line){
		// 기울기가 전과 같아서 평행한 경우는 안 구현함. strictly increasing 가정
		int l = 0, r = top;
		while (l < r)
		{
			int m = l + r >> 1;
			if(intersect(line, lines[m - 1]) < intersect(lines[m - 1], lines[m])) r = m;
			else l = m + 1;
		}
		return l;
	}
	void insert(Line line, int i){
		top = nth(line);
		lines[top] = line;
		idx[top] = i;
		top++;
	}

	pl get(ll x){
		int l = 0, r = top;
		while(l + 1 < r){
			int m = l + r >> 1;
			if(intersect(lines[m], lines[m - 1]) < x) l = m;
			else r = m;
		}
		return {f(lines[l], x), idx[l]};
	}
} cht;
/*
dp[i] = max(dp[j] + f(S[i] - S[j])) = max(dp[j] + a(S[i] - S[j])^2 + b(S[i] - S[j]) + c)
dp[i] = max(dp[j] + S[j] * (-2aS[i]-b) + aS[j]^2) + aS[i]^2+bS[i]+c
*/
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> a >> b >> c;
    cht = CHT(N + 1);
    cht.insert({0, 0}, 0);
    rep(i, 1, N + 1){
        cin >> x;
        S[i] = S[i - 1] + x;
        dp[i] = cht.get(S[i]).x + a * S[i] * S[i] + b * S[i] + c;
        cht.insert({-2 * a * S[i], -b * S[i] + a * S[i] * S[i] + dp[i]}, i);
    }
    cout << dp[N] << endl;
}
