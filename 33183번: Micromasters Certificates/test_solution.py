import pytest
import subprocess
import sys

# Helper function to run the solution with input
def run_solution(input_string):
    process = subprocess.Popen([sys.executable, 'solution.py'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate(input_string)
    if stderr:
        print("Error:", stderr)
    return stdout.strip()

# Sample Test Case 1
sample_input_1 = """
+-------------------------------------------------+
|  +-------------------+                          |
|  |Algorithm Design   |   +-------------------+  |
|  |  Programming      |   |PROGRAMMING        |  |
|  |Discrete Structures|   |   Web Prgramming  |  |
|  |   Data Structures |   |                   |  |
|  +-------------------+   | DatabaseDesign    |  |
|                          |Software Test      |  |
|     +--------------+     |     Patterns      |  |
|     |    Python    |     +-------------------+  |
|     +--------------+                            |
|          +------------------------+             |
|          |Programming             |             |
|          |          AI            |             |
|          |    Algorithm     design|             |
|          |Database Design         |             |
|          +------------------------+             |
+-------------------------------------------------+
"""

def test_sample_1():
    assert run_solution(sample_input_1) == "7"

# Additional Test Case: Different courses, some overlap
sample_input_2 = """
+-------+   +-------+   +-------+   +-------+
| A     |   | B     |   | C     |   | A     |
| B     |   | C     |   | D     |   | D     |
+-------+   +-------+   +-------+   +-------+
"""

def test_sample_2():
    # M1: {A, B}
    # M2: {B, C}
    # M3: {C, D}
    # M4: {A, D}
    # Combinations of 3:
    # (M1, M2, M3): {A, B} | {B, C} | {C, D} = {A, B, C, D} -> size 4
    # (M1, M2, M4): {A, B} | {B, C} | {A, D} = {A, B, C, D} -> size 4
    # (M1, M3, M4): {A, B} | {C, D} | {A, D} = {A, B, C, D} -> size 4
    # (M2, M3, M4): {B, C} | {C, D} | {A, D} = {A, B, C, D} -> size 4
    # Minimum is 4
    assert run_solution(sample_input_2) == "4"

# Additional Test Case: Courses with spaces and different cases
sample_input_3 = """
+-----------------+   +-----------------+   +-----------------+
| course one      |   | Course Two      |   | COURSE ONE      |
| Course Two      |   | Course Three    |   | Course Four     |
+-----------------+   +-----------------+   +-----------------+
"""

def test_sample_3():
    # M1: {"courseone", "coursetwo"}
    # M2: {"coursetwo", "coursethree"}
    # M3: {"courseone", "coursefour"}
    # Combination (M1, M2, M3): {"courseone", "coursetwo"} | {"coursetwo", "coursethree"} | {"courseone", "coursefour"}
    # Union: {"courseone", "coursetwo", "coursethree", "coursefour"}
    # Size: 4
    assert run_solution(sample_input_3) == "4"

# Additional Test Case: Larger number of boxes, some shared courses
sample_input_4 = """
+---+ +---+ +---+ +---+ +---+
| A | | B | | C | | A | | D |
| B | | C | | D | | C | | E |
+---+ +---+ +---+ +---+ +---+
"""

def test_sample_4():
    # M1: {A, B}
    # M2: {B, C}
    # M3: {C, D}
    # M4: {A, C}
    # M5: {D, E}
    # Combinations of 3:
    # (M1, M2, M3): {A,B}|{B,C}|{C,D} = {A,B,C,D} size 4
    # (M1, M2, M4): {A,B}|{B,C}|{A,C} = {A,B,C} size 3
    # (M1, M2, M5): {A,B}|{B,C}|{D,E} = {A,B,C,D,E} size 5
    # (M1, M3, M4): {A,B}|{C,D}|{A,C} = {A,B,C,D} size 4
    # (M1, M3, M5): {A,B}|{C,D}|{D,E} = {A,B,C,D,E} size 5
    # (M1, M4, M5): {A,B}|{A,C}|{D,E} = {A,B,C,D,E} size 5
    # (M2, M3, M4): {B,C}|{C,D}|{A,C} = {A,B,C,D} size 4
    # (M2, M3, M5): {B,C}|{C,D}|{D,E} = {B,C,D,E} size 4
    # (M2, M4, M5): {B,C}|{A,C}|{D,E} = {A,B,C,D,E} size 5
    # (M3, M4, M5): {C,D}|{A,C}|{D,E} = {A,C,D,E} size 4
    # Minimum is 3
    assert run_solution(sample_input_4) == "3"

# Additional Test Case: Empty lines inside boxes
sample_input_5 = """
+-------+   +-------+   +-------+
| A     |   | B     |   | C     |
|       |   |       |   |       |
| B     |   | C     |   | D     |
+-------+   +-------+   +-------+
"""

def test_sample_5():
    # M1: {A, B}
    # M2: {B, C}
    # M3: {C, D}
    # (M1, M2, M3): {A,B}|{B,C}|{C,D} = {A,B,C,D} size 4
    assert run_solution(sample_input_5) == "4"

# Additional Test Case: Box right at the edge
sample_input_6 = """
+---+
| A |
| B |
+---+
+---+
| C |
| D |
+---+
+---+
| E |
| F |
+---+
"""

def test_sample_6():
    # M1: {A, B}
    # M2: {C, D}
    # M3: {E, F}
    # (M1, M2, M3): {A,B}|{C,D}|{E,F} = {A,B,C,D,E,F} size 6
    assert run_solution(sample_input_6) == "6"