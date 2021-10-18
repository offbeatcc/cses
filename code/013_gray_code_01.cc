// A recursive definition of gray code that demonstrates the
// reflective property of the code.

// This was written to demonstrate the properties of Gray code in
// Offbeat Computation Club meetings for CSES problem solving. See
// https://offbeat.cc/cses/boards/ for more details.

#include <iostream>
#include <string>

std::string g(int num, int width)
{
    if (width == 1) {
        return std::to_string(num);
    }
    else if (num < (1 << (width - 1))) {
        return "0" + g(num, width - 1);
    } else {
        return "1" + g((1 << width) - 1 - num, width - 1);
    }
}

int main()
{
    int n; // 1 <= n <= 16.
    std::cin >> n;

    for (int k = 0; k < (1 << n); ++k) {
        std::cout << g(k, n) << '\n';
    }
}
