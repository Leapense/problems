# 입력 받기
a = input().strip()
b = input().strip()

len_a = len(a)
len_b = len(b)
len_max = max(len_a, len_b)
len_min = min(len_a, len_b)

a_num = int(a)
b_num = int(b)

if a_num > b_num:
    print(0)
    exit()

difference = b_num - a_num

gains = []
for i in range(1, len_min +1):
    pos_value = 10 ** (len_max -i)
    a_digit = int(a[i-1])
    b_digit = int(b[i-1])
    gain = 2 * (b_digit - a_digit) * pos_value
    if gain >0:
        gains.append( (gain, i) )

# 이득이 큰 순서대로 정렬
gains_sorted = sorted(gains, key=lambda x:x[0], reverse=True)

sum_gains =0
positions_to_swap = []

for gain, pos in gains_sorted:
    sum_gains += gain
    positions_to_swap.append(pos)
    if sum_gains > difference:
        break

if sum_gains > difference:
    print(len(positions_to_swap))
    print(' '.join(map(str, sorted(positions_to_swap))))
else:
    print("Bad luck")