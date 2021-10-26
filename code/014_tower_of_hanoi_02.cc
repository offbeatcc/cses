#include <iostream>

// Move n discs from peg x to peg y using peg z as the spare peg.
void solve(int n, int x, int y, int z)
{
    if (n == 0) {
        return;
    }
    solve(n - 1, x, z, y);
    std::cout << x << " " << y << '\n';
    solve(n - 1, z, y, x);
}

int main()
{
    int n; // 1 <= n <= 16.
    std::cin >> n;
    std::cout << ((1 << n) - 1) << '\n';
    solve(n, 1, 3, 2);
}
