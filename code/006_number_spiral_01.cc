// Simple solution based on edge numbers.

#include <iostream>

long long f(long long y, long long x)
{
    long long edge;
    int sign;
    int dist;
    
    if (y <= x) { // On or above diagonal.
        edge = (x % 2 == 1) ? x * x : (x - 1) * (x - 1) + 1;
        sign = (x % 2 == 1) ? -1 : 1;
        dist = (y - 1);
    } else { // Below diagonal.
        edge = (y % 2 == 0) ? y * y : (y - 1) * (y - 1) + 1;
        sign = (y % 2 == 0) ? -1 : 1;
        dist = (x - 1);
    }
    return edge + sign * dist;
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
