struct tree{
    int t[MAX * 4];
    void init(int n){
        fill(t, t + n, INF);
    }
    void update(int pos, int val) {
        t[pos + n] = val;
        for (pos += n; pos > 1; pos >>= 1) {
            t[pos >> 1] = min(t[pos], t[pos ^ 1]);
        }
    }
    int query(int l, int r){
        int ans = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, t[l++]);
            if (r & 1) ans = min(ans, t[--r]);
        }
        return ans;
    }
} SegTree;
