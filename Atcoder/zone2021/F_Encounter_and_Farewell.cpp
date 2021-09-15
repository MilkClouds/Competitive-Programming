#include <iostream>
#include <vector>
using namespace std;
void chmin(int& a, int b){ if(a > b) a = b; }

int main(){
    int N, M;
    cin >> N >> M;
    vector ok(N, true);
    while(M--){
        int A;
        cin >> A;
        ok[A] = false;
    }
    vector<int> base, elim;
    for(int x = 1; x < N; x++) if(ok[x]){
        int y = x;
        for(int b : elim) chmin(y, y ^ b);
        if(y){
            base.push_back(x);
            elim.push_back(y);
        }
    }
    if(base.size() != __lg(N)) return puts("-1") & 0;
    int XOR = 0;
    for(int x = 1; x < N; x++){
        cout << XOR << ' ';
        XOR ^= elim[__lg(x & -x)];
        cout << XOR << '\n';
    }
}
