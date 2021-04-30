#include <stdio.h>
#include <vector>
#define MOD 1000000009



bool check[40000];
std::vector<long long> prime, vec, q;
long long Y[100010];


int main(void) {

	for (long long i = 2; i < 40000; i++) {
		if (check[i] == false) {
			for (long long j = i * i; j < 40000; j += i)
				check[j] = true;
			prime.push_back(i);
		}
	}

	long long n, k;
	scanf("%lld %lld", &n, &k);
	Y[0] = 1;
	for (int i = 1; i <= n; i++)
		Y[i] = (Y[i - 1] * k) % MOD;

	long long tmp = k;

	for (int i = 0; i < prime.size(); i++) {
		bool flag = false;
		while (tmp % prime[i] == 0) {
			tmp /= prime[i];
			flag = true;
		}

		if (flag) {
			vec.push_back(prime[i]);
			q.push_back(prime[i]);

		}
	}

	if (tmp != 1) {
		vec.push_back(tmp);
		q.push_back(tmp);
	}

	tmp = k;
	for (int i = 0; i < vec.size(); i++)
		tmp /= vec[i];

	long long tmp2 = tmp;
	long long r = 0;
	for (int i = 1; i <= n; i++) {
		long long s = (Y[n - i] * (n - i + 1)) % MOD;

		for (int j = 0; j < vec.size(); j++)
			s = (s * ((vec[j] - 1 + MOD) % MOD)) % MOD;
		r = (r + (s * tmp) % MOD) % MOD;

		for (int j = 0; j < vec.size(); j++) {
			vec[j] = (vec[j] * q[j]) % MOD;
		}
		tmp = (tmp * tmp2) % MOD;
	}

	printf("%lld\n", r);
}

