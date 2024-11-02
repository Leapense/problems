import math

def solve():
    x_A, y_A = map(int, input().split())
    x_B, y_B = map(int, input().split())
    a, b = map(int, input().split())
    
    dx = abs(x_B - x_A)
    dy = abs(y_B - y_A)
    
    # Найдём gcd для dx и dy
    gcd = math.gcd(dx, dy)
    
    # Минимальная ширина и высота ступеньки
    w = dx // gcd
    h = dy // gcd
    
    # Найдём максимальный коэффициент k, такой что:
    # k * w >= a и k * h <= b
    k_min = max((a + w - 1) // w, 1)  # округление вверх для (a / w)
    k_max = b // h
    
    # Если существует подходящий k
    if k_min <= k_max:
        k = k_max
        print(w * k, 1)
        print(h * k, 1)
    else:
        print(-1)

solve()
