import random, subprocess, os, pty, sys, shlex, string, tempfile

def play_once():
    machine = ''.join(random.choice('025') for _ in range(100))
    proc = subprocess.Popen(
        ['./solution'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True
    )

    def score(my, opp):  # returns wins
        beats = {('2','5'), ('5','0'), ('0','2')}
        return sum((a,b) in beats for a,b in zip(my, opp))

    for _ in range(102):             # generous upper bound
        line = proc.stdout.readline()
        if not line: break
        if line[0] == '?':
            hand = line[2:].strip()
            wins = score(hand, machine)
            proc.stdin.write(f"{wins}\n")
            proc.stdin.flush()
        elif line[0] == '!':
            guess = line[2:].strip()
            ok = guess == machine
            proc.terminate()
            return ok
    return False

for _ in range(1000):
    assert play_once(), "Found a mismatch!"
print("All 1 000 random tests passed ✅")
