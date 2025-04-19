# Testmain.py
import importlib
import sys
from io import StringIO
import textwrap

def run_io(user_input: str, module_name: str = "main") -> str:
    """
    user_input : 프로그램 stdin 으로 줄 문자열
    module_name: 솔루션 파일 이름(확장자 .py 제외), 기본 "main"
    """
    orig_stdin, orig_stdout = sys.stdin, sys.stdout
    sys.stdin, sys.stdout = StringIO(user_input), StringIO()
    try:
        # 이미 import 되었으면 reload
        if module_name in sys.modules:
            mod = importlib.reload(sys.modules[module_name])
        else:
            mod = importlib.import_module(module_name)
        # import 후 main()이 정의돼 있으면 실행
        if hasattr(mod, "main"):
            mod.main()
        output = sys.stdout.getvalue()
    finally:
        sys.stdin, sys.stdout = orig_stdin, orig_stdout
    return output

def test_sample():
    inp = textwrap.dedent("""\
        8
        7
        2
        1
        8
        4
        3
        5
        6
    """)
    expected = "17\n"
    assert run_io(inp) == expected

