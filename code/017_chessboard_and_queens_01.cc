#include <iostream>

// When col - 1 queens are already placed on columns 0 to col - 1,
// check if it is safe to place a new queen at (row, col).
bool check(bool (&board)[8][8], int row, int col)
{
    // Check the current row for an attacking queen.
    for (int i = 0; i < col; ++i) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check the upper diagonal for an attacking queen.
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the lower diagonal for an attacking queen.
    for (int i = row, j = col; i < 8 && j >= 0; ++i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Solve the 8-queens problem recursively.
void solve(char (&input)[8][8], bool (&board)[8][8], int col, int& result)
{
    // If all queens were placed successfully on columns 0 to 7, we
    // have a successful placement to be counted.
    if (col == 8) {
        ++result;
        return;
    }

    // In the current column (col), try placing the queen in each row
    // one by one and search for solutions recursively.
    for (int i = 0; i < 8; ++i) {
        if (input[i][col] == '.' && check(board, i, col)) {
            board[i][col] = true;
            solve(input, board, col + 1, result);
            board[i][col] = false;
        }
    }
}

int main()
{
    char input[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cin >> input[i][j];
        }
    }

    bool board[8][8] = {{false}};
    int result = 0;
    solve(input, board, 0, result);
    std::cout << result << '\n';
}
