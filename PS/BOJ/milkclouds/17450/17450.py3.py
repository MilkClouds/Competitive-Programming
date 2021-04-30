x = [*map(int, input().split())] + [0]
y = [*map(int, input().split())] + [1]
z = [*map(int, input().split())] + [2]
f = lambda x: -10 * x[1] / (x[0] * 10 if x[0] < 500 else x[0] * 10 - 500)
print("SNU"[sorted([x,y,z], key = f)[0][2]])
