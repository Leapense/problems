import sys

def run(nums):
    if len(nums) <= 1:
        return 1  # Early return for sequences of length 1

    # Compute the common difference from the last two elements
    diff = nums[-1] - nums[-2]

    # Traverse the sequence from the end to find where the pattern breaks
    for i in range(len(nums) - 1, 0, -1):
        if nums[i - 1] + diff != nums[i]:
            return i + 1  # 1-based index

    return 1  # If no break in pattern, return the start of the sequence

try:
    while True:
        n = int(input())  # Read the size of the sequence (though we're not using it directly)
        input_line = input()  # Read the actual sequence
        nums = list(map(int, input_line.split()))
        print(run(nums))  # Print the result for this line
except EOFError:
    pass  # Exit gracefully on end-of-file

