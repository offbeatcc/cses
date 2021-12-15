// This program consumes about 1.3 s for a full search of 88418 paths.
// See the next program for an optimized version of this program that
// consumes less than 1 s to perform a full search.

#include <iostream>

const int N = 7;

bool split_occurs(bool (&a)[N][N], int i, int j)
{
    return
        // Path hits top edge.
        (i == 0 && j != 0 && j != N - 1 &&
         a[i + 1][j] && !a[i][j - 1] && !a[i][j + 1]) ||

        // Path hits bottom edge.
        (i == N - 1 && j != 0 && j != N - 1 &&
         a[i - 1][j] && !a[i][j - 1] && !a[i][j + 1]) ||

        // Path hits left edge.
        (j == 0 && i != 0 && i != N - 1 &&
         a[i][j + 1] && !a[i - 1][j] && !a[i + 1][j]) ||

        // Path hits right edge.
        (j == N - 1 && i != 0 && i != N - 1 &&
         a[i][j - 1] && !a[i - 1][j] && !a[i + 1][j]);
}


bool loop_occurs(bool (&a)[N][N], int i, int j)
{
    return
        // Path is not touching the edges.
        i != 0 && i != N - 1 && j != 0 && j != N - 1 &&

        // Path closes a horizontal gap to create loop.
        ((a[i][j - 1] && a[i][j + 1] &&
          !a[i - 1][j] && !a[i + 1][j]) ||

        // Path closes a vertical gap to create loop.
         (a[i - 1][j] && a[i + 1][j] &&
          !a[i][j - 1] && !a[i][j + 1]));
}


void solve(bool (&a)[N][N], int i, int j, int move_num,
           std::string& path, int& result)
{
    // If we have an unavailable cell, prune the search.
    if (i == -1 || i == N || j == -1 || j == N || a[i][j]) {
        return;
    }

    if (i == N - 1 && j == 0) {
        // If we reach the target too early, prune the search.
        if (move_num < N * N - 1) {
            return;
        }
        // We have reached the target after visiting all cells.
        ++result;
    }

    // If visiting the current cell splits the grid into two regions,
    // prune the search.
    if (split_occurs(a, i, j) || loop_occurs(a, i, j)) {
        return;
    }

    a[i][j] = true;

    char move = path[move_num];
    if (move == 'U' || move == '?') {
        solve(a, i - 1, j, move_num + 1, path, result);
    }
    if (move == 'D' || move == '?') {
        solve(a, i + 1, j, move_num + 1, path, result);
    }
    if (move == 'L' || move == '?') {
        solve(a, i, j - 1, move_num + 1, path, result);

    }
    if (move == 'R' || move == '?') {
        solve(a, i, j + 1, move_num + 1, path, result);
    }
    a[i][j] = false;
}

int main()
{
    std::string path;
    std::cin >> path;

    bool a[N][N] = {{false}};
    int result = 0;
    solve(a, 0, 0, 0, path, result);
    std::cout << result  << '\n';
}
