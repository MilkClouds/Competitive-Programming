# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}
// trim from start (in place)
static inline void ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s) {
	ltrim(s);
	rtrim(s);
}


map<string, ll> m;
ll N, M;
string s;
char in[10005];

int main() {
	cin.tie(0); cout.tie(0); //ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) {
		cin >> s;
		if(s.size() > 2) sort(s.begin() + 1, s.end() - 1);
		m[s]++;
	}
	cin >> M; getchar();
	rep(i, 0, M) {
		fill(in, in + 10002, 0);
		fgets(in, sizeof(in), stdin);
		s = string(in);
		trim(s);
		ll ret = 1;
		for (auto i : split(s, ' ')) {
			if (i.size() > 2) sort(i.begin() + 1, i.end() - 1);
			ret *= m[i];
		}
		cout << ret << "\n";
	}
}
