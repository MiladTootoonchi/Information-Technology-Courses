#include <iostream>
#include "task1.h"

int check_datatype() {
    std::cout << "short:      " << sizeof(short) << " byte\n";
    std::cout << "int:        " << sizeof(int) << " byte\n";
    std::cout << "long:       " << sizeof(long) << " byte\n";
    std::cout << "long long:  " << sizeof(long long) << " byte\n";
    std::cout << "float:      " << sizeof(float) << " byte\n";
    std::cout << "double:     " << sizeof(double) << " byte\n";
    std::cout << "char:       " << sizeof(char) << " byte\n";

    return 0;
}
