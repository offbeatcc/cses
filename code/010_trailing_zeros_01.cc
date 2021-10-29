// Note that although this code works it is not a safe way to solve
// this problem. The solution here depends on the existence of a power
// of 5 between 10^9 and 2^32 - 1 so that `while (power <= n)` loop
// can terminate after `power` exceeds n = 10^9 but is still smaller
// than 2^32 - 1 (thus avoiding integer overflow). It so happens that
// there indeed is such a power of 5 and that is 5^13 = 1220703125
// (about 1.2 billion) which lies between 10^9 and 2^31 - 1 (about 2.1
// billion).

// For a safe way to write this solution, see the next solution file.

#include <iostream>

int main()
{
    int n; // 1 <= n <= 10^9.
    std::cin >> n;

    int alpha = 0; // Largest power of 5 that divides n!.
    int power = 5; // Powers of 5, e.g., 5, 25, 125, etc.

    // Calculate alpha = [n / 5] + [n / 5^2] + [n / 5^3] + ...
    while (power <= n) {
        alpha += n / power;
        power *= 5;
    }

    std::cout << alpha << '\n';
}
