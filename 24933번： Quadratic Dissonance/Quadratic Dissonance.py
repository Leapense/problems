A, B, C, D = map(int, input().split())

def f(x):
    return x * x + A * x + B

def g(x):
    return x * x + C * x + D

def h(x):
    return max(f(x), g(x))

low = -1e12
high = 1e12

for _ in range(200):
    mid1 = low + (high - low) / 3
    mid2 = high - (high - low) / 3
    if h(mid1) < h(mid2):
        high = mid2
    else:
        low = mid1

x_star = (low + high) / 2
h_star = h(x_star)

print("{0:.10f} {1:.10f}".format(x_star, h_star).rstrip('0').rstrip('.') if '.0' in "{0:.10f} {1:.10f}".format(x_star, h_star) else "{0:.10f} {1:.10f}".format(x_star, h_star))