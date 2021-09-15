h, w = map(int, input().split())

if h > w: h, w = w, h
a = [h / 2]

a.append(min(w / 3, h))
print(max(a))
