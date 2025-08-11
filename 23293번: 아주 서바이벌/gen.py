import random
from typing import List, Tuple, Set, Dict

class TestDataGenerator:
    def __init__(self, T: int, N: int):
        self.T = T
        self.N = N
        self.logs = []
        self.player_locations = {}
        self.player_items = {}

    def generate_test_data(self, cheating_ratio: float = 0.2) -> str:
        result = [f"{self.T} {self.N}"]
        for log_num in range(1, self.T + 1):
            player_id = random.randint(1, self.N)

            if player_id not in self.player_locations:
                self.player_locations[player_id] = 1
                self.player_items[player_id] = set()

            action = self._choose_action(player_id)
            log_line = self._generate_log_line(log_num, player_id, action, cheating_ratio)
            result.append(log_line)

        return '\n'.join(result)
    
    def _choose_action(self, player_id: int) -> str:
        if len(self.player_items.get(player_id, [])) >= 2:
            weights = [0.3, 0.2, 0.3, 0.2]
        else:
            weights = [0.4, 0.4, 0.1, 0.1]
        
        return random.choices(['M', 'F', 'C', 'A'], weights=weights)[0]
    
    def _generate_log_line(self, log_num: int, player_id: int, action: str, cheating_ratio: float) -> str:
        is_cheating = random.random() < cheating_ratio

        if action == 'M':
            return self._generate_move_log(log_num, player_id)
        elif action == 'F':
            return self._generate_farming_log(log_num, player_id, is_cheating)
        elif action == 'C':
            return self._generate_crafting_log(log_num, player_id, is_cheating)
        elif action == 'A':
            return self._generate_attack_log(log_num, player_id, is_cheating)
        
    def _generate_move_log(self, log_num: int, player_id: int) -> str:
        new_location = random.randint(1, 53)
        while new_location == self.player_locations[player_id]:
            new_location = random.randint(1, 53)
        
        self.player_locations[player_id] = new_location
        return f"{log_num} {player_id} M {new_location}"
    
    def _generate_farming_log(self, log_num: int, player_id: int, is_cheating: bool) -> str:
        current_location = self.player_locations[player_id]
        if is_cheating and current_location != 1:
            item_id = random.randint(1, 53)
            while item_id == current_location:
                item_id = random.randint(1, 53)
        else:
            item_id = current_location
        
        self.player_items[player_id].add(item_id)
        return f"{log_num} {player_id} F {item_id}"
    
    def _generate_crafting_log(self, log_num: int, player_id: int, is_cheating: bool) -> str:
        player_items = self.player_items[player_id]
        if len(player_items) >= 2 and not is_cheating:
            items_list = list(player_items)
            item1, item2 = random.sample(items_list, 2)
            player_items.discard(item1)
            player_items.discard(item2)
        else:
            item1 = random.randint(1, 53)
            item2 = random.randint(1, 53)
            while item1 == item2:
                item2 = random.randint(1, 53)

            if item1 in player_items:
                player_items.discard(item1)
            if item2 in player_items:
                player_items.discard(item2)
        return f"{log_num} {player_id} C {item1} {item2}"
    
    def _generate_attack_log(self, log_num: int, player_id: int, is_cheating: bool) -> str:
        target_id = random.randint(1, self.N)
        while target_id == player_id:
            target_id = random.randint(1, self.N)

        if target_id not in self.player_locations:
            self.player_locations[target_id] = 1
            self.player_items[target_id] = set()

        if not is_cheating:
            self.player_locations[target_id] = self.player_locations[player_id]

        return f"{log_num} {player_id} A {target_id}"
    
def generate_boundary_test_cases():
    test_cases = []

    print("=== Test Case 1: 최소값 (T=1, N=1) ===")
    gen = TestDataGenerator(1, 1)
    print(gen.generate_test_data(0.0))
    print()

    print("=== Test Case 2: 작은 값 (T=10, N=5) ===")
    gen = TestDataGenerator(10, 5)
    print(gen.generate_test_data(0.3))
    print()

    print("=== Test Case 3: 중간 값 (T=100, N=50) ===")
    gen = TestDataGenerator(100, 50)
    print(gen.generate_test_data(0.2))
    print()

    print("=== Test Case 4: 큰 값 (T=1000, N=500) ===")
    gen = TestDataGenerator(1000, 500)
    data = gen.generate_test_data(0.15)
    lines = data.split('\n')
    print(lines[0])
    print('\n'.join(lines[1:11]))
    print(f"... ({len(lines)-11} more lines)")
    print()

    print("=== Test Case 5: 최대값 근처 (T=199999, N=99999) ===")
    gen = TestDataGenerator(199999, 99999)
    data = gen.generate_test_data(0.1)
    lines = data.split('\n')
    print(lines[0])
    print('\n'.join(lines[1:6]))
    print(f"... ({len(lines)-6} more lines)")
    print()

    print("=== Test Case 6: 부정행위 집중 (T=50, N=10) ===")
    gen = TestDataGenerator(50, 10)
    print(gen.generate_test_data(0.7))
    print()

    print("=== Test Case 7: 부정행위 없음 (T=30, N=5) ===")
    gen = TestDataGenerator(30, 5)
    print(gen.generate_test_data(0.0))
    print()

    print("=== Test Case 8: 특정 플레이어 집중 ===")
    result = ["20 3"]
    player_id = 1
    location = 1
    items = set()

    for i in range(1, 21):
        if i <= 5:
            new_loc = random.randint(2, 10)
            result.append(f"{i} {player_id} M {new_loc}")
            location = new_loc
        elif i <= 10:
            result.append(f"{i} {player_id} F {location}")
            items.add(location)
        elif i <= 15:
            if len(items) >= 2:
                item_list = list(items)
                item1, item2 = random.sample(item_list, 2)
                result.append(f"{i} {player_id} C {item1} {item2}")
                items.discard(item1)
                items.discard(item2)
            else:
                result.append(f"{i} {player_id} F {location}")
        else:
            target = 2 if player_id == 1 else 1
            result.append(f"{i} {player_id} A {target}")

    print('\n'.join(result))

if __name__ == "__main__":
    random.seed(42)
    generate_boundary_test_cases()