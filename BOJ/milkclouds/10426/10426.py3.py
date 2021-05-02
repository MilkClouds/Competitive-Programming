from datetime import *

a, b = input().split()
print((datetime.strptime(a, "%Y-%m-%d") + timedelta(days = int(b) - 1)).strftime("%Y-%m-%d"))