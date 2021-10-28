// Another solution using consecutive integers.
// This solution reduces code duplication compared to the previous one.

#include <iostream>

int main()
{
    int n; // 1 <= n <= 10^6.    
    std::cin >> n;
    
    if (n % 4 == 1 || n % 4 == 2) {
        std::cout << "NO\n";
        return 0;
    }
    
    std::cout << "YES\n";

    int k = (n % 4) + 1; // k = 1 or k = 4.
    int m = n - (n % 4);
    
    // Print the first set.
    std::cout << (n - 1) / 2 + 1 << '\n';
    if (n % 4 == 3) {
        std::cout << 1 << ' ' << 2 << ' ';
    }
    for (int i = k; i < k + m / 4; ++i) {
        std::cout << i << ' ' << n + k - i << ' ';
    }
    std::cout << '\n';
    
    // Print the second set.
    std::cout << n / 2 << '\n';
    if (n % 4 == 3) {
        std::cout << 3 << ' ';
    }
    for (int i = k + m / 4; i < k + m / 2; ++i) {
        std::cout << i << ' ' << n + k - i << ' ';
    }
    std::cout << '\n';
}
