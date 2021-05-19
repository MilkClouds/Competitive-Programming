#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const ll inf = (1ll<<60);

ll op(ll a,ll b){
    return min(a,b);
}

ll e(){
    return inf;
}

int main(){
    int N; cin >> N;
    vector<int> P(N),A(N),B(N),C(N),pos(N+1);
    for(int i=0; i<N; i++){
        cin >> P[i];
        pos[P[i]] = i+1;
    }
    for(int i=0; i<N; i++) cin >> A[i] >> B[i] >> C[i];
    vector<ll> dp(N+1,inf),Asum(N+1),Bsum(N+1),Csum(N+1);
    segtree<ll,op,e> seg(N+1);
    ll ans = inf;
    for(int i=0; i<N; i++){
        Asum[i+1] = Asum[i]+A[i];
        Bsum[i+1] = Bsum[i]+min(B[i],A[i]);
        Csum[i+1] = Csum[i]+min(C[i],A[i]);
    }
    for(int i=1; i<=N; i++){
        dp[i] = min(Bsum[i-1],seg.prod(0,pos[i])+Asum[i-1]);
        ans = min(ans, dp[i]+Csum[N]-Csum[i]);
        seg.set(pos[i],dp[i]-Asum[i]);
    }
    cout << ans << endl;
}
