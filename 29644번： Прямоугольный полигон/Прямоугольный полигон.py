import math

def find_sides(S, P):
    if P % 2 != 0:
        return -1
    
    half_p = P // 2

    for b in range(1, int(math.sqrt(S)) + 1):
        if S % b == 0:
            a = S // b
            if 2 * (a + b) == P:
                return a, b if a >= b else b, a
            
    return -1

S, P = map(int, input().split())
result = find_sides(S, P)

if result == -1:
    print(result)
else:
    print(result[0], result[1])