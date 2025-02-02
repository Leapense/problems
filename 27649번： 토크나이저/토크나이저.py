class Tokenizer:
    def __init__(self, s):
        self.s = s

    def tokenize(self):
        tokens = []
        i = 0
        n = len(self.s)
        current = ""
        while i < n:
            ch = self.s[i]
            if ch == ' ':
                if current:
                    tokens.append(current)
                    current = ""
                while i < n and self.s[i] == ' ':
                    i += 1
                continue
            if ch in "<>()":
                if current:
                    tokens.append(current)
                    current = ""
                tokens.append(ch)
                i += 1
                continue
            if ch == '&' or ch == '|':
                if current:
                    tokens.append(current)
                    current = ""
                tokens.append(self.s[i:i+2])
                i += 2
                continue
            current += ch
            i += 1
        if current:
            tokens.append(current)
        return tokens

    def get_result(self):
        tokens = self.tokenize()
        filtered = [t for t in tokens if t != " "]
        return " ".join(filtered)

if __name__ == "__main__":
    import sys
    s = sys.stdin.readline().rstrip('\n')
    tokenizer = Tokenizer(s)
    print(tokenizer.get_result())