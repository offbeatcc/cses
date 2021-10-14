#include <iostream>

int main()
{
    int n;
    long long result = 0;
    std::cin >> n;
    std::cout << result << '\n';
    for (long long k = 2; k <= n; ++k) {
        result += 2*k*k*k - 3*k*k - 7*k + 16;
        std::cout << result << '\n';
    }
}
