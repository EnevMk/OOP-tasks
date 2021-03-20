#include <iostream>
#include <cstring>
#include "BankAccount.hpp"

char* BankAccount::getName() const {
    return name;
}
const char* BankAccount::getCardNum() const {
    /* const char *ptr = &cardNum[0]; */
    return cardNum;
}
double BankAccount::getBudget() const {
    return budget;
}
bool BankAccount::validateCardNum(char *num_) {
    if (strlen(num_) == 15) return true;
    return false;
}
BankAccount::BankAccount() {
    name = nullptr;
    cardNum = nullptr;
    budget = 0;
}
BankAccount::BankAccount(const char *name_, const char *cardNum_) {

    name = new char[strlen(name_) + 1];
    strcpy(name, name_);

    cardNum = new char[strlen(cardNum_) + 1];
    strcpy(cardNum, cardNum_);

    budget = -2.00;
}
BankAccount::BankAccount(const BankAccount &obj) {
    strcpy(name, obj.name);
    strcpy(cardNum, obj.cardNum);
    budget = obj.budget;
}
BankAccount& BankAccount::operator=(const BankAccount &obj) {
    
    if (this != &obj) {
        if (name != nullptr) {
            delete[] name;
        }
        if (cardNum != nullptr) {
            delete[] cardNum;
        }

        name = new char[strlen(obj.name) + 1];
        cardNum = new char[strlen(obj.cardNum) + 1];

        strcpy(this->name, obj.name);
        strcpy(this->cardNum, obj.cardNum);
        this->budget = obj.budget;

    }

    return *this;
}
BankAccount::~BankAccount() {
    delete[] name;
    delete[] cardNum;
    //budget = 0;
}
void BankAccount::printAccount() const {
    std::cout << "\nBank Account information: \n";
    std::cout << "Holder: " << name << '\n';
    std::cout << "Card number: " << cardNum << '\n';
    std::cout << "Balance: " << budget << '\n';
}
void BankAccount::payIn(size_t sum) {
    budget += sum;
    std::cout << "\nA sum of "<< sum << " deposited successfully.\n";
}
void BankAccount::withdrawSum(size_t sum) {
    if (sum >= budget) {
        std::cout << "\nDraw request exceeds card's balance. Draw unsuccsessfully.\n";
        return;
    }
    budget -= sum;
    std::cout << "\nA sum of " << sum << " drawn successfully.\n";
}
