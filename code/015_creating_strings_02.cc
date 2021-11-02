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

void solve(std::string prefix, const std::vector<int>& freq)
{
    // If all frequencies are 0, we are done; print prefix and return.
    int sum = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        sum += freq[c - 'a'];
    }
    if (sum == 0) {
        std::cout << prefix << '\n';
        return;
    }

    // Recursively find permutations of smaller substrings.
    for (char c = 'a'; c <= 'z'; ++c) {
        if (freq[c - 'a'] == 0) {
            continue;
        }
        std::vector<int> new_freq = freq;
        --new_freq[c - 'a'];
        solve(prefix + c, new_freq);
    }
}

int main()
{
    std::string s; // 1 <= s.size() <= 8.
    std::cin >> s;

    // Count frequency of each letter of alphabet.
    std::vector<int> freq(26);
    for (const char& c : s) {
        ++freq[c - 'a'];
    }

    // Compute the number of permutations.
    long long permutations = factorial(s.size());
    for (char c = 'a'; c <= 'z'; ++c) {
        permutations /= factorial(freq[c - 'a']);
    }
    std::cout << permutations << '\n';

    // Print all permutations.
    solve("", freq);
}
