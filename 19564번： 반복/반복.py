def main():
    s = input()
    ans = 1
    cur = s[0]
    for i in range(1, len(s)):
        next = s[i]
        if ord(next) - ord('a') <= ord(cur) - ord('a'):
            ans += 1
        cur = next
    print(ans)

main()