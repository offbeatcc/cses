// Another solution using edge numbers.
// This one uses less variables compared to the previous solution.

#include <iostream>

long long f(long long y, long long x)
{
    if (y <= x) { // On or above diagonal.
        return (x % 2 == 1) ? x * x - y + 1 : (x - 1) * (x - 1) + y;
    } else { // Below diagonal.
        return (y % 2 == 0) ? y * y - x + 1 : (y - 1) * (y - 1) + x;
    }
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
