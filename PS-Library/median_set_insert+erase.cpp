#include <bits/stdc++.h>
using namespace std;

multiset<int> S,T; // Always S.size()==T.size() or S.size()==T.size()+1
void eval(){
    if(S.size()){
        auto itr = S.end(); itr--;
        T.insert(*itr); S.erase(itr);
    }
    while(S.size() < T.size()){
        S.insert(*T.begin()); T.erase(T.begin());
    }
}
int val(){
    auto itr = S.end(); itr--;
    if(S.size()==T.size()+1)return *itr;
    return (*itr+*T.begin())/2;
}
void erase(int x){
    auto itr = S.end(); itr--;
    if(*itr < x) T.erase(T.lower_bound(x));
    else S.erase(S.lower_bound(x));
}
// S.insert(~~); eval();
// val() -> median;
// erase(A[i]); eval();

int main(){
    int n; cin >> n;
    vector<int> A(n); for(int i = 0; i < n; i++) cin >> A[i];
    vector<int> dp(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b); g[b].push_back(a);
    }
    function<void(int,int,int)> dfs=[&](int i,int p,int d){
        S.insert(A[i]); eval();
        int mi = 1000000005, ma = 0;
        for(int x : g[i]) if(x != p) {
            dfs(x, i, d+1);
            mi = min(mi,dp[x]); ma = max(ma,dp[x]);
        }
        if(ma == 0) dp[i] = val();
        else if(d&1) dp[i] = mi;
        else dp[i] = ma;
        erase(A[i]); eval();
    }; dfs(0,-1,0);
    cout << dp[0] << endl;
}
