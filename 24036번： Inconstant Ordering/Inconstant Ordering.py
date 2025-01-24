from functools import lru_cache
import sys
import sys
import sys

class InconstantOrdering:
    def __init__(self, N, L):
        self.N = N
        self.L = L

    def get_min_string(self):
        N = self.N
        L = self.L

        @lru_cache(maxsize=None)
        def helper(block_index, prev_letter):
            if block_index == N:
                return ''

            current_block_size = L[block_index]

            if block_index % 2 == 0:
                # Odd block: strictly increasing
                # Generate all possible strictly increasing sequences of length L_i starting from s > prev_letter
                # Yield sequences in lex order
                def generate_sequences(start, length, current_seq):
                    if length == 0:
                        yield current_seq
                        return
                    for c in range(start, 26):
                        if not current_seq or c > current_seq[-1]:
                            yield from generate_sequences(c + 1, length - 1, current_seq + (c,))
                
                for seq in generate_sequences(prev_letter + 1, current_block_size, ()):
                    last_letter = seq[-1]
                    rest = helper(block_index + 1, last_letter)
                    if rest is not None:
                        return ''.join(chr(ord('A') + c) for c in seq) + rest

            else:
                # Even block: strictly decreasing
                # Assign a strictly decreasing sequence of L_i letters, starting from s < prev_letter
                for s in range(0, prev_letter):
                    if s - (current_block_size - 1) < 0:
                        continue
                    seq = tuple(s - j for j in range(current_block_size))
                    rest = helper(block_index + 1, seq[-1])
                    if rest is not None:
                        return ''.join(chr(ord('A') + c) for c in seq) + rest

            return None

        result = helper(0, ord('A') - ord('A'))  # Start with 'A' which is 0
        return 'A' + result if result else 'A'

def main():
    import sys
    import sys
    T = int(sys.stdin.readline())
    for test_case in range(1, T +1):
        N_line = ''
        while N_line.strip() == '':
            N_line = sys.stdin.readline()
        N = int(N_line.strip())
        L_line = ''
        while len(L_line.strip().split()) < N:
            L_line += sys.stdin.readline()
        L = list(map(int, L_line.strip().split()))
        io = InconstantOrdering(N, L)
        min_string = io.get_min_string()
        print(f"Case #{test_case}: {min_string}")

if __name__ == "__main__":
    main()
