import math

toks = input().split(' ')
h = int(toks[0])
v = int(toks[1])

x = math.ceil(h / math.sin(math.radians(v)))

print(x)

