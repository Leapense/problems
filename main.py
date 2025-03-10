class Solution:
    def coloredCells(self, n: int) -> int:
        num_blue_cells = 1
        addend = 4

        while n - 1:
            num_blue_cells += addend
            addend += 4
            n -= 1

        return num_blue_cells

sol = Solution()
print(sol.coloredCells(1))
print(sol.coloredCells(2))