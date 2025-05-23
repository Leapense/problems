import sys

class Person:
    __slots__ = ['rounds', 'number']
    def __init__(self, rounds, number):
        self.rounds = rounds
        self.number = number

def main():
    input = sys.stdin.read().split()
    idx = 0
    T = int(input[idx])
    idx +=1
    for tc in range(1, T+1):
        N = int(input[idx])
        X = int(input[idx+1])
        idx +=2
        amounts = list(map(int, input[idx:idx+N]))
        idx +=N
        people = []
        for i in range(N):
            rounds = (amounts[i] + X -1) // X
            people.append(Person(rounds, i+1))
        # 정렬: rounds 오름차순, 번호 오름차순
        people.sort(key=lambda p: (p.rounds, p.number))
        order = [str(p.number) for p in people]
        print(f"Case #{tc}: {' '.join(order)}")

if __name__ == "__main__":
    main()
