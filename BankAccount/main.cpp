#include <iostream>
#include "BankAccount.hpp"
#include <cstring>
#include <vector>
//#include <string>

enum class Action {
    CREATE,
    PRINT,
    WITHDRAW,
    DEPOSIT,
    EXIT,
    INVALID
};

Action eval(char);
BankAccount* createAcc(BankAccount *list, size_t &count);
bool validateCardNum(char*);
BankAccount* createAcc() {
    BankAccount *b = new BankAccount;
    return b;
}
int main() {
    /* BankAccount *c = createAcc();
    BankAccount b;
    delete c; */
    /* char ch[2] = "C";
    std::cout << (eval(ch[0]) == Action::CREATE); */
    size_t count = 0;
    BankAccount *list = new BankAccount[count];
    BankAccount *newList = nullptr;

    std::cout << "\nWelcome to Bank Wizard. \n\n";
    std::cout << "Available options: \n";
    std::cout << "[C]reate new bank account.\n";
    std::cout << "[P]rint all accounts.\n";
    std::cout << "[W]ithdraw money from accont.\n";
    std::cout << "[D] - Make a deposit.\n";
    std::cout << "[X] - Exit wizard.\n";
    
    

    
    bool programRun = true;
    while (programRun) {
        
        std::cout << "\nEnter your choice: ";
        char ch[2];
        std::cin.getline(ch, 2);

        if (eval(ch[0]) == Action::CREATE) {
            
            newList = createAcc(list, count);

            delete[] list;
            list = newList;
            
            newList = nullptr;
            
        } 
        else if (eval(ch[0]) == Action::PRINT) {
            std::cout << "Enter your card Number: ";
            char buff[16];
            std::cin.getline(buff, 16);
            while (validateCardNum(buff) == 0) {
                std::cout << "Invalid card num. Enter again.";
                std::cin.getline(buff, 16);
            }
            bool found = false;
            for (int i = 0; i < count && !found; ++i) {

                if (strcmp(buff, list[i].getCardNum()) == 0) {
                    list[i].printAccount();
                    found = true;
                }
            }
            if (!found) std::cout << "No matching card number found.";
        }
        else if (eval(ch[0]) == Action::EXIT) {
            std::cout << "\nGoodbye.";
            programRun = false;
            
        }
        else if (eval(ch[0]) == Action::INVALID) {
            std::cout << "\nInvalid input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }

    }
    
    delete[] list;
    return 0;
}
bool validateCardNum(char *num) {
    if (strlen(num) != 15) return false;
    return true;
}
BankAccount* createAcc(BankAccount *list, size_t &count) {
    //BankAccount *b = new BankAccount;
    BankAccount *newList = new BankAccount[count + 1];

    for (int i = 0; i < count; ++i) {
        newList[i] = list[i];
    }
    

    size_t nameLen = 25;
    char name_[nameLen];

    size_t cardNumLen = 16;
    char cardNum_[cardNumLen];
    
    std::cout << "Enter Personal and family name: \n";
    std::cin.getline(name_, nameLen, '\n');

    std::cout << "Enter a unique valid 15-symbol card number: ";
    std::cin.getline(cardNum_, cardNumLen);

    while(validateCardNum(cardNum_) == 0) {
        std::cout << "\nCard Number should consist of 15 letters and numbers!. Enter again: ";
        std::cin.getline(cardNum_, cardNumLen);
    }

    BankAccount obj(name_, cardNum_);
    
    newList[count] = obj;
    
    count++;
    std::cout << "\nBank account created successfully!\n";

    return newList;
}
/* BankAccount* createAccTwo(BankAccount *list, size_t count) {
    BankAccount *newList = new BankAccount[count + 1];
    delete[] newList;

    for (int i = 0; i < count; ++i) {
        newList[i] = list[i];
    }
} */

Action eval(char choice) {
    if (choice == 'C') {
        return Action::CREATE;
    }
    if (choice == 'P') {
        return Action::PRINT;
    }
    if (choice == 'W') {
        return Action::WITHDRAW;
    }
    if (choice == 'D') {
        return Action::DEPOSIT;
    }
    if (choice == 'X') {
        return Action::EXIT;
    }
    return Action::INVALID;
}