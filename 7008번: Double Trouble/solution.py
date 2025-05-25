import sys

def solve_test_case():
    n_str = sys.stdin.readline().strip()
    if not n_str:
        return
    
    n = int(n_str)

    ciphertext_segments = []
    chars_read_count = 0
    while chars_read_count < n:
        line_content = sys.stdin.readline().strip()
        parts_on_line = [part for part in line_content.split(' ') if part]
        for segment in parts_on_line:
            ciphertext_segments.append(segment)
            chars_read_count += len(segment)

    full_ciphertext = "".join(ciphertext_segments)
    crib_word = sys.stdin.readline().strip()

    for s_val in range(1, 26):
        for m_val in range(5, 21):
            intermediate_candidate_parts = []
            current_idx = 0
            while current_idx < n:
                chunk_end_idx = min(current_idx + m_val, n)
                original_chunk = full_ciphertext[current_idx:chunk_end_idx]
                reversed_chunk = original_chunk[::-1]
                intermediate_candidate_parts.append(reversed_chunk)
                current_idx += m_val
            
            intermediate_text = "".join(intermediate_candidate_parts)
            modified_plaintext_chars = []
            for char_cipher in intermediate_text:
                char_val_A_based = ord(char_cipher) - ord('A')
                unshifted_char_code_A_based = (char_val_A_based - s_val + 26) % 26
                modified_plaintext_chars.append(chr(unshifted_char_code_A_based + ord('A')))

            potential_modified_plaintext = "".join(modified_plaintext_chars)

            if crib_word in potential_modified_plaintext:
                sys.stdout.write(f"{s_val} {m_val}\n")
                return
            
    sys.stdout.write("Crib is not encrypted.\n")

num_total_test_cases_str = sys.stdin.readline().strip()
if num_total_test_cases_str:
    num_total_test_cases = int(num_total_test_cases_str)
    for _ in range(num_total_test_cases):
        solve_test_case()

