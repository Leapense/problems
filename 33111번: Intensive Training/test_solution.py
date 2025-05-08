import io
import sys
import pytest
from solution import solve_instance

test_data = [
    ("sample1", "3 4 7\n", "9\n"),
    ("sample2", "2 1 1\n", "0\n"),
    ("sample3", "1 1000000000 1000000000\n", "1000000000000000000\n"),
    ("sample4", "1043 104812 99818\n", "10042762\n"), # 내 계산에 따른 결과
    ("custom1_N_is_1", "1 5 10\n", "50\n"),
    ("custom2_K_is_0", "5 10 0\n", "0\n"),
    ("custom3_R_is_0", "5 0 10\n", "0\n"),
    ("custom4_K_mod_N_is_0", "3 6 9\n", "18\n"), # K=9,N=3 -> k_i=[3,3,3]. R=6,N=3 -> r_i=[2,2,2]. Prod = 3*2*3 = 18
    ("custom5_R_mod_N_is_0", "3 9 6\n", "18\n"), # K=6,N=3 -> k_i=[2,2,2]. R=9,N=3 -> r_i=[3,3,3]. Prod = 2*3*3 = 18
    ("custom6_K_less_than_N", "5 10 3\n", "6\n"), 
    # K=3,N=5 -> k_s=0,k_b=1,num_kb=3. k_seq=[1,1,1,0,0]
    # R=10,N=5 -> r_s=2,r_b=3,num_rb=0. r_seq=[2,2,2,2,2]
    # n_kb_rs = min(3,5) = 3. (1,2)
    # n_kb_rb = 3-3=0
    # n_ks_rs = 5-3=2. (0,2)
    # n_ks_rb = 5-(3+0+2)=0
    # Prod = 3*1*2 + 0 + 2*0*2 + 0 = 6
    ("custom7_R_less_than_N", "5 3 10\n", "6\n"),
    # K=10,N=5 -> k_s=2,k_b=3,num_kb=0. k_seq=[2,2,2,2,2]
    # R=3,N=5 -> r_s=0,r_b=1,num_rb=3. r_seq=[0,0,1,1,1]
    # n_kb_rs = min(0,2)=0
    # n_kb_rb = 0-0=0
    # n_ks_rs = 2-0=2. (2,0)
    # n_ks_rb = 5-(0+0+2)=3. (2,1)
    # Prod = 0 + 0 + 2*2*0 + 3*2*1 = 6
]

@pytest.mark.parametrize("test_id, input_str, expected_output_str", test_data)
def test_solve(test_id, input_str, expected_output_str, monkeypatch, capsys):
    monkeypatch.setattr(sys, 'stdin', io.StringIO(input_str))
    solve_instance()

    captured = capsys.readouterr()
    assert captured.out == expected_output_str

    