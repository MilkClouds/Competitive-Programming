#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
const int MAX = 2e3 + 5;

int N, a[MAX], vis[MAX], flag;
pi P[MAX];
string ans[MAX];
vector<pi> adj[MAX];

void make_edge(int u, int v, int f) {
	adj[u].pb({ v, f });
	adj[v].pb({ u, f });
}

void dfs(int u, int f) {
	if (vis[u]) {
		if (vis[u] ^ f) flag = 1;
		return;
	}
	vis[u] = f;
	for (auto p : adj[u]) {
		dfs(p.x, p.y * f);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) P[i + 1].x = -1;
	rep(i, 0, N * 2) {
		cin >> a[i];
		if (~P[a[i]].x) P[a[i]].y = i;
		else P[a[i]].x = i;
	}
	// a[i] : 입력 두번째줄 저장한 배열
	// P[i]: 숫자가 i인 패드 2개의 위치(pair)
	rep(i, 1, N + 1) rep(j, i + 1, N + 1) {
		if (P[i].y < P[j].x || P[j].y < P[i].x) continue;
		if (P[i].x < P[j].x && P[j].y < P[i].y) {
			make_edge(P[j].x, P[j].y, 1);
			continue;
		}
		// a bb a형태일 때, bb는 같은 방향
		swap(i, j);
		if (P[i].x < P[j].x && P[j].y < P[i].y) {
			make_edge(P[j].x, P[j].y, 1);
			swap(i, j);
			continue;
		}
		// b aa b형태일 때, aa같은 방향
		swap(i, j);
		// 원래 i,j로 스왑
		if (P[i].x < P[j].x) { make_edge(P[j].x, P[i].y, -1); continue; }
		// a b a b형태일 때, ba 다른방향
		swap(i, j);
		make_edge(P[j].x, P[i].y, -1);
		swap(i, j);
	}
	rep(i, 0, N * 2) if (!vis[i]) dfs(i, 1);
	// 방향 설정한 거 모순있나 dfs로 체크. vis[i]에는 +1 또는 -1 방향이 저장됨
	if (flag) { cout << "NO\n"; return 0; }
	cout << "YES\n";
	rep(k, 0, N * 2) {
		int i = a[k];
		if (P[i].y != k) continue;
		// i : 패드에 써있는 숫자
		// k : 오른쪽 패드 위치
		string s = ~vis[P[i].x] ? " U " : " D "; //왼쪽 패드 방향이 1이면 U, -1이면 D
		string s2 = ~vis[P[i].x] ? " D " : " U "; // 위랑 정확히 반대 되도록 만듬
		int l = P[i].y + 1; // 오른쪽 패드 위치 + 1
		if (vis[P[i].x] ^ vis[P[i].y]) { // 왼쪽패드 오른쪽패드 방향이 반대일 때
			ans[i] = to_string(5) + s + to_string(l) + " L " + to_string(2*l + P[i].x - P[i].y) + s2 + to_string(l * 2) + " R " + to_string(l * 2) +  s + to_string(l) + "\n";
			// 5 U 길이, L 길이*2,  D 길이*2,  R (적당한 길이) , U 길이
			//여기서 길이란 (오른쪽패드위치+1)을 말함!
		}
		else {
			ans[i] = to_string(3) + s + to_string(l) + " R " + to_string(P[i].y - P[i].x) + s2 + to_string(l) + "\n";
			// 3 U 길이, R 적당한 길이, D 길이
		}
	}
	rep(i, 0, N) cout << ans[i + 1];
	//저장한 string들 차례대로 출력. 패드 번호순
}