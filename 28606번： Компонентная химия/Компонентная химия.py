import sys
def main():
    def input():
        return sys.stdin.read()

    data = sys.stdin.read().split()
    ptr = 0
    n = int(data[ptr]); ptr +=1
    e = int(data[ptr]); ptr +=1

    cnt = {}
    total_pairs = 0
    res = []

    for _ in range(n):
        t_i = int(data[ptr]); ptr +=1
        a_i = int(data[ptr]); ptr +=1
        r = a_i % e
        s = (e - r) % e

        if t_i ==1:
            if s != r:
                total_pairs += cnt.get(s,0)
            else:
                total_pairs += cnt.get(r,0)
            cnt[r] = cnt.get(r,0) +1
        elif t_i ==2:
            if s != r:
                total_pairs -= cnt.get(s,0)
            else:
                current_cnt_r = cnt.get(r,0)
                total_pairs -= (current_cnt_r -1)
            cnt[r] = cnt.get(r,0) -1
            if cnt[r] ==0:
                del cnt[r]
        res.append(str(total_pairs))
    print('\n'.join(res))

if __name__ == "__main__":
    main()