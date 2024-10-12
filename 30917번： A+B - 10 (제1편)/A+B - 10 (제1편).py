def find_value(var):
    for x in range(1, 10):
        print(f"? {var} {x}", flush=True)
        response = int(input().strip())
        if response == 1:
            return x
    return None

A = find_value("A")
B = find_value("B")

print(f"! {A + B}", flush=True)