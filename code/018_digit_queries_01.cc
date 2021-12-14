#include <iostream>
#include <cmath>

// Return the kth digit in concatenation of 1, 2, 3, ...
int solve(long long k)
{
    // Let a_i = number of digits in concatenation of 1, 2, ..., 10^i - 1.
    // Find a_max = the largest a_i < k. Set n = max + 1.

    // Note: n is now the width (number of digits) of the integer that
    // the kth digit belongs to.

    long long a_max = 0; // We save the maximum a_i that does not exceed k here.
    long long a_next = 0; // We compute the next value of a_i and save it here.
    int n = 0; // n = max + 1.

    while (a_next < k) {
        a_max = a_next;
        ++n;
        // a[n] = a[n - 1] + 9n * 10^(n - 1).
        a_next = a_next + 9 * n * std::llround(std::pow(10, n - 1));
    }

    // The n-digit integer that ends on or before kth place.
    long long p = std::llround(std::pow(10, n - 1)) - 1 + (k - a_max) / n;

    // Distance between the last digit of p and the kth digit.
    int r = (k - a_max) % n;

    if (r == 0) {
        // The last digit of p.
        return p % 10;
    } else {
        // The rth digit of p + 1.
        return ((p + 1) / std::llround(std::pow(10, n - r))) % 10;
    }
}

int main()
{
    int q; // 1 <= q <= 1000.
    long long k; // 1 <= k <= 10^18.

    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> k;
        std::cout << solve(k) << '\n';
    }
}
