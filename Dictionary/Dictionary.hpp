#pragma once
#include "String.hpp"
#include "Vector.hpp"
struct Definition {
    String word;
    String definition;
};

class Dictionary {

private:
    //Definition dict[100];
    Vector<Definition> v;
    //int count;

public:
    Dictionary();
    Dictionary(const Vector<String> &words_, const Vector<String> &defs_);
    Dictionary(const Dictionary &obj);
    Dictionary& operator=(const Dictionary &obj);
    const Vector<Definition>& getVector() const;
    void printAll() const;
    void include(const Definition &obj);
    void remove(const String word_);
    Definition getMeaning(const String word) const;
    void printAllSorted() const;
    Dictionary operator+(Dictionary &obj) const;
    Dictionary& operator+=(const Dictionary &obj);

};