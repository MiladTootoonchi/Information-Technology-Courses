# include <iostream>

void print_bytes(const char* name, void* var, size_t size) {
    unsigned char* p = reinterpret_cast<unsigned char*>(var);

    std::cout << name << " (" << size << " byte): ";

    for (size_t i = 0; i < size; ++i) {
        unsigned char c = p[i];

        int high = c / 16;
        int low  = c % 16;

        std::cout << "0x";

        std::cout << (high < 10 ? char('0' + high) : char('a' + high - 10));
        std::cout << (low  < 10 ? char('0' + low)  : char('a' + low  - 10));

        std::cout << " ";
    }

    std::cout << "\n";
}

int main() {
    short s = -12;
    int i = -12;
    long l = -12;
    long long ll = -12;

    print_bytes("short", &s, sizeof(s));
    print_bytes("int", &i, sizeof(i));
    print_bytes("long", &l, sizeof(l));
    print_bytes("long long", &ll, sizeof(ll));

    return 0;
}
