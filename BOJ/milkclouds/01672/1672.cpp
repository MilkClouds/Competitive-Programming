#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

map<pair<char, char>, char> M;
int N;
string S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> S;
    if(N == 1){
        cout << S << endl;
        return 0;
    }
    M[{'A', 'A'}] = 'A';
    M[{'A', 'G'}] = 'C';
    M[{'A', 'C'}] = 'A';
    M[{'A', 'T'}] = 'G';
    M[{'G', 'A'}] = 'C';
    M[{'G', 'G'}] = 'G';
    M[{'G', 'C'}] = 'T';
    M[{'G', 'T'}] = 'A';
    M[{'C', 'A'}] = 'A';
    M[{'C', 'G'}] = 'T';
    M[{'C', 'C'}] = 'C';
    M[{'C', 'T'}] = 'G';
    M[{'T', 'A'}] = 'G';
    M[{'T', 'G'}] = 'A';
    M[{'T', 'C'}] = 'G';
    M[{'T', 'T'}] = 'T';
    rep2(i, 1, N){
        S[i - 1] = M[{S[i - 1], S[i]}];
    }
    cout << S[0] << endl;
}
