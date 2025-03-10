def solve():
    import sys
    data = sys.stdin.read().splitlines()
    tokens = []
    def tokenize(s):
        s = s.replace('(', ' ( ').replace(')', ' ) ')
        return s.split()
    
    def parse(tokens):
        token = tokens.pop(0)
        if token == '(':
            p = float(tokens.pop(0))
            e1 = parse(tokens)
            e2 = parse(tokens)
            tokens.pop(0)
            return (p, e1, e2)
        else:
            return float(token)
    def eval_expr(expr):
        if isinstance(expr, float):
            return expr
        p, e1, e2 = expr
        x = eval_expr(e1)
        y = eval_expr(e2)
        return x + y * (2 * p - 1)
    results = []
    for line in data:
        if line.strip() == "()":
            break
        tokens = tokenize(line.strip())
        expr = parse(tokens)
        res = eval_expr(expr)
        results.append("{:.2f}".format(res))
    sys.stdout.write("\n".join(results))

solve()