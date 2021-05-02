import sys
i=sys.stdin.readline
while 1:
	d,r1,r2=map(float,i().split())
	if d==r1==r2==0: break
	w=16*d/(337**.5)
	h=(d**2-w**2)**.5
	print("Horizontal DPI: %.2f\nVertical DPI: %.2f"%(r1/w,r2/h))