void _sort(vi& A, vi& B, int l, int r){
    if(r - l == 1) return;
    int m = l + r >> 1;
    _sort(B, A, l, m);
    _sort(B, A, m, r);
    for(int p = l, q = m, t = l; t < r; t++){
        A[t] = (!(p == m) && (q == r || B[p] < B[q]) ? B[p++] : B[q++]);
    }
}
void ssort(vi& v){
    vi B(all(v));
    _sort(v, B, 0, v.size());
}