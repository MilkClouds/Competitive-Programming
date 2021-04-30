import sys
index=0
for line in sys.stdin:
	a,b=line.split('=')
	x=1j;index+=1
	f=eval(a+'-('+b+')')
	#ax+b=0
	a,b=f.imag,f.real
	print('Equation #%d'%index)
	if a==0:
		if b!=0: print('No solution.')
		else: print("Infinitely many solutions.")
	else:
		ans=-b/a
		print('x = %.6f'%ans)
	print()