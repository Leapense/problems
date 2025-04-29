import io
import textwrap
import sys

from solution import main


def _run_io_test(input_str: str) -> str:
    """Utility: feed *input_str* to stdin, capture and return stdout."""
    stdin_backup, stdout_backup = sys.stdin, sys.stdout
    sys.stdin = io.StringIO(input_str)
    sys.stdout = io.StringIO()
    try:
        main()
        return sys.stdout.getvalue().strip()
    finally:
        sys.stdin, sys.stdout = stdin_backup, stdout_backup


def test_sample_1():
    input_data = textwrap.dedent(
        """\
        6
        hotel
        weary
        heart
        blast
        pilot
        vague
        3
        X!XX!
        *!XX!
        *****
        """
    )
    expected = textwrap.dedent(
        """\
        1
        1
        1
        """
    ).strip()
    assert _run_io_test(input_data) == expected


def test_sample_2():
    input_data = textwrap.dedent(
        """\
        3
        scale
        table
        maple
        5
        X!X**
        X!X**
        X!X**
        X!X**
        X!X**
        """
    )
    expected = textwrap.dedent(
        """\
        2
        2
        2
        2
        2
        """
    ).strip()
    assert _run_io_test(input_data) == expected


def test_sample_3():
    input_data = textwrap.dedent(
        """\
        4
        scale
        table
        maple
        smile
        4
        X!X**
        *XX**
        X!X**
        *****
        """
    )
    expected = textwrap.dedent(
        """\
        2
        1
        2
        1
        """
    ).strip()
    assert _run_io_test(input_data) == expected


def test_single_word():
    # Edge‑case: only one dictionary word == secret.
    input_data = """\
    1
    apple
    3
    *****
    XXXXX
    !*XXX
    """
    expected = """\
    1
    1
    1
    """.strip()
    assert _run_io_test(input_data) == expected
