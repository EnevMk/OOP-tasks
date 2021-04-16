#include <iostream>
#include <cassert>
#include "LList.hpp"

template class LList<int>;

template <typename T>
LList<T>::LList():first(nullptr) {

}

template <typename T>
void LList<T>::push(const T &data_) {

    first = new box{data_, first};
}

template <typename T>
typename LList<T>::box* LList<T>::locate(size_t i) const {
    box* crr = first;
    
    if (i > this->size()) return nullptr;

    i--;
    while (i != 0) {
        i--;
        crr = crr->next;
    }

    return crr;

}

template <typename T>
size_t LList<T>::size() const {

    box *crr = first;
    size_t cnt = 0;

    while (crr != nullptr) {
        cnt++;
        crr = crr->next;
    }

    return cnt;
}

template <typename T>
void LList<T>::insertAt(size_t i, const T &data_) {
    
    //box *ptr = first;
    size_t cnt = 1;
    size_t size_ = this->size();
    
    if (size_ < i) i == size_;

    box *ptr = locate(i-1);
    
    box *temp = ptr->next;
    ptr->next = new box{data_, temp};
    
}

template <typename T>
T LList<T>::getAt(size_t i) const {
    box *crr = locate(i);

    assert(crr != nullptr);

    return crr->data;
}

template <typename T>
void LList<T>::removeAt(size_t i) {
    box *pred = locate(i-1);
    
    box *toBeDeleted = pred->next;
    pred->next = toBeDeleted->next;

    delete toBeDeleted;

}

template <typename T>
LList<T>::~LList() {
    box *crr = first;

    while (crr != nullptr) {
        box *temp = crr->next;
        delete crr;
        crr = temp;
    }
}