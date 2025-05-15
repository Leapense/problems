def parse_term(term):
    import re
    # Match unsigned letters at start, then +x or -x blocks
    unsigned = []
    positives = set()
    negatives = set()
    i = 0
    n = len(term)
    # Collect all unsigned letters until '+' or '-'
    while i < n and term[i] not in '+-':
        unsigned.append(term[i])
        i += 1
    # Parse signed parts
    while i < n:
        sign = term[i]
        i += 1
        if i < n:
            if sign == '+':
                positives.add(term[i])
            elif sign == '-':
                negatives.add(term[i])
            i += 1
    return set(unsigned), positives, negatives

def match(word, unsigned, positives, negatives):
    wordset = set(word)
    # At least one unsigned letter in word
    if not (wordset & unsigned):
        return False
    # All positive letters in word
    if not positives.issubset(wordset):
        return False
    # No negative letters in word
    if wordset & negatives:
        return False
    return True

def process_case(words, queries):
    results = []
    words_sorted = sorted(words)
    for query in queries:
        answer = "NONE"
        terms = query.split('|')
        term_parsed = []
        for term in terms:
            unsigned, positives, negatives = parse_term(term)
            term_parsed.append((unsigned, positives, negatives))
        for word in words_sorted:
            for (unsigned, positives, negatives) in term_parsed:
                if match(word, unsigned, positives, negatives):
                    answer = word
                    break
            if answer != "NONE":
                break
        results.append(answer)
    return results

def main():
    import sys
    input_lines = [line.rstrip('\n') for line in sys.stdin]
    idx = 0
    while idx < len(input_lines):
        if input_lines[idx] == '#':
            break
        words = []
        while input_lines[idx] != '*':
            words.append(input_lines[idx])
            idx += 1
        idx += 1  # skip '*'
        queries = []
        while input_lines[idx] != '**':
            queries.append(input_lines[idx])
            idx += 1
        idx += 1  # skip '**'
        results = process_case(words, queries)
        for res in results:
            print(res)
        print('$')

if __name__ == '__main__':
    main()