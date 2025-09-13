import sys
from itertools import product

s = sys.stdin.readline().strip()
parts = s.split('?')
A = [int(x) for x in parts]

ops_list = ['+', '-', '*']

def build_and_check(eq_pos, ops_pick):
    nums = list(map(str, A))
    ops_full = []
    it = iter(ops_pick)
    for i in range(3):
        if i == eq_pos:
            ops_full.append('=')
        else:
            ops_full.append(next(it))

    expr_tokens = [nums[0], ops_full[0], nums[1], ops_full[1], nums[2], ops_full[2], nums[3]]
    left_tokens = []
    right_tokens = []
    on_left = True
    for t in expr_tokens:
        if t == '=':
            on_left = False
            continue
        (left_tokens if on_left else right_tokens).append(t)
    left_expr = ''.join(left_tokens)
    right_expr = ''.join(right_tokens)
    try:
        left_val = eval(left_expr)
        right_val = eval(right_expr)
    except Exception:
        return None
    if left_val == right_val:
        return ''.join(expr_tokens)
    return None

for eq_pos in range(3):
    for ops_pick in product(ops_list, repeat=2):
        res = build_and_check(eq_pos, ops_pick)
        if res is not None:
            print(res)
            sys.exit(0)

print("EI SAA")