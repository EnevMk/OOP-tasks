#include <iostream>
#include <cstring>

struct Student {
    char *name;
    int egn;
    int fn;
    double *grades;
};

void initialize(Student &s);

int main() {

    return 0;
}

void initialize(Student &s) {
    std::cout << "Enter student name: ";
    char buf[25];
    std::cin >> buf;
    s.name = new char[strlen(buf) + 1];
    strcpy(s.name, buf);

    std::cout << "Enter egn: ";
    std::cin >> s.egn;

    std::cout << "Enter fn: ";
    std::cin >> s.fn;

    std::cout << "Enter count of grades: ";
    size_t n;
    std::cin >> n;
    std::cout << "Enter student\'s grades: \n";

    for (int i = 0; i < n; ++i) {
        std::cin >> s.grades[i];
    }
}