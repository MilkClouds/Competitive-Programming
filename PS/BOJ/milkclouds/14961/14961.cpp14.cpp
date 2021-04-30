#include <cstdio>
int n, i, now, prv;
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("%d ", now-prv ? 1 : i);
        prv = now;
        scanf("%d %d", &now, &now);
    }
    return 0;
}