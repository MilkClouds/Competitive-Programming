#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, val;
	cin >> n >> k;
	while (n--) {
		cin >> val;
		vec.push_back(val);
	}
	sort(vec.begin(), vec.end());
	cout << vec.at(k-1) << endl;
}


