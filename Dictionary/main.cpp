#include <iostream>

#include "String.hpp"
#include "Vector.hpp"
#include "Dictionary.hpp"


int main() {
    
    const String words[] = {"hey", "banica", "Fmi", "Onlain", "Dis"};
    const String defs[] = 
    {
        "greeting", 
        "traditional Bulgarian cuisine",
        "Hell",
        "Tragichno",
        "Trash"
    };
    
    Vector<String> wrd(words, 5);
    Vector<String> dfs(defs, 5);
    
    Dictionary d2(wrd, dfs);
    Dictionary d3 = d2;
    //d3.printAll();

    const String words2[] = {"FIFA 15", "VS code", "Dualshock 3", "Simba", "Dis"};
    const String defs2[] = 
    {
        "Enjoyable football game",
        "That's dark magic. I was there when it was written.",
        "Classic Old School",
        "My cat. Love him <3",
        "No e vajen."
    };

    Vector<String> vectorWords(words2, 5);
    Vector<String> vectorDefs(defs2, 5);

    Dictionary d4(vectorWords, vectorDefs);
    //Dictionary d5 = d3 + d4;

    d3 += d4;


    std::cout << "d3: \n";
    d3.printAll();

    std::cout << "\nd4: \n";
    d4.printAll();

    std::cout << "\n\n\n ----- TESTING d5 ----- \n\n";
    //d5.printAll();

    //std::cout << "\nSize: " << d5.getVector().size() << '\n' << "Capacity: " << d5.getVector().maxCapacity();

    return 0;
}
