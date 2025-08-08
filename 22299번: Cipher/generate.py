import argparse
import random
import string
import sys
from typing import List, Set, Tuple

ALPHABET = string.ascii_lowercase
MAX_MSG_LEN = 1000
WORD_MIN = 1
WORD_MAX = 20

def is_letter(ch: str) -> bool:
    return ('A' <= ch <= 'Z') or ('a' <= ch <= 'z')

def shift_char(c: str, s: int, forward: bool) -> str:
    if 'A' <= c <= 'Z':
        base = ord('A')
        idx = ord(c) - base
        idx = (idx + s) % 26 if forward else (idx - s) % 26
        return chr(base + idx)
    if 'a' <= c <= 'z':
        base = ord('a')
        idx = ord(c) - base
        idx = (idx + s) % 26 if forward else (idx - s) % 26
        return chr(base + idx)
    return c

def caesar_encrypt(text: str, shift: int) -> str:
    return ''.join(shift_char(c, shift, True) for c in text)

def caesar_decrypt(text: str, shift: int) -> str:
    return ''.join(shift_char(c, shift, False) for c in text)

def tokenize_scored(plain: str, good: Set[str], bad: Set[str]) -> Tuple[int, int, int]:
    i = 0
    n = len(plain)
    total = 0
    matches = 0
    threats = 0
    while i < n:
        if is_letter(plain[i]):
            j = i
            while j < n and is_letter(plain[j]):
                j += 1
            length = j - i
            if 1 <= length <= 20:
                word = plain[i:j].lower()
                in_bad = word in bad
                in_good = word in good
                if in_bad or in_good:
                    matches += 1
                if in_bad:
                    threats += 1
                total += 1
            i = j
        else:
            i += 1
    return matches, threats, total

def unique_best_shift(cipher: str, good: Set[str], bad: Set[str], desired_shift: int) -> bool:
    best = -1
    ties = 0
    winner = -1
    for s in range(26):
        plain = caesar_decrypt(cipher, s)
        m, _, _ = tokenize_scored(plain, good, bad)
        if m > best:
            best = m
            ties = 1
            winner = s
        elif m == best:
            ties += 1
    return ties == 1 and winner == desired_shift

def random_word(rng: random.Random, length: int) -> str:
    return ''.join(rng.choice(ALPHABET) for _ in range(length))

def generate_unique_words(rng: random.Random, count: int, min_len: int, max_len: int, avoid: Set[str]) -> List[str]:
    words: Set[str] = set()
    while len(words) < count:
        length = rng.randint(min_len, max_len)
        w = random_word(rng, length)
        if w not in avoid and w not in words:
            words.add(w)
    return list(words)

def capitalize_mix(rng: random.Random, w: str) -> str:
    chars = []
    for ch in w:
        if rng.random() < 0.3:
            chars.append(ch.upper())
        else:
            chars.append(ch)
    return ''.join(chars)

def pad_to_exact_length(rng: random.Random, s: str, target_len: int) -> str:
    if len(s) > target_len:
        s2 = s[:target_len]
        while len(s2) > 0 and s2[-1] == ' ':
            s2 = s2[:-1]
        if not s2:
            s2 = '.'
        return s2
    if len(s) < target_len:
        pool = "0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?"
        need = target_len - len(s)
        filler = ''.join(rng.choice(pool) for _ in range(need))
        out = s + filler
        if out[-1] == ' ':
            out = out[:-1] + '.'
        return out
    if s[-1] == ' ':
        return s[:-1] + '.'
    return s

def build_case_minimal(rng: random.Random) -> Tuple[List[str], List[str], str]:
    good = ['a']
    bad = ['z']
    shift = 0
    plaintext = 'A'
    ciphertext = caesar_encrypt(plaintext, shift)
    return good, bad, ciphertext

def build_case_maximal_length(rng: random.Random) -> Tuple[List[str], List[str], str]:
    good = generate_unique_words(rng, 50, 3, 10, set())
    bad = generate_unique_words(rng, 50, 3, 10, set(good))
    tokens: List[str] = []
    pool = good + bad
    non_dict = generate_unique_words(rng, 200, 3, 10, set(pool))
    while len(' '.join(tokens)) < 920:
        choice_pool = pool if rng.random() < 0.6 else non_dict
        w = rng.choice(choice_pool)
        w = capitalize_mix(rng, w)
        tokens.append(w)
        if rng.random() < 0.35:
            tokens.append(rng.choice([',', '.', '!', '?', ';', ':']))
    plaintext = ' '.join(tokens).strip()
    if not plaintext:
        plaintext = rng.choice(pool)
    shift = 25
    cipher = caesar_encrypt(plaintext, shift)
    if not unique_best_shift(cipher, set(good), set(bad), shift):
        booster = rng.choice(pool)
        while len(plaintext) + 1 + len(booster) < MAX_MSG_LEN and not unique_best_shift(cipher, set(good), set(bad), shift):
            plaintext = f"{plaintext} {capitalize_mix(rng, booster)}"
            cipher = caesar_encrypt(plaintext, shift)
    cipher = pad_to_exact_length(rng, cipher, MAX_MSG_LEN)
    return good, bad, cipher

def build_case_tie_punct_only(rng: random.Random) -> Tuple[List[str], List[str], str]:
    g = generate_unique_words(rng, 10, 3, 8, set())
    b = generate_unique_words(rng, 10, 3, 8, set(g))
    pool = "0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?"
    length = rng.randint(40, 80)
    plaintext = ''.join(rng.choice(pool) for _ in range(length))
    shift = rng.randint(0, 25)
    ciphertext = caesar_encrypt(plaintext, shift)
    return g, b, ciphertext

