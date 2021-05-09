vector<ll> pn;
bool arr[MAX];

void eratos() {
	pn.push_back(2);
	for (ll i = 3; i < MAX; i += 2) {
		if (arr[i]) continue;
		pn.push_back(i);
		for (ll j = i * i; j < MAX; j += i) arr[j] = 1;
	}
}