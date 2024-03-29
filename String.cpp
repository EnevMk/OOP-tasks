#include <iostream>
#include "String.hpp"

int strLen(const char *str_);
void strCpy(char *dest, const char *src);
int strCmp(const char *str1, const char *str2);

String::String() {
    std::cout << "default ctor called\n";
    str = nullptr;
}
String::String(const char *str_) {
    std::cout << "ctor called\n";
    str = new char[strLen(str_) + 1];
    strCpy(str, str_);
}

String::String(const String &obj) {
    std::cout << "copy ctor called\n";
    str = new char[strLen(obj.str) + 1];
    strCpy(str, obj.str);
}

String::String(String&& obj) {
    std::cout << "move constructor called\n";
    this->str = obj.str;
    obj.str = nullptr;
}

String& String::operator=(String&& obj) {
    std::cout << "move operator= called\n";
    if (this == &obj) return *this;
    delete this->str;

    this->str = obj.str;
        obj.str = nullptr;

    return *this;
}

String& String::operator=(const String &obj) {
    std::cout << "copy assignment operator called\n";
    if (this != &obj) {
        delete[] str;
        str = new char[strLen(obj.str) + 1];
        strCpy(str, obj.str);
    }
    return *this;
}

String::~String() {
    
    if (str) {
        std::cout << "destructor called\n";
        delete[] str;
    }
    str = nullptr;
}

bool String::operator==(const String &obj) {
    return !strCmp(str, obj.str);
}

void String::toLower() {
    for (int i = 0; i < strLen(str); ++i) {
        (this->str[i] >= 'A' && this->str[i] < 'Z') ? str[i] += 'a' - 'A' : 1;
    }
}

String String::operator+(const String &obj) {
    std::cout << "in + oper\n";
    String res;
    int resultSize = this->size() + obj.size() + 1;
    res.str = new char[resultSize];/* 
    std::cout << "\nrazmeri: \n" << this->size() << ' ' << obj.size() <<'\n';
    std::cout << "\n\ntest -- " << this->getStr() << "\n\n"; */
    strCpy(res.str, this->str);
    /* 
    res.str[this->size()] = '.';
    res.str[this->size() + 1] = ' '; */
    strCpy((res.str + this->size()), obj.str);
    res.str[resultSize] = '\0';

    return res;
}

int String::size() const {
    return strLen(str);
}

char* String::getStr() const {
    return str;
}

void String::setStr(const char *str_) {
    delete[] str;
    str = new char[strLen(str_) + 1];
    strCpy(str, str_);
}

std::ostream& operator<<(std::ostream& os, const String &obj) {
    os << obj.str;
    return os;
}

int strLen(const char *str_) {
    int i;
    for (i = 0; *(str_ + i) != '\0'; ++i) {

    }
    return i;
}

void strCpy(char *dest, const char *src) {
    int i = 0;
    for (i = 0; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

int strCmp(const char *str1, const char *str2) {
    int i;
    for (i = 0; str1[i] == str2[i] && (str1[i] != '\0' && str2[i] != '\0'); ++i) {

    }

    if (str1[i] == '\0' && str2[i] == '\0') return 0;

    return (str1[i] - str2[i] < 0) ? -1 : 1;
}
