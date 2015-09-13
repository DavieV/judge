def format_data(data):
    msg = ""
    for d in data:
        msg += d + ' '
    return msg

n = int(input()) # clear buffer

for i in range(n):
    line = input()
    words = line.split(' ')
    if words[0] == "simon" and words[1] == "says":
        print(format_data(words[2:]))
    else:
        print()
