#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll update(vector<ll>& tree, int node, int index, int start, int end, ll val) {
	if (index < start || end < index) return tree[node];
	if (start == end) return tree[node] = val;
	int mid = (start + end) / 2;
	return tree[node] = (update(tree, node * 2, index, start, mid, val)
					*update(tree, node * 2 + 1, index, mid + 1, end, val))%MOD;
	
}

ll multiple(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return (multiple(tree, 2 * node, start, mid, left, right)
		* multiple(tree, 2 * node + 1, mid + 1, end, left, right)) % MOD;
}

int main() {
	cin.tie(NULL);
    
	int N, M, K;
	cin >> N >> M >> K;
	vector<ll> nums(N + 1);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << h + 1);
	vector<ll> tree(tree_size);
	for (int i = 1; i <= N; ++i) {
		cin >> nums[i];
		update(tree, 1, i, 1, N, nums[i]);
	}
	M += K;
	while (M--) {
		ll t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if (t1 == 1) {
			update(tree, 1, t2, 1, N, t3);
		}
		else {
			cout << multiple(tree, 1, 1, N, t2, t3) << '\n';
		}
	}
}