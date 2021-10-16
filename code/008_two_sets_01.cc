// Simple solution using consecutive numbers.

#include <iostream>

int main()
{
    int n; // 1 <= n <= 10^6.
    std::cin >> n;
    switch (n % 4) {
    case 0:
        std::cout << "YES\n";
        // Print the first set.
        std::cout << n / 2 << "\n";
        for (int i = 1; i <= n / 4; ++i) {
            std::cout << i << ' ' << n + 1 - i << ' ';
        }
        std::cout << '\n';
        // Print the second set.
        std::cout << n / 2 << "\n";
        for (int i = 1 + n / 4; i <= n / 2; ++i) {
            std::cout << i << ' ' << n + 1 - i << ' ';
        }
        std::cout << '\n';
        break;
    case 3:
        std::cout << "YES\n";
        // Print the first set.
        std::cout << n / 2 + 1 << "\n";
        std::cout << 1 << ' ' << 2 << ' ';
        for (int i = 4; i <= 3 + (n - 3) / 4; ++i) {
            std::cout << i << ' ' << n + 4 - i << ' ';
        }
        std::cout << '\n';
        // Print the second set.
        std::cout << n / 2 << "\n";
        std::cout << 3 << ' ';
        for (int i = 4 + n / 4; i <= 3 + (n - 3) / 2; ++i) {
            std::cout << i << ' ' << n + 4 - i << ' ';
        }
        std::cout << '\n';
        break;
    default:
        std::cout << "NO\n";
    }
}
