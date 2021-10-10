vector<ll> dijkstra(int S) {
    priority_queue<pl> pq;
    vector<ll> dist(N, INF);
    dist[S] = 0;
    pq.push({ 0, S });
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop(); d *= -1;
        if(d != dist[u]) continue;
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