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


/*
Forklaring:

Vi lagrer tallet -12 i ulike heltallstyper (short, int, long, long long)
og ser på hvordan det faktisk ligger i minnet, byte for byte.

Datamaskiner lagrer negative tall med noe som kalles to-komplement.
Kort fortalt betyr det at -12 får en binærrepresentasjon som ender på 0xf4 i laveste byte.

Siden tallet er negativt, fylles resten av bytene med 0xff. Dette kalles sign extension – maskinen "fyller på" med 1-ere
for å bevare fortegnet når typen er større. Derfor vil vi typisk se:
short - 0xf4 0xff
int - 0xf4 0xff 0xff 0xff
long long - 0xf4 fulgt av flere 0xff

At 0xf4 kommer først skyldes at de fleste maskiner i dag er little-endian. 
Det betyr at den minst signifikante byten lagres først i minnet.
Vi bruker unsigned char* fordi unsigned char alltid er nøyaktig én byte, og dermed kan vi gå gjennom minnet byte for byte.

 */