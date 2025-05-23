import sys
from collections import defaultdict

class AccountantSorter:
    def __init__(self):
        self.n = 0
        self.k = 0
        self.items = []
        self.category_order = {}
        self.item_to_category = {}
        self.sorted_items = []

    def read_input(self):
        input = sys.stdin.read().split()
        idx = 0

        self.n = int(input[idx])
        self.k = int(input[idx + 1])
        idx += 2

        self.items = input[idx : idx + self.n]
        idx += self.n

        c_categories = input[idx : idx + self.k]
        idx += self.k

        for order, category in enumerate(c_categories, start = 1):
            self.category_order[category] = order

        for _ in range(self.k):
            s_i = input[idx]
            m_i = int(input[idx + 1])
            items_i = input[idx + 2 : idx + 2 + m_i]
            idx += 2 + m_i

            category_seq = self.category_order[s_i]
            for item in items_i:
                self.item_to_category[item] = category_seq

    def sort_items(self):
        category_groups = defaultdict(list)
        for item in self.items:
            category_seq = self.item_to_category[item]
            category_groups[category_seq].append(item)

        for seq in sorted(category_groups.keys()):
            self.sorted_items.extend(category_groups[seq])

    def print_sorted_items(self):
        print(' '.join(self.sorted_items))
    
    def execute(self):
        self.read_input()
        self.sort_items()
        self.print_sorted_items()

if __name__ == "__main__":
    sorter = AccountantSorter()
    sorter.execute()