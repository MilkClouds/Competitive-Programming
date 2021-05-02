#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > p;
int best = 1234567891, cnt, j;
inline int pow(int a) { return a * a; }
inline int dist(pair<int, int>& a, pair<int, int>& b) {
	return pow(a.first - b.first) + pow(a.second - b.second);
}
void solve(vector<pair<int, int> >::iterator it, int n) {
	if (n == 2) { best = min(best, dist(it[0], it[1])); return; }
	if (n == 3) { best = min({ dist(it[0],it[1]),dist(it[1],it[2]),dist(it[2],it[0]),best }); return; }
	int line = (it[n / 2].first + it[n / 2 - 1].first) / 2;
	solve(it, n / 2);
	solve(it + n / 2, n / 2);
	vector<pair<int, int> > mid;
	for (int i = 0; i < n; i++) {
		int t = line - it[i].first;
		if (t * t < best) mid.push_back(it[i]);
	}
	sort(mid.begin(), mid.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
		});
	int sz = mid.size();
	for (int i = 0; i < sz - 1; i++)
		for (int j = i + 1; j < sz && mid[j].second - mid[i].second < best; j++)
			best = min(best, dist(mid[i], mid[j]));
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		p.push_back({ a,b });
	}
	sort(p.begin(), p.end());
	solve(p.begin(), n);
	cout << best << '\n';
	return 0;
}