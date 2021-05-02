'''각 테스트 케이스마다 첫 번째 숫자가 두 번째 숫자의 약수라면 factor를, 배수라면 multiple을, 둘 다 아니라면 neither를 출력한다.'''

import sys
for line in sys.stdin:
	a,b=map(int,line.split())
	if a==b==0: break
	if b%a==0:
		print('factor')
	elif a%b==0:
		print('multiple')
	else:
		print("neither")