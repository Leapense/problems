def choose_potion(N):
    if N < 206:
        return 1
    elif N < 218:
        return 2
    elif N < 229:
        return 3
    else:
        return 4

# 입력 예제
N = int(input().strip())
print(choose_potion(N))