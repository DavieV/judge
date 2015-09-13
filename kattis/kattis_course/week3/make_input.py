import random

def random_name():
    name = ''
    for i in range(20):
        name += chr(random.randint(97, 122))
    return name

print(2)
print(99999)
for i in range(99999):
    print(random_name(), random_name())

print(99999)
for i in range(99999):
    print(random_name(), random_name())

