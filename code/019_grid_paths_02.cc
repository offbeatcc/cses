// An optimized version of the previous program, so that it takes less
// than 1 s to perform a full search of 88418 paths.

#include <iostream>

const int N = 7;

void solve(bool (&a)[N][N], int i, int j, int move_num, char *path, int& result)
{

    if (i == N - 1 && j == 0) {
        // If we reach the target too early, prune the search.
        if (move_num < N * N - 1) {
            return;
        }

        // We have reached the target after visiting all cells.
        ++result;
    }

    // Optimization 1: Move split and loop checks inline
    // Improvement: 1.3 s -> 1.1 s for full search.

    // If visiting the current cell splits the grid into two regions,
    // prune the search.
    if ((i == 0 && j != 0 && j != N - 1 &&
         a[i + 1][j] && !a[i][j - 1] && !a[i][j + 1]) ||

        (i == N - 1 && j != 0 && j != N - 1 &&
         a[i - 1][j] && !a[i][j - 1] && !a[i][j + 1]) ||

        (j == 0 && i != 0 && i != N - 1 &&
         a[i][j + 1] && !a[i - 1][j] && !a[i + 1][j]) ||

        (j == N - 1 && i != 0 && i != N - 1 &&
         a[i][j - 1] && !a[i - 1][j] && !a[i + 1][j])) {

        return;
    }

    // If visiting the current cell creates a loop, prune the search.
    if (i != 0 && i != N - 1 && j != 0 && j != N - 1 &&
        ((a[i][j - 1] && a[i][j + 1] && !a[i - 1][j] && !a[i + 1][j]) ||
         (a[i - 1][j] && a[i + 1][j] && !a[i][j - 1] && !a[i][j + 1]))) {

        return;
    }

    a[i][j] = true;

    // Optimization 2: Move unavailable cell check from nested call to
    // the current call. Improvement: 1.1 s -> 0.9 s for full search.
    char move = path[move_num];
    if ((move == 'U' || move == '?') && i > 0 && !a[i - 1][j]) {
        solve(a, i - 1, j, move_num + 1, path, result);
    }
    if ((move == 'D' || move == '?') && i < N - 1 && !a[i + 1][j]) {
        solve(a, i + 1, j, move_num + 1, path, result);
    }
    if ((move == 'L' || move == '?') && j > 0 && !a[i][j - 1]) {
        solve(a, i, j - 1, move_num + 1, path, result);

    }
    if ((move == 'R' || move == '?') && j < N - 1 && !a[i][j + 1]) {
        solve(a, i, j + 1, move_num + 1, path, result);
    }
    a[i][j] = false;
}

int main()
{
    // Optimization 3: Change path from std::string to char[].
    // Improvement: 0.9s -> 0.8s for full search.
    char path[N * N];
    std::cin >> path;

    bool a[N][N] = {{false}};
    int result = 0;
    solve(a, 0, 0, 0, path, result);
    std::cout << result  << '\n';
}
