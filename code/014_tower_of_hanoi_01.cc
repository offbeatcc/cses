#include <iostream>

void solve(int n, int source, int target)
{
    if (n == 0) {
        return;
    }
    int spare = 6 - source - target;
    solve(n - 1, source, spare);
    std::cout << source << " " << target << '\n';
    solve(n - 1, spare, target);
}

int main()
{
    int n; // 1 <= n <= 16.
    std::cin >> n;
    std::cout << ((1 << n) - 1) << '\n';
    solve(n, 1, 3);
}
