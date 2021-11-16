#include <iostream>
#include <vector>
#include <limits>

void solve(const std::vector<int>& p, long long& min_diff, long long diff, std::size_t i)
{
    if (i == p.size()) {
        min_diff = std::min(min_diff, std::abs(diff));
        return;
    }
    solve(p, min_diff, diff - p[i], i + 1);
    solve(p, min_diff, diff + p[i], i + 1);
}

int main()
{
    int n; // 1 <= n < 20.
    std::cin >> n;

    std::vector<int> p(n); // 1 <= p[i] <= 10^9.
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    long long min_diff = std::numeric_limits<long long>::max();
    solve(p, min_diff, 0, 0);
    std::cout << min_diff << '\n';
}
