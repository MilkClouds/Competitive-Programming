vector<int>& dijkstra(int S) {
    priority_queue<pi> pq;
    vector<int> dist(N, 0);
    vector<bool> vis(N, 0);
    dist[S] = 0;
    pq.push({ 0, S });
    while (!pq.empty()) {
        do {
            u = pq.top().y;
            pq.pop();
        } while (!pq.empty() && vis[u]);
        if (vis[u])break;
        vis[u] = 1;
        for (auto v : adj[u]) {
            int nd = dist[u] + sz(v);
            if (dist[v] < nd) {
                dist[v] = nd;
                pq.push({ nd, v });
            }
        }
    }
    return dist;
}