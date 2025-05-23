O = int(input())
message = input().strip()
N = int(input())

vowels = {'a', 'e', 'i', 'o', 'u', 'y'}
t = len(message)
good_steps = 0
bad_steps = 0

for i in range(1, N + 1):
    shift = (O * i) % 26
    shifted = []
    for c in message:
        new_ord = (ord(c) - ord('a') + shift) % 26
        shifted_char = chr(new_ord + ord('a'))
        shifted.append(shifted_char)
    count = sum(1 for char in shifted if char in vowels)
    if 3 * count >= t:
        bad_steps += 1
    else:
        good_steps += 1

print("Boris" if good_steps > bad_steps else "Colleague")