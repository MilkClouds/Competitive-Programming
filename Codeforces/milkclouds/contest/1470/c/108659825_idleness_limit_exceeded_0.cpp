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

int N, K, p, q, l, r, m, cnt;

int query(int q){
  cnt++;
  if(q >= N) q -= N;
  cout << "? " << ++q << "\n";
  int p;
  cin >> p;
  return p;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> K;
  rep(i, 0, 800) {
    query(0);
  }
  if(N >= 1601){
    for(int i = 0; i < N; i += 800){
      p = query(i);
      if(p < K) {l = i; break;}
    }
    r = l + cnt;
  } else {
    for(auto q:{0, N / 2, N - 1}){
      p = query(q);
      if(p < K){l = q; break;}
    }
    r = l + N / 2;
  }
  while(r - l > 1){
    m = l + r >> 1;
    p = query(m);
    if(p < K) l = m;
    else r = m;
  }
  cout << "! " << ((l + 1) % N + 1);
}
