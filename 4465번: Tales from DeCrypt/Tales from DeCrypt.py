import math

# Function to generate the random number based on linear congruential generator
def r(a, m, s):
    val = s % m / float(m)
    s = (a * s + 1) % m
    return val, s

# Decryption function
def decrypt(a, m, seed, encrypted_text):
    decrypted_text = []
    s = seed

    for line in encrypted_text:
        decrypted_line = []
        for c in line:
            char_code = ord(c)
            if 0x20 <= char_code <= 0x7e:
                # Apply reverse of the encryption formula
                rand, s = r(a, m, s)
                shift = math.ceil(95 - rand * 95)
                decrypted_char = (char_code - 32 - shift) % 95 + 32
                decrypted_line.append(chr(decrypted_char))
            else:
                decrypted_line.append(c)
        decrypted_text.append("".join(decrypted_line))
    
    return "\n".join(decrypted_text)

# Main function to read input and output the result
if __name__ == "__main__":
    # Read the first line with a, m, seed
    a, m, seed = map(int, input().strip().split())
    
    # Read the encrypted text
    encrypted_text = []
    while True:
        try:
            line = input().strip()
            encrypted_text.append(line)
        except EOFError:
            break

    # Decrypt the given text
    decrypted_output = decrypt(a, m, seed, encrypted_text)
    
    # Output the result
    print(decrypted_output)
