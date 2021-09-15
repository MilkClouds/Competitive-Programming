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

struct DS{
    deque<int> Q;
    multiset<int> S;
    void insert(int x){
        Q.pb(x);
    }
    int p(){
        if(S.empty()){
            assert(!Q.empty());
            int ret = Q.front();
            Q.pop_front();
            return ret;
        }
        int ret = *S.begin();
        S.erase(S.begin());
        return ret;
    }
    void q(){
        while(!Q.empty()){
            S.insert(Q.front());
            Q.pop_front();
        }
    }
} ds;
int Q, i, x;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> Q;
    while(Q--){
        cin >> i;
        if(i == 1){
            cin >> x;
            ds.insert(x);
        } else if(i == 3){
            ds.q();
        } else {
            cout << ds.p() << "\n";
        }
    }
}
