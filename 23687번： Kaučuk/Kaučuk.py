# Read the number of commands
n = int(input())

# Initialize counters for sections, subsections, and subsubsections
section_count = 0
subsection_count = 0
subsubsection_count = 0

# Process each command
for _ in range(n):
    command, title = input().split()
    
    if command == "section":
        section_count += 1
        subsection_count = 0
        subsubsection_count = 0
        print(f"{section_count} {title}")
    
    elif command == "subsection":
        subsection_count += 1
        subsubsection_count = 0
        print(f"{section_count}.{subsection_count} {title}")
    
    elif command == "subsubsection":
        subsubsection_count += 1
        print(f"{section_count}.{subsection_count}.{subsubsection_count} {title}")