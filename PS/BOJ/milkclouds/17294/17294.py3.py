def f(x):
	if len(x)==1: return True
	d=int(x[1])-int(x[0])
	for i in range(1,len(x)):
		if int(x[i])==int(x[i-1])+d:
			continue
		return False
	return True

print("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" if f(input()) else "흥칫뿡!! <(￣ ﹌ ￣)>")