#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using llg = long long;

const int maxNod = (int)(1e5) + 5;
const int maxEdges = 3*(int)(1e5) + 5;
const int maxQueries = 3*(int)(1e5) + 5;

const int maxTokens = 2*maxQueries;

const llg BIG = (llg)(1e9) * (llg)(1e9);

int nbNod, nbEdges, nbCentrals, nbQueries;
llg rep[maxQueries];

// DSU

int dsuRepr[maxNod];
int dsuSize[maxNod];
vector<int> tokenIn[maxNod];

int baseTok[maxTokens];

void dsuInit()
{
	for (int nod = 0; nod < maxNod; ++nod) {
		dsuRepr[nod] = nod;
		dsuSize[nod] = 1;
	}
}

int dsuFind(int x)
{
	if (x != dsuRepr[x]) {
		dsuRepr[x] = dsuFind(dsuRepr[x]);
	}
	return dsuRepr[x];
}

void dsuMerge(int small, int big, llg curCap)
{
	small = dsuFind(small);
	big = dsuFind(big);
	if (small == big) return;
	if (dsuSize[small] > dsuSize[big]) swap(small, big);

	for (int token : tokenIn[small]) {
		int oth = token^1;
		int query = token/2;
		if (dsuFind(baseTok[oth]) == big) {
			rep[query] = curCap;
		}
		tokenIn[big].push_back(token);
	}

	tokenIn[small].clear();
	tokenIn[small].shrink_to_fit();

	dsuSize[big] += dsuSize[small];
	dsuRepr[small] = big;
}

// Dijkstra

vector<pair<int, llg>> adj[maxNod];
llg mdis[maxNod];

void dijkstra()
{
	priority_queue<pair<llg, int>> pq;
	for (int nod = 0; nod < nbNod; ++nod) {
		if (nod < nbCentrals) {
			pq.push({0, nod});
		} else {
			mdis[nod] = BIG;
		}
	}

	while (! pq.empty()) {
		llg dist = -pq.top().first;
		int nod = pq.top().second;
		pq.pop();
		if (dist != mdis[nod]) continue;

		for (auto rawNeigh : adj[nod]) {
			int neighbor = rawNeigh.first;
			llg newDis = dist + rawNeigh.second;
			if (newDis < mdis[neighbor]) {
				mdis[neighbor] = newDis;
				pq.push({-newDis, neighbor});
			}
		}
	}
}

// Main

struct Edge
{
	llg weight, n1, n2;
};

bool operator<(Edge a, Edge b)
{
	return a.weight < b.weight;
}

vector<Edge> tabEdges;
int t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	dsuInit();

	cin >> nbNod >> nbEdges >> nbCentrals >> nbQueries;
	for (int iEdge = 0; iEdge < nbEdges; ++iEdge) {
		int n1, n2; llg weight;
		cin >> n1 >> n2 >> weight;
		--n1; --n2;
		adj[n1].emplace_back(n2, weight);
		adj[n2].emplace_back(n1, weight);
		tabEdges.push_back({weight, n1, n2});
	}

	for (int query = 0; query < nbQueries; ++query) {
		int n1, n2;
		cin >> n1 >> n2;
		--n1; --n2;
		int tk1 = 2*query, tk2 = 2*query+1;

		baseTok[tk1] = n1;
		baseTok[tk2] = n2;

		tokenIn[n1].push_back(tk1);
		tokenIn[n2].push_back(tk2);
	}

	dijkstra();

	for (auto &edge : tabEdges) {
		edge.weight += mdis[edge.n1] + mdis[edge.n2];
	}

	sort(tabEdges.begin(), tabEdges.end());

	for (auto edge : tabEdges) {
		dsuMerge(edge.n1, edge.n2, edge.weight);
	}

	for (int query = 0; query < nbQueries; ++query) {
		cout << rep[query] << "\n";
	}
}