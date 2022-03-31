#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;
int T, M, a, b, c, d;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> M; c = 0, d = 0;
        rep(i, 0, M){
            cin >> a >> b;
            c += b - a;
            d = max(d, c);
        }
        cout << d << "\n";
    }
}