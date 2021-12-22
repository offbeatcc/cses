#include <iostream>
#include <set>

int main()
{
    int n; // 1 <= n <= 2 * 10^5.
    std::cin >> n;

    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        int x; // 1 <= x <= 10^9.
        std::cin >> x;
        s.insert(x);
    }

    std::cout << s.size() << '\n';
}

// Note that std::set::insert() takes O(log n) time to insert an
// element into the set whereas std::unordered_set::insert() takes
// O(1) time on an average, where n = size of the set. However, in
// practice, on CSES, using std::unordered_set causes TLE for the
// largest test case with n = 200000 but using std::set completes the
// execution in merely 0.12 s.
