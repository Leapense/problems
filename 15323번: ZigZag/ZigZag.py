import sys, heapq
from collections import defaultdict

def main():
    data = sys.stdin.read().splitlines()
    K, N = map(int, data[0].split())
    words = data[1:1+K]
    letters = data[1+K:]
    groups = defaultdict(list)
    for word in words:
        groups[word[0]].append(word)
    word_list = []
    frequency = []
    per_letter_heap = {}
    for c in groups:
        sorted_words = sorted(groups[c])
        heap = []
        for word in sorted_words:
            word_list.append(word)
            frequency.append(0)
            heap.append((0, len(word_list) - 1))
        heapq.heapify(heap)
        per_letter_heap[c] = heap
    output = []
    for letter in letters:
        heap = per_letter_heap[letter]
        while True:
            freq, idx = heapq.heappop(heap)
            if freq == frequency[idx]:
                output.append(word_list[idx])
                frequency[idx] += 1
                heapq.heappush(heap, (freq + 1, idx))
                break
    print('\n'.join(output))

if __name__ == '__main__':
    main()