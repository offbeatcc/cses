#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    for (long long k = 1; k <= n; ++k) {
        std::cout << (k * k) * (k * k - 1) / 2 - 4 * (k - 1) * (k - 2) << '\n';
    }
}
