#include <bits/stdc++.h>
#define rep(a,b,c) for(int a = b; a < c; a++)
#define rep2(a,b,c) for(int a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;


const int MAX = 1e4;
int N, M, SS, TT, u, v;
vector<int> adj[MAX], adj2[MAX];

int dfsn[MAX], sn[MAX], SN, cnt;
bool finished[MAX]; // SCC 분리가 끝난 정점만 true
stack<int> S;
vector<vector<int>> SCC;

// 자신의 결과값을 리턴하는 DFS 함수
int DFS(int curr) {
    dfsn[curr] = ++cnt; // dfsn 결정
    S.push(curr); // 스택에 자신을 push

    // 자신의 dfsn, 자식들의 결과나 dfsn 중 가장 작은 번호를 result에 저장
    int result = dfsn[curr];
    for (int next : adj[curr]) {
        // 아직 방문하지 않은 이웃
        if (dfsn[next] == 0) result = min(result, DFS(next));
        // 방문은 했으나 아직 SCC로 추출되지는 않은 이웃
        else if (!finished[next]) result = min(result, dfsn[next]);
    }

    // 자신, 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
    if (result == dfsn[curr]) {
        vector<int> currSCC;
        // 스택에서 자신이 나올 때까지 pop
        while (1) {
            int t = S.top();
            S.pop();
            currSCC.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if (t == curr) break;
        }
        // 출력을 위해 원소 정렬
        sort(currSCC.begin(), currSCC.end());
        // SCC 추출
        SCC.push_back(currSCC);
        SN++;
    }
    return result;
}

void DFS2(int u) {
    dfsn[u] = ++cnt;
    for (int v : adj[u]) {
        if (dfsn[v] == 0) DFS2(v);
        if (sn[u] != sn[v]) adj2[sn[u]].pb(sn[v]);
    }
}

inline int sz(int u) { return SCC[u].size(); }

int dijkstra() {
    priority_queue<pi> pq;
    vector<int> dist(N, 0), vis(N, 0);
    dist[SS] = sz(SS);
    pq.push({ dist[SS], SS });
    while (!pq.empty()) {
        do {
            u = pq.top().y;
            pq.pop();
        } while (!pq.empty() && vis[u]);
        if (vis[u])break;
        vis[u] = 1;
        for (auto v : adj2[u]) {
            int nd = dist[u] + sz(v);
            if (dist[v] < nd) {
                dist[v] = nd;
                pq.push({ nd, v });
            }
        }
    }
    return dist[TT];
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> SS >> TT; SS--; TT--;
	rep(i, 0, M) {
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
	}
    rep(i, 0, N) if (dfsn[i] == 0) DFS(i);
    fill(dfsn, dfsn + N, 0); cnt = 0;
    rep(i, 0, N) if (dfsn[i] == 0) DFS2(i);
    SS = sn[SS]; TT = sn[TT];
    cout << dijkstra();
}
