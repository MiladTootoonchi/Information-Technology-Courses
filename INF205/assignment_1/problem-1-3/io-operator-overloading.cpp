#include "journal-article-index.h"
#include <iostream>
#include <fstream>

int main()
{
   litindex::JournalArticleIndex jai_i;
   jai_i.set_bibliographic_data(
      "IEEE_Access", 9, 0, 152333, 152346, 2021, "doi:10.1109/access.2021.3126429"
   );
   jai_i.set_page(152345);
   std::clog << "JournalArticleIndex jai_i:\n" << jai_i << "\n";
   std::clog << "\nWriting jai_i into a string stream.\n";
   
   // writing to file
   std::ofstream out_file("journal.txt");
   out_file << jai_i;
   out_file.close();

   std::clog << "Object written to file 'journal.txt'\n";

   litindex::JournalArticleIndex jai_j;

   std::clog << "\nReading jai_j from file.\n";

   // reading from file
   std::ifstream in_file("journal.txt");
   in_file >> jai_j;
   in_file.close();

   std::clog << "JournalArticleIndex jai_j:\n" << jai_j << "\n";
}