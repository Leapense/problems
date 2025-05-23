import sys

def find_birthday(N, names):
    answers = []
    
    for name in names:
        print(f"? {name}")
        sys.stdout.flush()
        answer = int(input().strip())
        answers.append((name, answer))
    
    for name, first_answer in answers:
        print(f"? {name}")
        sys.stdout.flush()
        second_answer = int(input().strip())
        
        if first_answer != second_answer:
            # If the first answer and second answer are different, we suspect this is the person
            # because the interactor might have lied.
            print(f"! {name}")
            sys.stdout.flush()
            return
    
    # If we don't detect any inconsistency, return the first person with an answer of 1
    for name, first_answer in answers:
        if first_answer == 1:
            print(f"! {name}")
            sys.stdout.flush()
            return

if __name__ == "__main__":
    N = int(input().strip())
    names = []
    for _ in range(N):
        names.append(input().strip())
    
    find_birthday(N, names)
