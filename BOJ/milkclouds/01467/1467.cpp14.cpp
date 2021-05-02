#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num, num_del;
int cnt[10];
string result;

int main()
{
	cin >> num >> num_del;
	
	for (int i : num)
		cnt[i-'0']++;
	for (int i : num_del)
		cnt[i-'0']--;

	int idx = 0;
	for (int x = 9; x >= 0; x--) {
		if (cnt[x] == 0)
			continue;
		for (int i = idx; i < num.size(); i++) {
			if (num[i]-'0' == x) {
				int tcnt[10];
				memcpy(tcnt, cnt, sizeof(int) * 10);
				for (int j = i; j < num.size(); j++)
					tcnt[num[j]-'0'] = max(0, tcnt[num[j]-'0']-1);

				if (count(tcnt, tcnt+10, 0) == 10) {
					idx = i+1;
					result.push_back(x+'0');
					cnt[x]--;
					x = 10;
				}
				break;
			}
		}
	}

	cout << result;
	return 0;
}