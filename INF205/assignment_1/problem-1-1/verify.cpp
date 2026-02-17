#include <iostream>
#include "task1.h"

int verify() {
    int arr[2];

    /* p saves the adresses of the first element in arr*/
    int* p = &arr[0];
    /* q saves the next int in memory after what p points at*/
    int* q = p + 1;

    std::cout << "Adress p: " << p << "\n";
    std::cout << "Adress q: " << q << "\n";

    std::cout << "difference in byte: "
              << reinterpret_cast<char*>(q) - reinterpret_cast<char*>(p)
              << "\n";

    std::cout << "sizeof(int): " << sizeof(int) << "\n";

    return 0;
}
