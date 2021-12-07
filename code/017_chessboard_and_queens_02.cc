#include <iostream>

// Solve the 8-queens problem recursively.
void solve(char (&input)[8][8],
           bool (&row)[8], bool (&fd)[15], bool (&rd)[15],
           int col, int &result)
{
    // If all queens were placed successfully on columns 0 to 7, we
    // have a successful placement to be counted.
    if (col == 8) {
        ++result;
        return;
    }

    // In the current column, try placing the queen in each row one by
    // one and search for solutions recursively.
    for (int i = 0; i < 8; ++i) {
        int fd_i = i - col + 7;
        int rd_i = i + col;
        if (input[i][col] == '.' && !row[i] && !fd[fd_i] && !rd[rd_i]) {
            row[i] = fd[fd_i] = rd[rd_i] = true;
            solve(input, row, fd, rd, col + 1, result);
            row[i] = fd[fd_i] = rd[rd_i] = false;
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

    bool row[8] = {false}; // Lookup table for occupied rows.
    bool fd[15] = {false}; // Lookup table for occupied falling diagonals.
    bool rd[15] = {false}; // Lookup table for occupied rising diagonals.

    int result = 0;
    solve(input, row, fd, rd, 0, result);
    std::cout << result << '\n';
}
