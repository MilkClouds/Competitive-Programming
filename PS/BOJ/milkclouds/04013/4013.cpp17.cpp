
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int N, M, S, P, dfsCnt = 0, sccCnt = 0;

vector<int> graph[500001], dfsNum(500001), sccNum(500001);  // scc
vector<bool> finish(500001);
stack<int> s;

vector<int> graph2[500001], inDegree(500001), atm(500001), cost(500001);  // 위상정렬
vector<bool> canArrive(500001), isOutback(500001);
queue<int> q;

int dfs(int curr)  // scc
{
	int result = dfsNum[curr] = ++dfsCnt;
	s.push(curr);

	for (auto& Next : graph[curr])
	{
		if (dfsNum[Next] == 0) result = min(result, dfs(Next));
		else if (!finish[Next]) result = min(result, dfsNum[Next]);
	}
	if (result == dfsNum[curr])
	{
		while (1)
		{
			int Top = s.top();
			s.pop();

			finish[Top] = true;
			sccNum[Top] = sccCnt + 1;

			if (curr == Top) break;
		}
		sccCnt++;
	}
	return result;
}

int TopologicalSort()  // 위상 정렬
{
	int result = 0;

	for (int i = 1; i <= sccCnt; i++) 
	{
		cost[i] = atm[i];
		if (i == sccNum[S]) canArrive[i] = true;
		if (inDegree[i] == 0) q.push(i);
	}

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (auto& Next : graph2[curr])
		{
			if (canArrive[curr])
			{
				cost[Next] = max(cost[Next], cost[curr] + atm[Next]);
				canArrive[Next] = true;
			}
			if (--inDegree[Next] == 0) q.push(Next);
		}
	}

	for (int i = 1; i <= sccCnt; i++)
		if(isOutback[i] && canArrive[i]) result = max(result, cost[i]);

	return result;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    
    
    
    
    
    
    
    
    
    
    
    
    
	cin >> N >> M;

	int a, b, temp;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= N; i++)
		if (dfsNum[i] == 0) dfs(i);

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		atm[sccNum[i]] += temp;
		for (auto& Next : graph[i])
		{
			if (sccNum[i] == sccNum[Next]) continue;
			graph2[sccNum[i]].push_back(sccNum[Next]);
			inDegree[sccNum[Next]]++;
		}
	}

	cin >> S >> P;
	for (int i = 0; i < P; i++)
	{
		cin >> temp;
		isOutback[sccNum[temp]] = true;
	}

	cout << TopologicalSort() << '\n';

	return 0;
}