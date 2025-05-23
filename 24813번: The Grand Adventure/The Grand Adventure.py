class Adventure:
    def __init__(self, path):
        self.path = path
        self.stack = []
        self.demand = {'t': '|', 'j': '*', 'b': '$'}

    def can_complete(self):
        for char in self.path:
            if char in {'$', '|', '*'}:
                self.stack.append(char)
            elif char in {'t', 'j', 'b'}:
                if not self.stack or self.stack[-1] != self.demand[char]:
                    return "NO"
                self.stack.pop()
        return "YES" if not self.stack else "NO"
    
n = int(input())
for _ in range(n):
    path = input().strip()
    adventure = Adventure(path)
    print(adventure.can_complete())