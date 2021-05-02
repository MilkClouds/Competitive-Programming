"""
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
"""

D=[1,1,2]
N=int(input())
for i in range(3,N+1):
	D.append((D[i-1]+D[i-2])%10007)
	
print(D[N])