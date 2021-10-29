#include <iostream>

int main()
{
    int n; // 1 <= n <= 10^9.
    std::cin >> n;

    int alpha = 0; // Largest power of 5 that divides n!.

    // Calculate alpha = [n / 5] + [n / 5^2] + [n / 5^3] + ...
    while (n) {
        alpha += (n /= 5);
    }

    std::cout << alpha << '\n';
}
