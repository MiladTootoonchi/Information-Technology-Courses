#include "book-index.h"
#include <iostream>
#include <fstream>

namespace
{
   void start_chapter(litindex::BookIndex b)
   {
      std::cout << "start_chapter(litindex::BookIndex b)\n";

      b.next_chapter();
      b.out();  // print status
   }
}

int main()
{
    std::ifstream infile("input.txt");

    int count;
    infile >> count;

    for (int i = 0; i < count; ++i)
    {
        int c, s, p;
        infile >> c >> s >> p;

        litindex::BookIndex idx(c, s, p);
        idx.out();
    }
}
