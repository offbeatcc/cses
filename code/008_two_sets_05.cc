// Based on a solution by pikaynu.

#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& v)
{
    std::cout << v.size() << '\n';
    for (const int& k : v) {
        std::cout << k << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int n; // 1 <= n <= 10^6.
    std::cin >> n;

    std::vector<int> v1;
    std::vector<int> v2;
    long long sum1 = 0;
    long long sum2 = 0;

    // Push each number to the vector with the smaller sum of numbers.
    do {
        if (sum1 <= sum2) {
            v1.push_back(n);
            sum1 += n;
        } else {
            v2.push_back(n);
            sum2 += n;
        }
    } while (--n > 0);

    // Print solution.
    if (sum1 == sum2) {
        std::cout << "YES\n";
        print_vector(v1);
        print_vector(v2);
    } else {
        std::cout << "NO\n";
    }
}

// test_suffix=_05
