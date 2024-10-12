def is_sufficiently_round(num):
    num_str = str(num)
    total_digits = len(num_str)
    trailing_zeros = len(num_str) - len(num_str.rstrip('0'))
    return trailing_zeros * 2 >= total_digits

def find_next_prize(prev_prize):
    next_candidate = prev_prize * 2
    while not is_sufficiently_round(next_candidate):
        next_candidate += 1
    return next_candidate

def generate_prizes(n):
    prizes = [100]
    for i in range(1, n):
        next_prize = find_next_prize(prizes[-1])
        prizes.append(next_prize)
    return prizes

n = int(input())

prizes = generate_prizes(n)
for prize in prizes:
    print(prize)