#include <iostream>

int gray(int n)
{
    return n ^ (n >> 1);
}

void print_binary(int num, int width)
{
    for (unsigned mask = 1 << (width - 1); mask > 0; mask = (mask >> 1)) {
        std::cout << ((num & mask) ? 1 : 0);
    }
    std::cout << '\n';
}

int main()
{
    int n; // 1 <= n <= 16.
    std::cin >> n;

    for (int k = 0; k < (1 << n); ++k) {
        print_binary(gray(k), n);
    }
}
