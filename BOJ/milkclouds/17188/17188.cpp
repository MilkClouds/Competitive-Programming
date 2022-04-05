#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std;
using ll = long long;
using B = bitset<501>;
using ai = array<int, 6>;

const int MAX = 501;
ai A[MAX], root;
int N, K, C;
struct Partition{
    B ban; ai arr{-1, -1, -1, -1, -1, -1}; int fix = 0, sum = 0;
    Partition(){}
    Partition(Partition prv, int fix): ban(prv.ban), fix(fix){
        rep(i, 0, fix) arr[i] = prv.arr[i];
        rep(j, fix, K){
            int M = -1;
            rep(i, 0, N){
                if(ban[i]) continue;
                if(A[i][j] > M){
                    M = A[i][j];
                    arr[j] = i;
                }
            }
            if(arr[j] == -1) break;
            ban[arr[j]] = 1;
        }
        rep(j, fix, K) if(~arr[j]) ban[arr[j]] = 0;
        if(~arr[K - 1]) score();
    }
    void score(){
        rep(i, 0, K){
            int M = -1;
            rep(j, 0, K) M = max(M, A[arr[j]][i]);
            sum += M;
        }
    }
    friend bool operator < (const Partition& a, const Partition& b){
        return a.sum < b.sum;
    }
};
priority_queue<Partition> pq;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K >> C;
    rep(i, 0, N){
        rep(j, 0, K){
            cin >> A[i][j];
        }
    }
    pq.emplace(Partition(), 0);
    rep(i, 1, C){
        assert(!pq.empty());
        auto a = pq.top(); pq.pop();
        for(; a.fix < K; a.fix++){
            a.ban[a.arr[a.fix]] = 1;
            Partition nxt = Partition(a, a.fix);
            if(~nxt.arr[K - 1]) pq.push(nxt);
        }
    }
    assert(!pq.empty());
    cout << pq.top().sum << endl;
}
