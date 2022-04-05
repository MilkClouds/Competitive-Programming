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
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAXN = 100005, MAXC = 26;
struct aho_corasick{
	int trie[MAXN][MAXC], piv; // trie
	int fail[MAXN]; // failure link
	int term[MAXN]; // output check
	void init(vector<string> &v){
		memset(trie, 0, sizeof(trie));
		memset(fail, 0, sizeof(fail));
		memset(term, 0, sizeof(term));
		piv = 0;
		for(auto &i : v){
			int p = 0;
			for(auto &j : i){
				if(!trie[p][j - 'a']) trie[p][j - 'a'] = ++piv;
				p = trie[p][j - 'a'];
			}
			term[p] = 1;
		}
        cout << piv << endl;
		queue<int> que;
		for(int i=0; i<MAXC; i++){
			if(trie[0][i]) que.push(trie[0][i]);
		}
		while(!que.empty()){
			int x = que.front();
			que.pop();
			for(int i=0; i<MAXC; i++){
				if(trie[x][i]){
					int p = fail[x];
					while(p && !trie[p][i]) p = fail[p];
					p = trie[p][i];
					fail[trie[x][i]] = p;
					if(term[p]) term[trie[x][i]] = 1;
					que.push(trie[x][i]);
				}
			}
		}
	}
	bool query(string &s){
		int p = 0;
		for(auto &i : s){
			while(p && !trie[p][i - 'a']) p = fail[p];
			p = trie[p][i - 'a'];
			if(term[p]) return 1;
		}
		return 0;
	}
}aho_corasick;
int N, Q;
vector<string> v;
string S;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N){
        cin >> S;
        v.eb(S);
    }
    aho_corasick.init(v);
    cin >> Q;
    while(Q--){
        cin >> S;
        cout << (aho_corasick.query(S) ? "YES" : "NO") << '\n';
    }
}

