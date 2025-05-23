def generate_star_patterns(n):
    for k in range(1, n + 1):
        num_stars = k * k
        if num_stars <= 100:
            print('*' * num_stars)
        else:
            print('*' * 100 + '...')

n = int(input().strip())
generate_star_patterns(n)