def build_case_rounding_13pct(rng: random.Random) -> Tuple[List[str], List[str], str]:
    good = ['safe']
    bad = ['danger']
    fillers: List[str] = []
    while len(fillers) < 7:
        length = rng.choice([5, 7, 8, 9, 11])
        w = random_word(rng, length)
        if w not in good and w not in bad:
            fillers.append(w)
    tokens = []
    idx = rng.randint(0, 7)
    for i in range(8):
        if i == idx:
            tokens.append(capitalize_mix(rng, 'danger'))
        else:
            tokens.append(capitalize_mix(rng, fillers.pop()))
        if i != 7 and rng.random() < 0.4:
            tokens.append(rng.choice([',', ';', ':']))
    plaintext = ' '.join(tokens)
    shift = 13
    ciphertext = caesar_encrypt(plaintext, shift)
    return good, bad, ciphertext

def build_case_word_length_boundary(rng: random.Random) -> Tuple[List[str], List[str], str]:
    w20 = random_word(rng, 20)
    good_pool = {w20}
    while len(good_pool) < 5:
        good_pool.add(random_word(rng, rng.randint(3, 8)))
    good = list(good_pool)
    bad_pool: Set[str] = set()
    while len(bad_pool) < 5:
        candidate = random_word(rng, rng.randint(3, 8))
        if candidate not in good_pool:
            bad_pool.add(candidate)
    bad = list(bad_pool)
    long21a = random_word(rng, 21)
    long21b = random_word(rng, 21)
    w19 = random_word(rng, 19)
    w20_non = random_word(rng, 20)
    tokens = [capitalize_mix(rng, long21a), capitalize_mix(rng, w20), capitalize_mix(rng, long21b), capitalize_mix(rng, w19), capitalize_mix(rng, w20_non)]
    puncts = ['.', ',', '!', '?', ';', ':']
    plaintext = ''
    for t in tokens:
        if plaintext:
            plaintext += ' '
        plaintext += t
        if rng.random() < 0.5:
            plaintext += rng.choice(puncts)
    shift = 7
    ciphertext = caesar_encrypt(plaintext, shift)
    return good, bad, ciphertext

def build_case_half_rounding(rng: random.Random) -> Tuple[List[str], List[str], str]:
    good = ['alpha', 'beta']
    bad = ['omega']
    tokens = [capitalize_mix(rng, 'alpha'), capitalize_mix(rng, random_word(rng, 6))]
    if rng.random() < 0.5:
        tokens.insert(1, ',')
    plaintext = ' '.join(tokens)
    shift = 5
    ciphertext = caesar_encrypt(plaintext, shift)
    return good, bad, ciphertext

def build_random_case(rng: random.Random) -> Tuple[List[str], List[str], str]:
    g_count = rng.randint(1, 50)
    b_count = rng.randint(1, 50)
    good = generate_unique_words(rng, g_count, 1, 20, set())
    bad = generate_unique_words(rng, b_count, 1, 20, set(good))
    words_pool = good + bad
    non_dict = generate_unique_words(rng, rng.randint(10, 100), 1, 20, set(words_pool))
    total_tokens = rng.randint(5, 60)
    tokens: List[str] = []
    for _ in range(total_tokens):
        source = words_pool if rng.random() < 0.5 else non_dict
        tokens.append(capitalize_mix(rng, rng.choice(source)))
        if rng.random() < 0.3:
            tokens.append(rng.choice([',', '.', '!', '?', ';', ':']))
    plaintext = ' '.join(tokens).strip()
    if not plaintext:
        plaintext = rng.choice(words_pool)
    shift = rng.randint(0, 25)
    ciphertext = caesar_encrypt(plaintext, shift)
    tries = 0
    while not unique_best_shift(ciphertext, set(good), set(bad), shift) and tries < 10 and len(plaintext) < MAX_MSG_LEN - 10:
        booster = capitalize_mix(rng, rng.choice(words_pool))
        plaintext = f"{plaintext} {booster}"
        ciphertext = caesar_encrypt(plaintext, shift)
        tries += 1
    if len(ciphertext) > MAX_MSG_LEN:
        ciphertext = ciphertext[:MAX_MSG_LEN]
        if ciphertext[-1] == ' ':
            ciphertext = ciphertext[:-1] + '.'
    return good, bad, ciphertext

def build_boundary_suite(rng: random.Random) -> List[Tuple[List[str], List[str], str]]:
    cases = [
        build_case_minimal(rng),
        build_case_maximal_length(rng),
        build_case_tie_punct_only(rng),
        build_case_rounding_13pct(rng),
        build_case_word_length_boundary(rng),
        build_case_half_rounding(rng)
    ]
    return cases

def print_cases(cases: List[Tuple[List[str], List[str], str]]) -> None:
    print(len(cases))
    for good, bad, cipher in cases:
        print(len(good))
        for w in good:
            print(w)
        print(len(bad))
        for w in bad:
            print(w)
        line = cipher.strip()
        if not line:
            line = '.'
        print(line)

def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('--mode', choices=['boundary', 'random'], default='boundary')
    parser.add_argument('--cases', type=int, default=None)
    parser.add_argument('--seed', type=int, default=None)
    args = parser.parse_args()
    rng = random.Random(args.seed)
    if args.mode == 'boundary':
        base_cases = build_boundary_suite(rng)
        if args.cases is None:
            print_cases(base_cases)
            return
        count = max(1, min(50, args.cases))
        out_cases = base_cases[:count]
        while len(out_cases) < count:
            out_cases.append(build_random_case(rng))
        print_cases(out_cases)
        return
    if args.mode == 'random':
        count = args.cases if args.cases is not None else 10
        count = max(1, min(50, count))
        cases = [build_random_case(rng) for _ in range(count)]
        print_cases(cases)
        return

if __name__ == '__main__':
    main()