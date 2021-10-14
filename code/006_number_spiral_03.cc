// Solution using diagonal numbers.

#include <iostream>

long long f(long long y, long long x)
{
    long long diag;
    int sign;
    int dist;

    if (y <= x) { // On or above diagonal.
        diag = 1 + x * (x - 1);
        sign = (x % 2 == 1) ? 1 : -1;
        dist = x - y;
    } else { // Below diagonal.
        diag = 1 + y * (y - 1);
        sign = (y % 2 == 1) ? -1 : 1;
        dist = y - x;
    }

    return diag + sign * dist;
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
