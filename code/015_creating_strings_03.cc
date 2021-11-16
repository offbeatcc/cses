#include <iostream>
#include <string>
#include <vector>
#include <cassert>

void sort(std::string& s)
{
    // Count frequency of each letter.
    std::vector<int> freq(26);
    for (const char& c : s) {
        ++freq[c - 'a'];
    }

    // Write the letters back to s in sorted order.
    int to = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        for (int i = 0; i < freq[c - 'a']; ++i) {
            s[to++] = c;
        }
    }
}

long long factorial(int n) {
    assert(0 <= n && n <= 20); // 20! < 2^64 - 1 < 21!
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void swap(char* p, char* q) {
    char temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

bool next_permutation(std::string& s) {
    // Find the largest i such that s[i] < s[i + 1].
    int i = s.size() - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        --i;
    }

    // If all characters are in descending order, this is the last
    // permutation.
    if (i == -1) {
        return false;
    }

    // Find the largest j such that s[j] > s[i].
    int j = s.size() - 1;
    while (j >= 0 && s[j] <= s[i]) {
        --j;
    }

    // Replace s[i] with s[j] by swapping them.
    swap(&s[i], &s[j]);

    // Reverse characters from s[i + 1] to end of string.
    for (int l = i + 1, r = s.size() - 1; l <= r; ++l, --r) {
        swap(&s[l], &s[r]);
    }

    return true;
}

int main()
{
    std::string s; // 1 <= s.size() <= 8.
    std::cin >> s;
    sort(s);

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

    do {
        std::cout << s << '\n';
    } while (next_permutation(s));
}
