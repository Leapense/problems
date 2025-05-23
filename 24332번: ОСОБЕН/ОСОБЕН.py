import sys

class StrangeSubstringFinder:
    def __init__(self, s):
        self.s = s
        self.n = len(s)
        self.max_length = 0
        self.start_pos = 0

    def find_longest_strange_substring(self):
        last_seen = [-1] * 128
        left = 0

        for right in range(self.n):
            char = self.s[right]
            ascii_val = ord(char)

            if last_seen[ascii_val] >= left:
                left = last_seen[ascii_val] + 1
            
            last_seen[ascii_val] = right
            current_length = right - left + 1

            if current_length > self.max_length:
                self.max_length = current_length
                self.start_pos = left
            elif current_length == self.max_length and left > self.start_pos:
                self.start_pos = left

    def get_result(self):
        substring = self.s[self.start_pos:self.start_pos + self.max_length]
        return self.max_length, self.start_pos, substring
    
def main():
    input_string = sys.stdin.read().rstrip('\n')
    finder = StrangeSubstringFinder(input_string)
    finder.find_longest_strange_substring()
    length, start, substring = finder.get_result()

    print(f"{length} {start}")
    print(substring)

if __name__ == "__main__":
    main()