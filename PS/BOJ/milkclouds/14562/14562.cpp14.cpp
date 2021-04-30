#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int s, t, c;

int dist[201][201];
bool check[201][201];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> c;
	while (c--) {
		memset(dist, 0, sizeof(dist));
		memset(check, 0, sizeof(check));
		queue<pair<int, int>> q;
		cin >> s >> t;
		check[s][t] = true;
		q.push({ s, t });
		while (!q.empty()) {
			int u = q.front().first;
			int v = q.front().second;
			q.pop();
			if (u == v) {
				cout << dist[u][v] << '\n';
				break;
			}
			if (u + 1 <= v) {
				check[u + 1][v] = true;
				dist[u + 1][v] = dist[u][v] + 1;
				q.push({ u + 1, v });
			}
			if (u * 2 <= v + 3 ) {
				check[u * 2][v + 3] = true;
				dist[u * 2][v + 3] = dist[u][v] + 1;
				q.push({ u * 2, v + 3 });
			}
		}
	}
}


