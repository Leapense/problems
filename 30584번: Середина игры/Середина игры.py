A = int(input())
B = int(input())

if A % 2 != B % 2:
    print("Error")
elif min(A, B) > 1:
    print("Undefined")
else:
    ans1 = max((A - B) // 2, 0)
    ans2 = max((B - A) // 2, 0)
    ans3 = min(A, B)
    print(ans1)
    print(ans2)
    print(ans3)