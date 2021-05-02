#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <cassert>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<pair<int,int> > vii;
typedef vector<pair<ll,int> > vli;
typedef vector<pair<ll,ll> > vll;
typedef vector<pair<db,db> > vdd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mp make_pair
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const db PI = acos(-1);

int main(){

    std::ios::sync_with_stdio(false);

    int n;
    scanf("%d",&n);

    int kk[32]={0,};

    for(int t,i=0;i<n;i++){
        scanf("%d",&t);

        for(int j=0;t;j++){
            if(t%2) kk[j]++;
            t/=2;
        }
    }

    ll result=0;
    for(int j=0;j<20;j++)
        result += (ll)(n-kk[j])*kk[j]*(1<<j);

    printf("%lld", result);

    return 0;
}