import sys

class CoinGame:
    def __init__(self):
        try:
            self.n = int(sys.stdin.readline())
        except:
            print('잘못된 입력입니다.')
            sys.exit(1)
        
        if not (1 <= self.n <= 1000):
            print('동전의 개수는 1 이상 1000 이하이어야 합니다.')
            sys.exit(1)
    
    def make_move(self):
        if self.n <= 0:
            sys.exit(0)

        move = self.n % 4
        if move == 0:
            move = 1
        elif move > 3:
            move = 3

        move = min(move, 3, self.n)
        self.n -= move

        print(move)
        sys.stdout.flush()

    def read_opponent_move(self):
        try:
            response = sys.stdin.readline().strip()
        except:
            sys.exit(1)

        if response == "I give up":
            sys.exit(0)
        else:
            try:
                c = int(response)
                if c not in {1, 2, 3}:
                    print("유효하지 않은 상대의 움직임입니다.")
                    sys.exit(1)
                self.n -= c
            except:
                print("유효하지 않은 입력입니다.")
                sys.exit(1)
    
    def play_game(self):
        while True:
            self.make_move()
            if self.n <= 0:
                sys.exit(0)

            self.read_opponent_move()

            if self.n <= 0:
                sys.exit(0)

if __name__ == "__main__":
    game = CoinGame()
    game.play_game()