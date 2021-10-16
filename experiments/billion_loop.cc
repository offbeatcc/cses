#include <iostream>

int main()
{
    int r = 0;
    for (int i = 0; i < 1000000000; ++i) {
        r = (r + i) % 101;
    }
    std::cout << r << '\n';
}
