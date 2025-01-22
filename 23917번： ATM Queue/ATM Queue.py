from collections import deque
import sys

class Person:
    def __init__(self, number, amount):
        self.number = number
        self.amount = amount

class ATMQueue:
    def __init__(self, N, X, amounts):
        self.queue = deque()
        for i in range(N):
            self.queue.append(Person(i + 1, amounts[i]))
        self.X = X
        self.result = []

    def process_queue(self):
        while self.queue:
            person = self.queue.popleft()
            if person.amount <= self.X:
                self.result.append(str(person.number))
            else:
                person.amount -= self.X
                self.queue.append(person)
        return ' '.join(self.result)

def main():
    input = sys.stdin.read().split()
    idx = 0
    T = int(input[idx])
    idx += 1
    for tc in range(1, T + 1):
        N = int(input[idx])
        X = int(input[idx + 1])
        idx += 2
        amounts = list(map(int, input[idx:idx+N]))
        idx += N
        atm = ATMQueue(N, X, amounts)
        order = atm.process_queue()
        print(f"Case #{tc}: {order}")

if __name__ == "__main__":
    main()