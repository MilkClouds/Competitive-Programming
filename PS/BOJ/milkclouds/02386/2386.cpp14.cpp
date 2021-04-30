#include <iostream>

int main() {
    char buf[256];
    char c, n;
    while (true) {
        n = 0;
        scanf("%c", &c);
        if (c == '#') {
            break;
        }
        fgets(buf, 256, stdin);
        
        for (int i = 0; buf[i] != '\0'; ++i) {
            if (c == buf[i] || c == buf[i] + 32) {
                ++n;
            }
        }
        printf("%c %d\n", c, n);
    }
    return 0;
}