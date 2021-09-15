#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;


int solve(vector<int>& b, int l, int r){
    vector<ll> G(32);
    rep(i, l, r){
        int tmp = b[i];
        int j = 0;
        while(tmp){
            if(tmp & 1) G[j]++;
            tmp >>= 1;
            j++;
        }
    }
    ll ans = 0;
    rep2(i, 0, 32){
        if(G[i]){
            ans += G[i] - 1;
            rep(j, 0, i) G[j] += G[i] - 1;
        }
    }
    return ans;
}
vector<int> solution(vector<int> m, vector<int> b) {
    vector<int> answer(m.size());
    int j = 0, cnt = 0;
    for(auto i: m){
        answer[cnt++] = solve(b, j, j + i);
        j += i;
    }
    return answer;
}
int main(){
    for(auto i: solution({2, 2}, {3, 2, 1, 2})) cout << i << endl;
    for(auto i: solution({4}, {4, 4, 4, 4})) cout << i << endl;
}