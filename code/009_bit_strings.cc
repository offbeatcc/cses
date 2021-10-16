#include <iostream>

int main()
{
    int n; // 1 <= n <= 10^6.
    int m = 1000000007;
    int r = 1;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        r = (r * 2) % m;
    }
    std::cout << r << '\n';
}
