inv[1] = 1;
rep(i, 2, MAX) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
