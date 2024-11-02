class Info:
    def __init__(self):
        self.arr = [0] * 4

    def read(self):
        self.arr = list(map(int, input().split()))
        if self.arr.count(-1) != 1:
            return False
        return True

    def check(self, add, sub):
        v = self.arr[:]
        idx = v.index(-1)
        diff = sub(v[idx + 2], v[idx + 1]) if idx < 2 else sub(v[idx - 1], v[idx - 2])
        if idx < 2:
            v[idx] = sub(v[idx + 1], diff)
        else:
            v[idx] = add(v[idx - 1], diff)
        ret = v[idx]
        if ret <= 0 or ret > 10000:
            return -1
        for i in range(1, 4):
            if v[i] != add(v[i - 1], diff):
                return -1
        return ret

    def sol(self):
        return max(
            self.check(lambda x, y: x + y, lambda x, y: x - y),
            self.check(lambda x, y: x * y, lambda x, y: x // y if y != 0 else 0)
        )


info = Info()
while info.read():
    print(info.sol())
