import sys
import itertools

def main():
    data = sys.stdin.read().split()
    n, m, k = map(int, data[:3])
    quest_skills = [tuple(map(int, data[i:i+k])) for i in range(3, 3 + m * k, k)]
    all_skills = range(1, 2 * n + 1)
    max_completed = 0

    for combo in itertools.combinations(all_skills, n):
        skill_set = set(combo)
        completed = 0
        for skills in quest_skills:
            if skill_set.issuperset(skills):
                completed += 1
        if completed > max_completed:
            max_completed = completed
    
    print(max_completed)

if __name__ == "__main__":
    main()