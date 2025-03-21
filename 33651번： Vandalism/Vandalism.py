s = input()
original_s = "UAPC"
removed_c = []

for i in range(len(original_s)):
    if not original_s[i] in s:
        removed_c.append(original_s[i])

print(''.join(removed_c))