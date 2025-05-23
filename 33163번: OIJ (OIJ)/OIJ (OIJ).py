def transform_string():
    N = int(input().strip())
    S = input().strip()

    transformation = {
        'J' : 'O',
        'O' : 'I',
        'I' : 'J'
    }

    result = ''.join(transformation[char] for char in S)
    print(result)

if __name__ == '__main__':
    transform_string()