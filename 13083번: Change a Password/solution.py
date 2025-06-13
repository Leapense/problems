import itertools

def change_password():
    old_password_str = input()
    n = len(old_password_str)
    old_password_val = int(old_password_str)
    mod = 10 ** n
    digits = "0123456789"

    best_password_str = ""
    max_diff = -1

    for p in itertools.permutations(digits, n):
        candidate_str = "".join(p)
        candidate_val = int(candidate_str)

        abs_diff = abs(old_password_val - candidate_val)
        current_diff = min(abs_diff, mod - abs_diff)

        if current_diff > max_diff:
            max_diff = current_diff
            best_password_str = candidate_str
        elif current_diff == max_diff and candidate_val < int(best_password_str):
            best_password_str = candidate_str

    print(best_password_str)

if __name__ == "__main__":
    change_password()