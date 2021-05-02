struct scc_graph {
    scc_graph() : scc_graph(0) {}
    scc_graph(int N) : dfsn(N), sn(N), N(N) {}

    int cnt, SN, N;
    vector<int> dfsn, sn;
    vector<vector<int>> SCC;
    stack<int> S;

    int scc(int u) {
        dfsn[u] = ++cnt;
        S.push(u);
        int result = dfsn[u];
        for (int v : adj[u]) {
            if (dfsn[v] == 0) result = min(result, scc(v));
            else if (!finished[v]) result = min(result, dfsn[v]);
        }
        if (result == dfsn[u]) {
            vector<int> currSCC;
            while (1) {
                int t = S.top();
                S.pop();
                currSCC.push_back(t);
                finished[t] = true;
                sn[t] = SN;
                if (t == u) break;
            }
            sort(currSCC.begin(), currSCC.end());
            SCC.push_back(currSCC);
            SN++;
        }
        return result;
    }
};