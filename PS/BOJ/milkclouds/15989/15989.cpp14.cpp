#include <cstdio>
#include <iostream>
using namespace std;
int n, t, d[2][10001];
int main() {
    d[0][2] = 1;
    for (int i = 3; i <= 10000; i++) {
        d[0][i] = d[0][i-2]+1;
        d[1][i] = d[0][i-3]+d[1][i-3]+1;
    }
    // for(int i=0;i<20;i++)cout<<d[0][i]<<endl;
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        printf("%d\n", 1+d[0][n]+d[1][n]);
    }
    return 0;
}