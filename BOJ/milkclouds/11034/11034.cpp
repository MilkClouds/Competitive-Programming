#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    while(~scanf("%d %d %d", &a, &b, &c)){
        cout << max(abs(a - b), abs(b - c)) - 1 << "\n";
    }
}