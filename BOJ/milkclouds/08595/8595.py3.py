import sys
i=sys.stdin.readline;i()
import re
t=i()
print(sum(map(int,re.findall('\d+',t))))