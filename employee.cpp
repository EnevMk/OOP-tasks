#include <iostream>
#include <cstring>

struct Name {
public:    
    char *first;
    char *last;
    ~Name();
    void setName() {
        std::cout << "Enter employee's first name: ";
        char buf[13];
        std::cin >> buf;

        std::cout << "Enter employee's last name: ";
        char buff2[13];
        std::cin >> buff2;
        
        first = new char[strlen(buf) + 1];
        strcpy(first, buf);

        last = new char[strlen(buff2) + 1];
        strcpy(last, buff2);
    }
};
Name::~Name() {
    delete[] first;
    delete[] last;
}

struct Work {
public:    
    size_t hours;
    size_t salary;
public:
    Work();
};
Work::Work() {
    hours = 40;
    salary = 12;
}

class Employee {
public:    
    Name name_;
    Work work_;

public:
    void printPay();
    //void enterData();
    double calculatePay();
};
/* void enterData() {
    
} */
double Employee::calculatePay() {
    return work_.hours * work_.salary;
}
void Employee::printPay() {

    std::cout << name_.first << ' ' << name_.last << "\' s salary is " << calculatePay() << " USD";
}
int main() {
    Employee test;
    test.name_.setName();
    test.printPay();
    return 0;
}