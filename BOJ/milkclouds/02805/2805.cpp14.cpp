#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, M = 0LL;
ll woods[1000001];
ll cut(ll h)
{
    ll acc = 0LL;
    for(ll i = 0LL; i < n; i++)
    {
        if(woods[i] <= h) continue;
        acc += woods[i] - h;
    }
    return acc;
}
ll solve(ll lo = 0LL, ll hi = M)
{
    if(lo >= hi) return lo;
    ll mid = (hi + lo + 1) / 2;
    if(cut(mid) >= m) return solve(mid, hi);
    else return solve(lo, mid-1);
}
int main()

{
    
    cin>>n>>m;
    for(ll i = 0LL; i < n; i++)
    {
        ll t;
        cin>>t;
        M = max(M, t);
        woods[i] = t;
    }
    cout<<solve();
}
 