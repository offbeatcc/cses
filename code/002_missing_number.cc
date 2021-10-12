#include <iostream>

int main()
{
    long long n;
    std::cin >> n;
    long long s = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; ++i) {
        int k;
        std::cin >> k;
        s -= k;
    }
    std::cout << s << '\n';
}
