#include <iostream>

void solve(long long y, long long x)
{
    if (y <= x) { // (y, x) on or above diagonal.
        if (x % 2 == 1) {
            std::cout << x * x - y + 1 << '\n';
        } else {
            std::cout << (x - 1) * (x - 1) + y << '\n';
        }
    } else { // (y, x) below diagonal.
        if (y % 2 == 0) {
            std::cout << y * y - x + 1 << '\n';
        } else {
            std::cout << (y - 1) * (y - 1) + x << '\n';
        }
    }
}

int main()
{
    int t; // 1 <= t <= 10^5.
    long long y, x; // 1 <= y, x <= 10^9.

    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> y >> x;
        solve(y, x);
    }
}
