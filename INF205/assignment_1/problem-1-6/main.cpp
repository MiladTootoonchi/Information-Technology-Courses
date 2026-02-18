#include <iostream>
#include <array>

namespace
{
    void increment_at_position(int p, std::array<char, 7> arr)
    {
        std::cout << "increment_at_position_value(int p, std::array<char,7> arr):\n";
        arr[p]++;
        std::cout << "\tarr inside the function: \"";
        for(char c : arr) std::cout << c;
        std::cout << "\"\n";
    }

    void increment_at_position_ref(int p, std::array<char, 7>& arr)
    {
        std::cout << "increment_at_position_ref(int p, std::array<char,7>& arr):\n";
        arr[p]++;
        std::cout << "\tarr inside the function: \"";
        for(char c : arr) std::cout << c;
        std::cout << "\"\n";
    }
}

int main()
{
    std::array<char, 7> arr = {'I','N','F','2','0','5','\0'};

    increment_at_position(5, arr);
    std::cout << "\tarr after value function: \"";
    for(char c : arr) std::cout << c;
    std::cout << "\"\n\n";
    
    increment_at_position_ref(5, arr);
    std::cout << "\tarr after reference function: \"";
    for(char c : arr) std::cout << c;
    std::cout << "\"\n";

}