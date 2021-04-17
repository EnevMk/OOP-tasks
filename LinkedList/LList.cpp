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
LList<T>::LList(T *ptr, size_t size_) {
    
    first = nullptr;

    for (int i = size_ - 1; i >= 0; --i) {
        push(ptr[i]);
    }
}

template <typename T>
typename LList<T>::box* LList<T>::copy(box *pt) const {
    if (pt == nullptr) return pt;

    box *copied = new box{pt->data, copy(pt->next)};
    return copied;
}

template <typename T>
LList<T>::LList(const LList<T> &obj) {

    first = copy(obj.first);
}

template <typename T>
LList<T>& LList<T>::operator=(const LList<T> &obj) {
    if (this != &obj) {

        box *crr = first;

        while (crr != nullptr) {
            box *temp = crr->next;
            delete crr;
            crr = temp;
        }

        first = copy(obj.first);

    }
    return *this;
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
bool LList<T>::insertAt(size_t i, const T &data_) {

    if (i == 1 || i == 0) {
        push(data_);
        return true;
    }

    //box *ptr = first;
    size_t cnt = 1;
    size_t size_ = this->size();
    
    if (size_ < i) i == size_ + 1;

    box *ptr = locate(i-1);
    
    box *temp = ptr->next;
    ptr->next = new box{data_, temp};
    
    return true;
}

template <typename T>
T LList<T>::getAt(size_t i) const {
    box *crr = locate(i);

    assert(crr != nullptr);

    return crr->data;
}

template <typename T>
void LList<T>::pop() {
    box* temp;
    temp = first->next;

    delete first;
    first = temp;
}

template <typename T>
bool LList<T>::removeAt(size_t i) {

    if (i == 1) {
        pop();
        return true;
    }
    box *pred = locate(i-1);
    
    box *toBeDeleted = pred->next;
    pred->next = toBeDeleted->next;

    delete toBeDeleted;
    return true;

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