import random
import argparse

INT_MIN = -2**31
INT_MAX = 2**31 - 1
OPERATORS = ['S', 'M', 'U', 'P']

def generate_expression(scenario="general"):
    max_len = 1000000
    if scenario == "long_expression":
        target_n = random.randint(450000, 500000)
    else:
        target_n = random.randint(5, 100)

    expression = []
    current_value = 0
    pending_operator = 'P'
    is_expecting_number = True
    n_count = 0

    while len("".join(expression)) < max_len and n_count < target_n:
        if is_expecting_number:
            num_str = generate_intelligent_number(current_value, pending_operator, scenario)
            operand = int(num_str)

            if pending_operator == 'S': current_value -= operand
            elif pending_operator == 'M': current_value *= operand
            elif pending_operator == 'U':
                if current_value < 0:
                    current_value = -(abs(current_value) // operand)
                else:
                    current_value = current_value // operand
            elif pending_operator == 'P': current_value += operand
            expression.append(num_str)
            n_count += len(num_str)
            is_expecting_number = False
        else:
            op = generate_intelligent_operator(current_value, scenario)
            expression.append(op)
            n_count += 1
            if op != 'C':
                pending_operator = op
                is_expecting_number = True

    if is_expecting_number:
        num_str = generate_intelligent_number(current_value, pending_operator, scenario)
        expression.append(num_str)
        op = generate_intelligent_operator(current_value, scenario)
        expression.append(op)

    final_expression = "".join(expression)
    print(len(final_expression))
    print(final_expression)

def generate_intelligent_number(current_value, operator, scenario):
    if operator == 'M':
        if abs(current_value) > INT_MAX // 100:
            return str(random.randint(0, 2))
        return str(random.randint(0, 100))
    elif operator == 'U':
        return str(random.randint(1, 1000))
    elif operator in ['S', 'P']:
        if current_value > INT_MAX - 10000:
            return str(random.randint(1, 1000))
        if current_value < INT_MIN + 10000:
            return str(random.randint(1, 1000))
        return str(random.randint(1, 50000))
    return str(random.randint(0, 1000))

def generate_intelligent_operator(current_value, scenario):
    if scenario == "no_output":
        return random.choice(OPERATORS)
    if scenario == "negative_division" and current_value > 0:
        return 'S'
    if scenario == "negative_division" and current_value < 0:
        return 'U'

    if current_value > INT_MAX * 0.8:
        return random.choice(['S', 'U', 'C'])
    if current_value < INT_MIN * 0.8:
        return random.choice(['P', 'C'])

    return random.choice(OPERATORS + ['C'])

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate test cases for the SMUPC Calculator problem."
    )
    parser.add_argument(
        "--scenario",
        type=str,
        default="general",
        choices=[
            "general", "no_output", "long_expression",
            "value_boundary", "negative_division"
        ],
        help="Type of test case scenario to generate."
    )

    args = parser.parse_args()
    generate_expression(args.scenario)
