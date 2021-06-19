const int MAX = 1e5, INF = 1e9;
vector<int> dist;
vector<int> adj[MAX];
vector<int> solve(int S){
    dist.assign(MAX, INF);
    dist[S] = 0;
    deque<int> Q; Q.push_back(S);
    while(!Q.empty()){
        auto u = Q.front(); Q.pop_front();
        for(auto tmp: adj[u]){
            auto v = tmp.x; auto d = tmp.y;
            if(dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                if(d == 1) Q.push_back(v);
                else Q.push_front(v);
            }
        }
    }
    return dist;
}