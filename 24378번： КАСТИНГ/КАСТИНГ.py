def casting(type_query, n, a, b, c):
    if type_query == 2:
        # Maximum number of actors who can be tall, blue-eyed and blonde is the minimum of the counts a, b, c
        return min(a, b, c)
    elif type_query == 1:
        # Calculate the minimum number of actors who must be tall, blue-eyed and blonde
        sum_categories = a + b + c
        # The minimum overlap is the amount over 2n because any more than 2n must necessarily overlap in at least n + 1 places.
        overlap = sum_categories - 2 * n
        # There can't be fewer than zero actors who meet all criteria
        minimum_required = max(0, overlap)
        return minimum_required

type_query = int(input())
n, a, b, c = map(int, input().split())
print(casting(type_query, n, a, b, c))