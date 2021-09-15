# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

int rev = 0;
deque<char> deq;
string S, ans;
void push(char c){
    if(rev) {
        if(!deq.empty() && deq.front() == c) deq.pop_front();
        else deq.push_front(c);
    }
    else {
        if(!deq.empty() && deq.back() == c) deq.pop_back();
        else deq.push_back(c);
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> S;
    for(auto c: S){
        if(c == 'R') rev ^= 1;
        else {
            push(c);
        }
    }
    if(rev) reverse(all(deq));
    for(auto c: deq) cout << c;
}
