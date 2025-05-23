def calculate_tax(X, k, U, p):
    tax = 0
    prev = 0
    for i in range(k):
        upper = U[i]
        if X > upper:
            taxable_income = upper - prev
            tax += taxable_income * p[i]
        else:
            taxable_income = X - prev
            if taxable_income > 0:
                tax += taxable_income * p[i]
            return tax
        prev = upper
    # 만약 X가 모든 구간을 초과한다면 마지막 세율을 적용
    if X > prev:
        taxable_income = X - prev
        tax += taxable_income * p[k]
    return tax

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    X = int(data[0])
    k = int(data[1])
    U = list(map(int, data[2:2 + k]))
    p = list(map(int, data[2 + k:2 + k + k + 1]))
    
    total_tax = calculate_tax(X, k, U, p)
    # 세금을 소수점 두 자리로 변환
    dollars = total_tax // 100
    cents = total_tax % 100
    print("{0}.{1:02d}".format(dollars, cents))

if __name__ == "__main__":
    main()