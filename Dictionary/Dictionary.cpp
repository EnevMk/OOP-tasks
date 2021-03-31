#include <iostream>
#include "Dictionary.hpp"

std::ostream& operator<<(std::ostream &out, String obj);

Dictionary::Dictionary() {
    //dict = nullptr;
    //count = 0;
}
Dictionary::Dictionary(const Vector<String> &words_, const Vector<String> &defs_) {
    for (int i = 0; i < words_.size(); ++i) {
        Definition df;
        df.word = words_[i];
        df.definition = defs_[i];
        
        v.push(df);
    }
}

Dictionary::Dictionary(const Dictionary &obj) {
    v = obj.v;

}

Dictionary& Dictionary::operator=(const Dictionary &obj) {
    if (this != &obj) {
        v = obj.v;
    }
    return *this;
}

const Vector<Definition>& Dictionary::getVector() const {
    return v;
}

void Dictionary::printAll() const {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i].word << " - " << v[i].definition << '\n';
    }
}

void Dictionary::include(const Definition &obj) {
    v.push(obj);
    //count++;
}

void Dictionary::remove(const String word_) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].word == word_) {
            v.removeAtIndex(i);
        }
    }
    //count--;
}

Definition Dictionary::getMeaning(const String word_) const {

    Definition def;
    for (int i = 0; i < v.size(); ++i) {

        if (v[i].word == word_) {
        
            def.word = word_;
            def.definition = v[i].definition;

            return def;
        }
    }
    def.word = word_;
    def.definition = "NOT FOUND";

    return def;
}


std::ostream& operator<<(std::ostream &out, String obj) {
    
    out << obj.getStr();

    return out;
}

Dictionary Dictionary::operator+(const Dictionary &obj) const {
    
    Dictionary res = *this;

    res.v.reserve(this->v.maxCapacity() + obj.v.maxCapacity());
    
    int startInd = res.v.size();
    int endInd = res.v.size() + obj.v.size();
    
    for (int i = startInd; i < endInd; ++i) {
        //res.v[i] = obj.v[i - startInd];
        res.v.push(obj.v[i - startInd]);
    }

    for (int i = 0; i < endInd - 1; ++i) {
        
        for (int j = 1; j < endInd; ++j) {

            if (res.v[i].word == res.v[j].word && i != j) {
                res.v[i].definition = res.v[i].definition + res.v[j].definition;
                res.v.removeAtIndex(j);
            }
        }
    }
    
    return res;
}

Dictionary& Dictionary::operator+=(const Dictionary &obj) {
    *this = *this + obj;
    return *this;
}