#include <iostream>
#include <algorithm>

void solve(int a, int b)
{
    std::cout << ((a + b) % 3 == 0 && 2 * a >= b ? "YES\n" : "NO\n");
}

int main()
{
    int t; // 1 <= t <= 10^5.
    int a, b; // 0 <= a, b <= 10^9.

    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> a >> b;
        solve(std::min(a, b), std::max(a, b));
    }
}
