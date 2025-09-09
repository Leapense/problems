import sys
from math import gcd, isqrt

def divisors(n: int):
    d = set()
    for a in range(1, isqrt(n) + 1):
        if n % a == 0:
            d.add(a)
            d.add(n // a)
    return d

class State:
    __slots__ = ("sA", "sB", "GA", "GB", "FA", "FB", "S_num", "S_onlyA", "S_onlyB", "saw_both")
    def __init__(self, sA=None, sB=None, GA=0, GB=0, FA=None, FB=None, S_num=None, S_onlyA=None, S_onlyB=None, saw_both=False):
        self.sA = sA
        self.sB = sB
        self.GA = GA
        self.GB = GB
        self.FA = set() if FA is None else set(FA)
        self.FB = set() if FB is None else set(FB)
        self.S_num = set() if S_num is None else set(S_num)
        self.S_onlyA = set() if S_onlyA is None else set(S_onlyA)
        self.S_onlyB = set() if S_onlyB is None else set(S_onlyB)
        self.saw_both = saw_both

    def clone(self):
        return State(self.sA, self.sB, self.GA, self.GB, self.FA, self.FB, self.S_num, self.S_onlyA, self.S_onlyB, self.saw_both)

    def candidate_divs(self, G, F):
        if G == 0:
            return None
        return [d for d in divisors(G) if all(j % d != 0 for j in F)]

    def feasible(self) -> bool:
        DA = self.candidate_divs(self.GA, self.FA)
        DB = self.candidate_divs(self.GB, self.FB)
        if self.GA > 0 and not DA:
            return False
        if self.GB > 0 and not DB:
            return False
        if self.GA > 0 and self.GB > 0:
            for a in DA:
                for b in DB:
                    if a != b and (not self.saw_both or a < b):
                        return True
            return False
        return True

def step(states, i, token):
    next_states = []
    is_num = False

    if token.isdigit():
        val = int(token)
        if str(val) == token and val == i:
            is_num = True
        else:
            return []
    elif token.isalpha():
        L = len(token)
        if L == 4:
            typ = 'single'
            x = token
        elif L == 8:
            typ = 'both'
            u, v = token[:4], token[4:]
        else:
            return []
    else:
        return []

    if is_num:
        for st in states:
            ns = st.clone()
            ns.S_num.add(i)
            if ns.GA > 0:
                ns.FA.add(i)
            if ns.GB > 0:
                ns.FB.add(i)
            if ns.feasible():
                next_states.append(ns)
        return next_states

    if typ == 'single':
        for st in states:
            if st.sA is None or st.sA == x:
                ns = st.clone()
                if ns.sA is None:
                    ns.sA = x
                    ns.GA = i
                    ns.FA = set(ns.S_num) | set(ns.S_onlyB)
                else:
                    ns.GA = gcd(ns.GA, i)
                if ns.GB > 0:
                    ns.FB.add(i)
                ns.S_onlyA.add(i)
                if ns.feasible():
                    next_states.append(ns)

            if st.sB is None or st.sB == x:
                ns = st.clone()
                if ns.sB is None:
                    ns.sB = x
                    ns.GB = i
                    ns.FB = set(ns.S_num) | set(ns.S_onlyA)
                else:
                    ns.GB = gcd(ns.GB, i)
                if ns.GA > 0:
                    ns.FA.add(i)
                ns.S_onlyB.add(i)
                if ns.feasible():
                    next_states.append(ns)

        uniq = {}
        for st in next_states:
            key = (st.sA, st.sB, st.GA, st.GB, 
                   tuple(sorted(st.FA)), tuple(sorted(st.FB)),
                   tuple(sorted(st.S_num)), tuple(sorted(st.S_onlyA)),
                   tuple(sorted(st.S_onlyB)), st.saw_both)
            uniq[key] = st
        return list(uniq.values())

    for st in states:
        if (st.sA is None or st.sA == u) and (st.sB is None or st.sB == v):
            ns = st.clone()
            if ns.sA is None:
                ns.sA = u
                ns.FA = set(ns.S_num) | set(ns.S_onlyB)
            if ns.sB is None:
                ns.sB = v
                ns.FB = set(ns.S_num) | set(ns.S_onlyA)
            ns.GA = ns.GA if ns.GA > 0 else i
            ns.GB = ns.GB if ns.GB > 0 else i
            ns.GA = gcd(ns.GA, i)
            ns.GB = gcd(ns.GB, i)
            ns.saw_both = True
            if ns.feasible():
                next_states.append(ns)
    
    uniq = {}
    for st in next_states:
        key = (st.sA, st.sB, st.GA, st.GB,
               tuple(sorted(st.FA)), tuple(sorted(st.FB)),
               tuple(sorted(st.S_num)), tuple(sorted(st.S_onlyA)),
               tuple(sorted(st.S_onlyB)), st.saw_both)
        uniq[key] = st

    return list(uniq.values())

def solve_case(tokens):
    states = [State()]
    for idx, tok in enumerate(tokens, start=1):
        states = step(states, idx, tok)
        if not states:
            return idx - 1
    return len(tokens)

def read_input():
    data = sys.stdin.read().strip("\n").splitlines()
    it = iter(data)
    def next_nonempty():
        for line in it:
            if line.strip():
                return line.strip()
        return None

    t_line = next_nonempty()
    if t_line is None:
        return []

    t = int(t_line)
    cases = []
    for _ in range(t):
        n_line = next_nonempty()
        while n_line is None or not n_line.isdigit():
            if n_line is None:
                break
            n_line = next_nonempty()
        if n_line is None:
            break
        n = int(n_line)
        seq_line = next_nonempty()
        tokens = seq_line.split() if seq_line else []

        while len(tokens) < n:
            extra = next_nonempty()
            if extra is None:
                break

            tokens += extra.split()
        cases.append(tokens[:n])
    return cases

def main():
    cases = read_input()
    out = []
    for tokens in cases:
        out.append(str(solve_case(tokens)))
    print("\n".join(out))

if __name__ == "__main__":
    main()
