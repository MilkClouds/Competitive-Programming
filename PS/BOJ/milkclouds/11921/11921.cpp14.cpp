#include <iostream>

char buf[67108864];

int main() {
    int t;
    int n = 0, idx = 0;
    long long sum = 0;
    
    fread(buf, 1, 67108864, stdin);
    
    for (; buf[idx] != '\n'; ++idx) {
        n *= 10;
        n += buf[idx] - '0';
    }
    
    for (int i = 0; i < n; ++i) {
        t = 0;
        
        for (++idx; buf[idx] != '\n'; ++idx) {
            t *= 10;
            t += buf[idx] - '0';
        }
        
        sum += t;
    }
    
    return !printf("%d\n%lld", n, sum);
}