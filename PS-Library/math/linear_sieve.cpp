#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MAX=101010;
vector<int> pn;
ll sp[MAX], e[MAX], phi[MAX], mu[MAX], tau[MAX], sigma[MAX];
ll pw(ll a, ll b){
    ll ret = 1;
    for(; b; b >>= 1, a *= a) if(b & 1) ret *= a;
    return ret;
}
// https://ahgus89.github.io/algorithm/Linear-sieve/
// https://ahgus89.github.io/algorithm/Notation/
void sieve(){
    phi[1] = 1;
    mu[1] = 1;
    tau[1] = 1;
    sigma[1] = 1;
    for(int i = 2; i < MAX; i++){
        if(!sp[i]){
            pn.push_back(i);
            sp[i] = i;
            e[i] = 1;
            phi[i] = i - 1;
            mu[i] = -1;
            tau[i] = 2;
            sigma[i] = i + 1;
        }
        for(auto j: pn){
            if(i * j >= MAX) break; //!ll
            // j: i*j의 최소인수(because j<(i의 최소인수))
            sp[i * j] = j;
            if(i % j == 0){
                e[i * j] = e[i] + 1;
                phi[i * j] = phi[i] * j;
                mu[i * j] = 0;
                tau[i * j] = tau[i] / e[i * j] * (e[i * j] + 1);
                sigma[i * j] = sigma[i] * (j - 1) / (pw(j, e[i * j]) - 1) * (pw(j, e[i * j] + 1) - 1) / (j - 1);
                break; // j==(i의 최소인수)이면 break
            }
            // gcd(i, j) == 1
            e[i * j] = 1;
            phi[i * j] = phi[i] * phi[j];
            mu[i * j] = mu[i] * mu[j];
            tau[i * j] = tau[i] * tau[j];
            sigma[i * j] = sigma[i] * sigma[j];
        }
    }
}


// ======================================================================
vector<int> pn;
ll sp[MAX];
// https://ahgus89.github.io/algorithm/Linear-sieve/
// https://ahgus89.github.io/algorithm/Notation/
void sieve(){
    for(int i = 2; i < MAX; i++){
        if(!sp[i]){
            pn.push_back(i);
            sp[i] = i;
        }
        for(auto j: pn){
            if(i * j >= MAX) break; //!ll
            // j: i*j의 최소인수(because j<(i의 최소인수))
            sp[i * j] = j;
            if(i % j == 0)break; // j==(i의 최소인수)이면 break
        }
    }
}