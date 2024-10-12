def bargain_score(n, prices):
    today_price = prices[0]

    for i in range(1, n):
        if prices[i] <= today_price:
            return i
        
    return "infinity"

n = int(input())
prices = list(map(int, input().split()))
result = bargain_score(n, prices)
print(result)