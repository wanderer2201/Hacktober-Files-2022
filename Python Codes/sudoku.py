# Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
# Each row must contain the digits 1-9 without repetition.
# Each column must contain the digits 1-9 without repetition.
# Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for x in range(9)]
        columns = [set() for x in range(9)]
        squares = [[set() for x in range(3)] for y in range(3)]
        
        for x in range(9):
            for y in range(9):
                cell_value = board[x][y]
                if cell_value == ".":
                    continue
                if cell_value in rows[x] or cell_value in columns[y] or cell_value in squares[x//3][y//3]:
                    return False

                rows[x].add(cell_value)
                columns[y].add(cell_value)
                squares[x//3][y//3].add(cell_value)
        
        return True
