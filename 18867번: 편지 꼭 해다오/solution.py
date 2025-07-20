import sys

def build_letter() -> str:
    base_message = (
        "Dear Ukje,\n"
        "Stay strong in training. We're proud of you.\n"
        "We'll await your return on 2020-04-29.\n"
        "Cheer up!\n"
    )
    padding = "3" * 181_441
    return base_message + padding

def main() -> None:
    sys.stdout.write(build_letter())

if __name__ == "__main__":
    main()