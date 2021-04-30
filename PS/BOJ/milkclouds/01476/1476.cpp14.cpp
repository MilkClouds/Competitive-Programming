#include <iostream>
using namespace std;
int E, S, M;
void solve() {
    for (int i = 1; i <= 10000; i++) {
        if (((i - E) % 15) == 0 && ((i - S) % 28) == 0 && ((i - M) % 19) == 0) {
            cout << i << endl;
            return;
        }
    }
}
int main() {
    cin >> E >> S >> M;
    solve();
    return 0;
}
