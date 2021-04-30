class node:
    def __init__(self,value):
        self.value=value
        self.front=self.back=None

class List:
    def __init__(self,txt):
        self.begin=node(0)
        prev=self.begin
        for s in txt:
            t=node(s)
            t.front=prev
            prev.back=t
            prev=t
        self.cursor=prev
    def L(self):
        if self.cursor.front:
            self.cursor=self.cursor.front
    def D(self):
        if self.cursor.back:
            self.cursor=self.cursor.back
    def B(self):
        front=self.cursor.front
        back=self.cursor.back
        if front:
            front.back=back
            if back:
                back.front=front
            self.cursor=front
    def P(self,s):
        t=node(s)
        front=self.cursor
        back=self.cursor.back
        self.cursor=t
        if front:
            front.back=self.cursor
        if back:
            back.front=self.cursor
        self.cursor.front=front
        self.cursor.back=back
    def print(self):
        self.cursor=self.begin.back
        while self.cursor:
            print(self.cursor.value)
            self.cursor=self.cursor.back

import sys
input=lambda:sys.stdin.readline().rstrip()
print=sys.stdout.write
List=List(input())
for _ in range(int(input())):
    c=input()
    if c=='L': List.L()
    elif c=='D':List.D()
    elif c=='B': List.B()
    else: List.P(c.split()[1])
List.print()