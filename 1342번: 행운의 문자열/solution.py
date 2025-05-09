import collections
import functools

def calculate_lucky_strings(s_str: str) -> int:
    initial_char_counts = collections.Counter(s_str)
    counts_list_for_tuple = [0] * 26
    for i in range(26):
        char = chr(ord('a') + i)
        if char in initial_char_counts:
            counts_list_for_tuple[i] = initial_char_counts[char]
    
    initial_counts_tuple = tuple(counts_list_for_tuple)

    @functools.lru_cache(maxsize=None)
    def count_recursive(last_char_idx : int, current_char_counts_tuple : tuple) -> int:
        if sum(current_char_counts_tuple) == 0:
            return 1
        
        total_found = 0

        for current_char_idx in range(26):
            if current_char_idx == last_char_idx:
                continue

            if current_char_counts_tuple[current_char_idx] > 0:
                temp_counts_list = list(current_char_counts_tuple)
                temp_counts_list[current_char_idx] -= 1
                next_counts_tuple = tuple(temp_counts_list)

                total_found += count_recursive(
                    current_char_idx,
                    next_counts_tuple
                )

        return total_found
    
    result = count_recursive(-1, initial_counts_tuple)
    return result

def main():
    s_input = input()
    print(calculate_lucky_strings(s_input))

if __name__ == "__main__":
    main()