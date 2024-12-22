def solve():
    import sys
    expr = sys.stdin.readline().strip()
    tokens = []
    i = 0
    first_sign = ''
    if expr[0] in '+-':
        first_sign = expr[0]
        i = 1
    start = i
    while i < len(expr):
        if expr[i] in '+-':
            digits = expr[start:i]
            tokens.append((first_sign, digits))
            first_sign = expr[i]
            i += 1
            start = i
        else:
            i += 1
    digits = expr[start:]
    tokens.append((first_sign, digits))

    def to_int(s):
        return int(s)
    
    def chunk_max_expr(c):
        return c
    
    def chunk_min_expr(c):
        best_val = to_int(c)
        best_str = c
        n = len(c)

        for i in range(1, n):
            left, right = c[:i], c[i:]
            if (left[0] == '0' and len(left) > 1):
                continue
            if (right[0] == '0' and len(right) > 1):
                continue
            val = to_int(left) - to_int(right)
            if val < best_val:
                best_val = val
                best_str = left + '-' + right
        return best_str
    
    answer = []
    for idx, (sgn, c) in enumerate(tokens):
        if idx == 0:
            if sgn in ('', '+'):
                answer.append('+' + chunk_max_expr(c) if sgn == '+' else chunk_max_expr(c))
            else:
                answer.append('-' + chunk_min_expr(c))
        else:
            if sgn == '+':
                answer.append('+' + chunk_max_expr(c))
            else:
                answer.append('-' + chunk_min_expr(c))
    print(''.join(answer))

solve()