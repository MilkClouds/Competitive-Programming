int sz[101010]; // 서브 트리의 크기
vector<int> g[101010]; // 인접 리스트
int getSize(int v, int b = -1){ // 서브 트리의 크기를 구하는 DFS
    sz[v] = 1;
    for(auto i : g[v]) if(i != b) sz[v] += getSize(i, v);
    return sz[v];
}
int getCent(int v, int b = -1, int cap = n){ // 센트로이드를 찾는 DFS
    for(auto i : g[v]) if(&& i != b && sz[i]*2 > cap) return getCent(i, v, cap);
    return v;
}


// https://justicehui.github.io/hard-algorithm/2020/08/25/centroid/
