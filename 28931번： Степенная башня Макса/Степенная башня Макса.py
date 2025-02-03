import sys
input = sys.stdin.readline
n = int(input())
nums = list(map(int, input().split()))
if n == 1:
    print(nums[0] % 3)
else:
    a1 = nums[0] % 3
    if a1 == 0:
        print(0)
    elif a1 == 1:
        print(1)
    else:
        print(1 if nums[1] % 2 == 0 else 2)