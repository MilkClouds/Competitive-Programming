N = int(input())
A = [*map(int, input().split())]
A.sort()
def solution(start, step):
	if step > N: return 0
	a = b = 0
	for i in range(start, N, step * 2):
		a += A[i]
	for i in range(start + step, N, step * 2):
		b += A[i]
	return a * b + solution(start, step * 2) + solution(start + step, step * 2)

print(solution(0, 1))
