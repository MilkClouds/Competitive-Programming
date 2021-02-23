vector<int>& dijkstra(int S) {
    priority_queue<pi> pq;
    vector<int> dist(N, 0);
    dist[S] = 0;
    pq.push({ 0, S });
    while (!pq.empty()) {
        int d, u;
        tie(d, u) = pq.top(); pq.pop();
        if(-d != dist[u]) continue;
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