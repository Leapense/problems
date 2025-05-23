def classify_respondent(answer):
    if 'blue' in answer and 'black' in answer:
        return 'Earthling'
    elif 'white' in answer and 'gold' in answer:
        return 'Aboriginal'
    else:
        return 'Other'

def calculate_percentage(count, total):
    return count / total * 100

# Read the number of respondents
N = int(input())

# Initialize counters
earthlings_count = 0
aboriginals_count = 0
others_count = 0

# Process each respondent's answer
for _ in range(N):
    answer = input().lower()  # Convert to lowercase for case-insensitive comparison
    respondent_type = classify_respondent(answer)
    if respondent_type == 'Earthling':
        earthlings_count += 1
    elif respondent_type == 'Aboriginal':
        aboriginals_count += 1
    else:
        others_count += 1

# Calculate percentages
earthlings_percentage = calculate_percentage(earthlings_count, N)
aboriginals_percentage = calculate_percentage(aboriginals_count, N)
others_percentage = calculate_percentage(others_count, N)

# Output the percentages
print(f"{earthlings_percentage:.10f}")
print(f"{aboriginals_percentage:.10f}")
print(f"{others_percentage:.10f}")