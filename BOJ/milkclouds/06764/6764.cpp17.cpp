#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    vector<int> v(4);
    rep(i, 0, 4) cin >> v[i];
    if(v[0] < v[1] && v[1] < v[2] && v[2] < v[3]) cout << "Fish Rising";
    else if(v[0] > v[1] && v[1] > v[2] && v[2] > v[3]) cout << "Fish Diving";
    else if(v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) cout << "Fish At Constant Depth";
    else cout << "No Fish";
}
