#pragma once

class BankAccount {
private:    
    char *name;
    char *cardNum;
    double budget;
    bool validateCardNum(char*);
public:
    char* getName() const;
    const char* getCardNum() const;
    double getBudget() const;
    BankAccount();
    BankAccount(const char *name_, const char *cardNum_);
    BankAccount(const BankAccount &obj);
    BankAccount& operator=(const BankAccount &obj);
    ~BankAccount();
    void printAccount() const;
    void withdrawSum(size_t sum);
    void payIn(size_t sum);
};
