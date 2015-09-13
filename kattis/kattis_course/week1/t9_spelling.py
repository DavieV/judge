import sys

keys = {
    'a' : '2', 'b' : '22', 'c' : '222',
    'd' : "3", 'e' : '33', 'f' : '333',
    'g' : '4', 'h' : '44', 'i' : '444',
    'j' : '5', 'k' : '55', 'l' : '555',
    'm' : '6', 'n' : '66', 'o' : '666',
    'p' : '7', 'q' : '77', 'r' : '777', 's' : '7777',
    't' : '8', 'u' : '88', 'v' : '888',
    'w' : '9', 'x' : '99', 'y' : '999', 'z' : '9999',
    ' ' : '0'
}

def t9(s):
    last = ''
    t9_msg = ''
    for c in s:
        if keys[c][0] in last:
            t9_msg += ' ' + keys[c]
        else:
            t9_msg += keys[c]
        last = keys[c]

    return t9_msg

n = int(input())

for i in range(n):
    s = sys.stdin.readline().strip("\n")
    print('Case #' + str(i+1) + ': ' + t9(s))
