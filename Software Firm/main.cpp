#include <fstream>

#include "Programmer.hpp"
#include "Manager.hpp"
#include "HR.hpp"

int main() {

    Programmer lacho("Lacho", 12, 1, 0);
    Manager pavel("Pavel", 24, 1);

    //Employee *p = new Manager("Pavel", 24,1); 
    std::cout << lacho << pavel;

    std::ofstream output_file;
    output_file.open("test.txt");

    output_file << lacho << pavel;

    output_file.close();

    Manager kalin("Kalin", 250, 2);
    HR team;
    team.addEmployee(&lacho);
    team.addEmployee(&pavel);
    team.addEmployee(&kalin);

    output_file.open("test.txt");
    output_file << team;

    output_file.close();
    std::cout << team;

    return 0;
}