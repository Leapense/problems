import sys

def main():
    input = sys.stdin.read().split()
    n = int(input[0])
    m = int(input[1])
    senders = list(map(int, input[2:2+m]))
    total_messages = 0
    total_last_sent_sum = 0
    last_sent = {}
    for i, s in enumerate(senders, 1):
        total_messages += 1
        prev = last_sent.get(s, 0)
        total_last_sent_sum += i - prev
        last_sent[s] = i
        total_unread = n * total_messages - total_last_sent_sum
        print(total_unread)

if __name__ == "__main__":
    main()