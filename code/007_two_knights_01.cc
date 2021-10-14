#include <iostream>

int main()
{
    int n;
    long long result = 0;
    std::cin >> n;
    std::cout << result << '\n';
    for (long long k = 2; k <= n; ++k) {
        result +=
            (2 * k - 1) * (k - 1) - 2
            + 5 * ((k - 1) * (k - 1) - 2)
            + 4 * ((k - 1) * (k - 1) - 3)
            + 2 * (k - 5) * ((k - 1) * (k - 1) - 4);
        std::cout << result << '\n';
    }
}
