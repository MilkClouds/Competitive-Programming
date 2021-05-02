for i in range(int(input())):
	N=int(input())
	if N==1: print('#\n'); continue
	print('#'*N)
	for i in range(N-2):
		print('#'+'J'*(N-2)+'#')
	print('#'*N)
	print()