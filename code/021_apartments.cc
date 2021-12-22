#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    // Read input.
    int n; // 1 <= n <= 2 * 10^5 (applicants).
    int m; // 1 <= m <= 2 * 10^5 (apartments).
    int k; // 0 <= k <= 10^9 (maximum allowed difference).

    std::cin >> n >> m >> k;

    std::vector<int> a(n); // 1 <= a[i] <= 10^9 (desired apartment size).
    std::vector<int> b(m); // 1 <= b[i] <= 10^9 (available apartment size).

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    // Solve.
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int i = 0;
    int j = 0;
    int result = 0;

    while (i < n && j < m) {
        int diff = b[j] - a[i];
        if (abs(diff) <= k) { // Suitable apartment size.
            ++i;
            ++j;
            ++result;
            continue;
        } else if (diff > k) { // Desired apartment size too small.
            ++i;
        } else { // Available apartment size too small.
            ++j;
        }
    }

    std::cout << result << '\n';
}
