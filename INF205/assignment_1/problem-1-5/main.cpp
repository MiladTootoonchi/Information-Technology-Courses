#include <iostream>
#include <set>  // for std::set
#include <string>  // vi vil konvertere C-strengane til C++-strengar
#include <vector>

int main(int argc, char** argv)
{
    std::cout << "\nargv[0] er namnet til den kørbare fila: " << argv[0] << "\n";
   
    std::set<std::string> argumentsett{};
    std::vector<std::string> unike_argument{};
   
    for(int i = 0; i < argc; i++)
    {
        std::string arg = argv[i];

        // Hvis ikke allerede sett
        if(argumentsett.find(arg) == argumentsett.end())
        {
            argumentsett.insert(arg);
            unike_argument.push_back(arg);
        }
    }

    // Skriv ut i opprinnelig rekkefølge
    for(const std::string& s : unike_argument)
    {
        std::cout << "\targument: \"" << s << "\"\n";
    }
}