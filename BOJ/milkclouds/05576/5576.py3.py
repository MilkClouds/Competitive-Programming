r=list(map(int,[input() for i in range(20)]))
a=sorted(r[:10])[7:]
b=sorted(r[10:])[7:]
print(sum(a),sum(b))