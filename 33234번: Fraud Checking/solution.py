def main():
    n = int(input())
    code1_lines_str = [input() for _ in range(n)]
    code2_lines_str = [input() for _ in range(n)]

    code1_tokenized = []
    for line_str in code1_lines_str:
        code1_tokenized.append(line_str.split())
    
    code2_tokenized = []
    for line_str in code2_lines_str:
        code2_tokenized.append(line_str.split())

    map_c1_to_c2 = {}
    map_c2_to_c1 = {}
    is_similar = True

    for i in range(n):
        words_c1 = code1_tokenized[i]
        words_c2 = code2_tokenized[i]

        if len(words_c1) != len(words_c2):
            is_similar = False
            break

        for j in range(len(words_c1)):
            word1 = words_c1[j]
            word2 = words_c2[j]

            if word1 in map_c1_to_c2:
                if map_c1_to_c2[word1] != word2:
                    is_similar = False
                    break
            elif word2 in map_c2_to_c1:
                if map_c2_to_c1[word2] != word1:
                    is_similar = False
                    break
            else:
                map_c1_to_c2[word1] = word2
                map_c2_to_c1[word2] = word1

        if not is_similar:
            break

    if not is_similar:
        print("-1")
    else:
        replacements_to_report = []
        for original_word, new_word in map_c1_to_c2.items():
            if original_word != new_word:
                replacements_to_report.append((original_word, new_word))
        replacements_to_report.sort()

        print(len(replacements_to_report))
        for r_orig, r_new in replacements_to_report:
            print(f"{r_orig} {r_new}")

if __name__ == "__main__":
    main() 