#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int main() {
	cin >> s;
	s += s;
	int ans = 0;
	for (int i = 0; i < 52; i++) {
		if (s[i] == 0)continue;
		vector<int> check('Z' + 1);
		for (int j = i + 1; 1; j++) {
			if (s[i] == s[j]) {
				s[j] = 0;
				for (int k = 'A'; k < 'Z' + 1; k++) {
					if (check[k])ans++;
				}
				break;
			}
			check[s[j]] ^= 1;
		}
	}
	cout << ans;
}

