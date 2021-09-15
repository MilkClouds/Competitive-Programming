vector<int> dijkstra(int S) {
    priority_queue<pi> pq;
    vector<int> dist(N, INF);
    dist[S] = 0;
    pq.push({ 0, S });
    while (!pq.empty()) {
        int d, u;
        tie(d, u) = pq.top(); pq.pop();
        if(-d != dist[u]) continue;
        for (auto [v, d] : adj[u]) {
            int nd = dist[u] + d;
            if (dist[v] > nd) {
                dist[v] = nd;
                pq.push({ -nd, v });
            }
        }
    }
    return dist;
}