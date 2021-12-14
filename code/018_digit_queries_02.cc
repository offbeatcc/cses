// This is almost the same as the previous solution except that in
// this solution p always refers to the integer that the kth digit
// belongs to.

#include <iostream>
#include <cmath>

// Return the kth digit in concatenation of 1, 2, 3, ...
char solve(long long k)
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

    // The n-digit integer that the kth digit belongs to.
    long long p = std::llround(std::pow(10, n - 1)) + (k - a_max - 1) / n;

    // The 0-based position of the kth digit in p.
    int r = (k - a_max - 1) % n;

    return std::to_string(p)[r];
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
