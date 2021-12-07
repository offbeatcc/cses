#include <iostream>
#include <vector>
#include <limits>

int main()
{
    int n; // 1 <= n < 20.
    std::cin >> n;

    std::vector<int> p(n); // 1 <= p[i] <= 10^9.
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    long long min_diff = std::numeric_limits<long long>::max();

    // Each m represents an n-bit string from 000...000 to 111...111.
    for (int m = 0; m < (1 << n); ++m) {
        long long diff = 0; // 1st group sum - 2nd group sum.
        for (int i = 0; i < n; ++i) {
            if (m & (1 << i)) {
                // If bit k_i = 1, p[i] belongs to the 1st group.
                diff += p[i];
            } else {
                // If bit k_i = 0, p[i] belongs to the 2nd group.
                diff -= p[i];
            }
        }
        min_diff = std::min(min_diff, std::abs(diff));
    }
    std::cout << min_diff << '\n';
}
