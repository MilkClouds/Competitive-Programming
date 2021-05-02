#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}
long fibo(long n){
    if (n <= 1) {
        return n;
    }

    matrix ans = {{1, 0}, {0, 1}};
    matrix a = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }

    return ans[0][1];
}
long gcd(long a,long b){
    if(a>b)swap(a,b);
    if(b%a==0)return a;
    return gcd(a,b%a);
}
int main() {
    long long n,m;
    cin >> n >> m;
    cout<<fibo(gcd(n,m));
    return 0;
}