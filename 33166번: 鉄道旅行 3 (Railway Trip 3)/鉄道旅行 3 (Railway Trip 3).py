def calculate_fare():
    P, Q = map(int, input().split())
    A, B = map(int, input().split())

    if Q <= P:
        fare = Q * A
    else:
        fare = P * A + (Q - P) * B

    print(fare)

calculate_fare()