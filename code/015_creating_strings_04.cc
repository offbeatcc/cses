#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    std::string s; // 1 <= s.size() <= 8.
    std::cin >> s;

    std::sort(s.begin(), s.end());

    std::vector<std::string> v;
    do {
        v.push_back(s);
    } while(std::next_permutation(s.begin(), s.end()));

    std::cout << v.size() << '\n';
    for (const std::string& s : v) {
        std::cout << s << '\n';
    }
}
