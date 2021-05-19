#include <fstream>

#include "Programmer.hpp"
#include "Manager.hpp"
#include "HR.hpp"


void map(HR &team, void (HR::*ptr)(int), bool (*filt)(Employee*)) {


    int size = team.size();

    for (int i = 0; i < size; ++i) {

        if (filt(team[i])) {
            (team.*ptr)(i);
        }
    }
}

//template <typename T>
/* HR& filter(HR &team, bool (*filt)(Employee*)) {
    HR newTeam;

    for (int i = 0; i < newTeam.size(); ++i) {

        if (filt(team[i])) {
            newTeam.addEmployee(team[i]);
        }
    }

    return newTeam;
} */

int main() {

    Programmer lacho("Lacho", 12, 1, 0);
    Manager pavel("Pavel", 24, 1);
    Programmer misho("Misho", 2, 1, 0);

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
    team.addEmployee(&misho);

    output_file.open("test.txt");
    output_file << team;

    output_file.close();
    std::cout << team;

    map(team, &HR::leaveJob, [](Employee *e) -> bool {return e->getExperience() < 3;});

    std::cout << "\nafter filter: \n";
    std::cout << team;
    return 0;
}