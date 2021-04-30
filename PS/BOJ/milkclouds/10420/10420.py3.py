from datetime import *

a = "2014-04-02"
b = input()
print((datetime.strptime(a, "%Y-%m-%d") + timedelta(days = int(b) - 1)).strftime("%Y-%m-%d"))