#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);    
    long long N,tmp;
    cin >> N;
    long long ans = N*(N-1)/2;    
    while(N--) {
        cin >> tmp;
        ans -= tmp;
    }
    cout << abs(ans);
    return 0;
}