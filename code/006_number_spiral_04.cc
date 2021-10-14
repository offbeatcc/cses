// Another solution using diagonal numbers.
// This one uses less variables compared to the previous solution.

#include <iostream>

long long f(long long y, long long x)
{
    long long k = std::max(x, y);
    return (1 + k * (k - 1)) + (k % 2 == 0 ? 1 : -1) * (y - x);
}

int main()
{
    int t; // 1 <= t <= 10^5.
    int y, x; // 1 <= y, x <= 10^9.

    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> y >> x;
        std::cout << f(y, x) << '\n';
    }
}
