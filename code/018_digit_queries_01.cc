#include <iostream>
#include <cmath>

// Precompute a[n] = number of digits in concatenation of 1, 2, ..., 10^n - 1.
void precompute_lengths(long long (&a)[18])
{
    a[0] = 0;
    for (std::size_t n = 1; n < sizeof a / sizeof *a; ++n) {
        // a[n] = a[n - 1] + 9 * n * 10^(n - 1).
        a[n] = a[n - 1] + 9 * n * std::llround(std::pow(10, n - 1));
    }
}

// Return the kth digit in concatenation of 1, 2, 3, ...
int solve(long long k, long long (&a)[18])
{
    // Find n = number of digits in the integer at the kth place.
    int n = 0;
    while (a[n] < k) {
        ++n;
    }

    // Maximum (n - 1)th digit integer = 10^(n - 1) - 1.
    long long m = std::llround(std::pow(10, n - 1)) - 1;

    // The nth digit integer that ends on or before kth place.
    long long p = m + (k - a[n - 1]) / n;

    // Distance between the last digit of p and the kth digit.
    int r = (k - a[n - 1]) % n;

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

    long long a[18];
    precompute_lengths(a);

    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> k;
        std::cout << solve(k, a) << '\n';
    }

}
