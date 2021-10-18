// Based on NieDzejkob's solution.

#include <iostream>

int main()
{
    std::string s; // 1 <= s.size() <= 10^6.
    std::cin >> s;

    int freq[26] = {0};
    for (const char& c : s) {
        ++freq[c - 'A'];
    }

    char middle = 0; // Character with odd frequency.
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (freq[c - 'A'] % 2 == 1) {
            if (middle == 0) {
                middle = c;
            } else {
                std::cout << "NO SOLUTION\n";
                return 0;
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        for (int j = 0; j < freq[c - 'A'] / 2; ++j) {
            std::cout << c;
        }
    }

    if (middle) {
        std::cout << middle;
    }

    for (char c = 'Z'; c >= 'A'; --c) {
        for (int j = 0; j < freq[c - 'A'] / 2; ++j) {
            std::cout << c;
        }
    }

    std::cout << '\n';
}
