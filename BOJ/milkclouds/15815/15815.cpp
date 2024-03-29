#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

string S;
stack<int> SS;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> S;
    for(auto i: S){
        if('0' <= i && i <= '9'){
            SS.push(i - '0');
        } else {
            int v = SS.top(); SS.pop();
            int u = SS.top(); SS.pop();
            switch (i)
            {
                case '*':
                    SS.push(u * v);
                    break;
                case '+':
                    SS.push(u + v);
                    break;
                case '/':
                    SS.push(u / v);
                    break;
                case '-':
                    SS.push(u - v);
                    break;
            }
        }
    }
    cout << SS.top() << endl;
}
