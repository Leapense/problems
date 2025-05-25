import sys
import re

def parse_value(value, context):
    if ".." in value:
        start, end = value.split("..")
        start_val = int(context[start]) if start in context else int(start)
        end_val = int(context[end]) if end in context else int(end)
        return [str(v) for v in range(start_val, end_val + 1)]
    elif value.isdigit() or (value[0] == '-' and value[1:].isdigit()):
        return [value]
    elif value in context:
        return [str(context[value])]
    else:
        return [value]
    
def expand_definition(expr, context):
    result = []
    for part in expr.split(','):
        result.extend(parse_value(part, context))
    return result

def dfs(variables, definitions, idx, context, order, results, formula, var_pattern):
    if idx == len(order):
        def replacer(m):
            return context[m.group()]
        results.append(var_pattern.sub(replacer, formula))
        return
    var = order[idx]
    values = expand_definition(definitions[var], context)
    for v in values:
        context[var] = v
        dfs(variables, definitions, idx + 1, context, order, results, formula, var_pattern)
        del context[var]

def main():
    formula = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    definitions = {}
    variables = []
    for _ in range(n):
        line = sys.stdin.readline().strip()
        var, expr = line.split('=')
        var = var.strip()
        definitions[var] = expr.strip()
        variables.append(var)

    var_pattern = re.compile(r'[a-z]')
    results = []
    dfs(variables, definitions, 0, {}, variables, results, formula, var_pattern)

    for res in sorted(set(results)):
        print(res)

if __name__ == "__main__":
    main()