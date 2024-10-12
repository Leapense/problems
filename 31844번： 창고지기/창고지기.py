def solve(s):
    st = 0
    fin = 0
    box = 0
    for i in range(10):
        if s[i] == '@': st = i
        if s[i] == '#': box = i
        if s[i] == '!': fin = i

    if st < box and box < fin: return fin - st - 1
    elif fin < box and box < st: return st - fin - 1
    else: return -1

s = input()
print(solve(s))