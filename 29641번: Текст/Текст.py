def wrap_text(k, text):
    words = text.split()
    lines = []
    current_line = ""

    for word in words:
        if len(current_line) + len(word) + (1 if current_line else 0) <= k:
            if current_line:
                current_line += " " + word
            else:
                current_line = word
        else:
            lines.append(current_line)
            current_line = word
        
    if current_line:
        lines.append(current_line)

    return "\n".join(lines)

k = int(input())
text = input().strip()

result = wrap_text(k, text)
print(result)