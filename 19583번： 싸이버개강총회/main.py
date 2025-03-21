import unittest
import io
import sys
from contextlib import redirect_stdout

def run_io_fun(input_data, func):
    stdin_backup = sys.stdin
    sys.stdin = io.StringIO(input_data)
    output = io.StringIO()
    with redirect_stdout(output):
        func()
    sys.stdin = stdin_backup
    return output.getvalue().strip()

class TestSolution(unittest.TestCase):
    def test_sample_input_1(self):
        input_data = """22:00 23:00 23:30
21:30 malkoring
21:33 tolelom
21:34 minjae705
21:35 hhan14
21:36 dicohy27
21:40 906bc
23:00 906bc
23:01 tolelom
23:10 minjae705
23:11 hhan14
23:20 dicohy27
"""
        expected_output = "5"
        result = run_io_fun(input_data, main)
        self.assertEqual(result, expected_output)

    def test_sample_input_2(self):
        input_data = """06:00 12:00 18:00
06:00 shinyo17
06:00 kimchist
06:00 swoon
06:00 kheee512
06:00 Green55
09:00 kimchist
11:59 shinyo17
12:00 kimchist
17:59 swoon
17:59 swoon
18:00 kheee512
18:01 swoon
18:01 Green55
18:01 kheee512
18:01 swoon
18:21 jinius36
18:40 jeongyun1206
"""
        expected_output = "3"
        result = run_io_fun(input_data, main)
        self.assertEqual(result, expected_output)

    def test_no_exit_records(self):
        input_data = """10:00 11:00 12:00
        09:30 user1
        09:45 user2
        10:00 user3
"""
        expected_output = "0"
        result = run_io_fun(input_data, main)
        self.assertEqual(result, expected_output)
    
    def test_all_users_present(self):
        input_data = """08:00 09:00 10:00
07:50 alice
07:55 bob
08:00 charlie
09:00 alice
09:30 bob
10:00 charlie
"""
        expected_output = "3"
        result = run_io_fun(input_data, main)
        self.assertEqual(result, expected_output)

    def test_edge_case_boundaries(self):
        input_data = """12:00 13:00 14:00
12:00 userA
11:59 userB
13:00 userA
14:00 userA
13:00 userC
14:00 userC
"""
        expected_output = "2"
        result = run_io_fun(input_data, main)
        self.assertEqual(result, expected_output)

def time_to_minutes(time_str):
    hours, minutes = map(int, time_str.split(':'))
    return hours * 60 + minutes

def main():
    input_data = sys.stdin.read().strip().splitlines()
    if not input_data:
        return
    
    S, E, Q = input_data[0].split()
    S = time_to_minutes(S)
    E = time_to_minutes(E)
    Q = time_to_minutes(Q)

    entered = set()
    exited = set()

    for line in input_data[1:]:
        time_str, nickname = line.split()
        t = time_to_minutes(time_str)
        if t <= S:
            entered.add(nickname)

        if E <= t <= Q:
            exited.add(nickname)

    result = len(entered & exited)
    print(result)

if __name__ == '__main__':
    unittest.main()