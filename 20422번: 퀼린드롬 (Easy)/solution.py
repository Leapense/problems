import sys

mirror = {
    'A': 'A', 'H': 'H', 'I': 'I', 'M': 'M', 'O': 'O', 'T': 'T', 'U': 'U', 'V': 'V', 'W': 'W', 'X': 'X', 'Y': 'Y',
    '0': '0', '1': '1', '8': '8',
    'n': 'n', 'o': 'o', 'u': 'u', 'v': 'v', 'w': 'w', 'x': 'x', 'i': 'i', 'l': 'l', 'm': 'm',
    'b': 'd', 'd': 'b', 'p': 'q', 'q': 'p', 'S': '2', '2': 'S', 'E': '3', '3': 'E', 'Z': '5', '5': 'Z', '7': 'r', 'r': '7'
}

def variant_list(ch):
    res = set()
    if ch.isalpha():
        for v in {ch.lower(), ch.upper()}:
            if v in mirror:
                res.add(v)
    else:
        if ch in mirror:
            res.add(ch)
    return list(res)

def check_delta(n, vars_list, delta):
    chosen = [None] * n
    for t in range(n):
        j = n + delta - 1 - t
        if 0 <= j < n and t <= j:
            if t == j:
                found = False
                for x in vars_list[t]:
                    if mirror[x] == x:
                        chosen[t] = x
                        found = True
                        break
                if not found:
                    return None
            else:
                ok = False
                for x in vars_list[t]:
                    y = mirror[x]
                    if y in vars_list[j]:
                        chosen[t] = x
                        chosen[j] = y
                        ok = True
                        break
                if not ok:
                    return None
        elif not (0 <= j < n):
            if chosen[t] is None:
                if not vars_list[t]:
                    return None
                chosen[t] = vars_list[t][0]
    for idx in range(n):
        if chosen[idx] is None:
            chosen[idx] = vars_list[idx][0]
    return chosen

def build_result(chosen, delta):
    n = len(chosen)
    length = n + abs(delta)
    offset = max(0, -delta)
    res = [''] * length
    for t, ch in enumerate(chosen):
        pos = offset + t
        res[pos] = ch
        res[length - 1 - pos] = mirror[ch]
    for i in range(length):
        if res[i] == '':
            res[i] = 'A'
            res[length - 1 - i] = 'A'
    return ''.join(res)

def main():
    s = sys.stdin.readline().rstrip('\n')
    n = len(s)
    vars_list = [variant_list(c) for c in s]
    if any(len(v) == 0 for v in vars_list):
        print(-1)
        return
    for d in range(n + 1):
        for delta in ([d] if d == 0 else [d, -d]):
            chosen = check_delta(n, vars_list, delta)
            if chosen is not None:
                print(build_result(chosen, delta))
                return
    print(-1)

if __name__ == '__main__':
    main()