def solveSudoku(board):
    def is_valid(num, row, col):
        # Check row
        if num in board[row]:
            return False
        # Check column
        if num in [board[i][col] for i in range(9)]:
            return False
        # Check 3x3 subgrid
        subgrid_row, subgrid_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(subgrid_row, subgrid_row + 3):
            for j in range(subgrid_col, subgrid_col + 3):
                if board[i][j] == num:
                    return False
        return True

    def solve(row, col):
        if row == 9:
            return True
        if col == 9:
            return solve(row+1 , 0)
        if board[row][col] != '.':
            return solve(row, col + 1)

        for num in map(str,range(1,10)):
            if is_valid(num, row, col):
                board[row][col] = num
                if solve(row, col + 1):
                    return True
                board[row][col] = '.'
        
        return False
                            

    solve(0, 0)

# Example Sudoku board (9x9 grid as a list of lists)
sudoku_board = [
    ["5", "3", ".", ".", "7", ".", ".", ".", "."],
    ["6", ".", ".", "1", "9", "5", ".", ".", "."],
    [".", "9", "8", ".", ".", ".", ".", "6", "."],
    ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
    ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
    ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
    [".", "6", ".", ".", ".", ".", "2", "8", "."],
    [".", ".", ".", "4", "1", "9", ".", ".", "5"],
    [".", ".", ".", ".", "8", ".", ".", "7", "9"]
]

solveSudoku(sudoku_board)

# Print the solved Sudoku board
for row in sudoku_board:
    print(" ".join(row))
