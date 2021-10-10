#include <iostream>

int main()
{
    std::cout << "sizeof (short): " << sizeof (short) << '\n';
    std::cout << "sizeof (int): " << sizeof (int) << '\n';
    std::cout << "sizeof (long): " << sizeof (long) << '\n';
    std::cout << "sizeof (long long): " << sizeof (long long) << '\n';
    std::cout << "sizeof (void *): " << sizeof (void *) << '\n';
}

/*
Output on macOS/Linux System
============================

sizeof (short): 2
sizeof (int): 4
sizeof (long): 8
sizeof (long long): 8
sizeof (void *): 8
*/
