import math
pi = math.pi
e = math.e

def RK4(f, t0, y0, dt, iterations):
	t, y = t0, y0
	for it in range(iterations):
		k1 = dt * f(t, y)
		k2 = dt * f(t + dt / 2, y + k1 / 2)
		k3 = dt * f(t + dt / 2, y + k2 / 2)
		k4 = dt * f(t + dt, y + k3)
		
		y += (k1 + 2 * k2 + 2 * k3 + k4) / 6
		t += dt
	return y

f = lambda x: a * e ** (- x ** 2) + b * x ** .5

dt = 1e-4
V, N = map(float, input().split())
N = int(N)

ans = (1e12, 0)
for i in range(N):
	a, b, h = map(float, input().split())
	v = RK4(lambda t, y: f(t) ** 2 * pi, 0, 0, dt, int(h / dt))
	ans = min(ans, (abs(V - v), i))

print(ans[1])
