#include <iostream>
#include <string>
#include <vector>
#include <cassert>

long long factorial(int n) {
    assert(0 <= n && n <= 20); // 20! < 2^64 - 1 < 21!
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void sort(std::string* s)
{
    // Count frequency of each letter.
    std::vector<int> freq(26);
    for (const char& c : *s) {
        ++freq[c - 'a'];
    }

    // Write the letters back to s in sorted order.
    int to = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        for (int i = 0; i < freq[c - 'a']; ++i) {
            (*s)[to++] = c;
        }
    }
}

void solve(std::string prefix, std::string s)
{
    std::cout << "solve(\"" << prefix << "\", \"" << s << "\")" << '\n';
    if (s == "") {
        std::cout << prefix << '\n';
        return;
    }

    sort(&s);

    // For each distinct letter in s, move the letter from s to
    // prefix, and find permutations for the remaining s.
    solve(prefix + s[0], s.substr(1));
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i - 1] != s[i]) {
            solve(prefix + s[i], s.substr(0, i) + s.substr(i + 1));
        }
    }
}

int main()
{
    std::string s; // 1 <= s.size() <= 8.
    std::cin >> s;
    sort(&s);

    // Compute the number of permutations.
    long long permutations = factorial(s.size());
    int k = 1; // Number of repetitions of current character.
    for (std::size_t i = 1; i < s.size(); ++i) {
        if (s[i - 1] == s[i]) {
            ++k;
        } else {
            permutations /= factorial(k);
            k = 1;
        }
    }
    permutations /= factorial(k);

    std::cout << permutations << '\n';
    solve("", "abac");
}
