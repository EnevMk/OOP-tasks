#ifndef VECTORS_HPP
#define VECTORS_HPP
#include <iostream>

template <typename T>
T determinantRow2(T matrix[][2]) {

    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

template <typename T>
struct TupleOf3 {

    T e1;
    T e2;
    T e3;

    TupleOf3(T e1_, T e2_, T e3_) {
        e1 = e1_;
        e2 = e2_;
        e3 = e3_;
    }
    friend std::ostream& operator<<(std::ostream &os, const TupleOf3 &obj) {
        os << "coordinates: (" << obj.e1 << ", " << obj.e2 << ", " << obj.e3 << ")\n";
        return os;
    }

    friend TupleOf3<T>* vector_multiplication(const TupleOf3<T> &obj1, const TupleOf3<T> &obj2) {
        T m1[][2] = {{obj1.e2, obj1.e3}, {obj2.e2, obj2.e3}};
        T m2[][2] = {{obj1.e3, obj1.e1}, {obj2.e3, obj2.e1}};
        T m3[][2] = {{obj1.e1, obj1.e2}, {obj2.e1, obj2.e2}};

        TupleOf3<T>* res = new TupleOf3(determinantRow2(m1), determinantRow2(m2), determinantRow2(m3));
        return res;
    }
};
//explicit instantiation

template class TupleOf3<int>;
template class TupleOf3<double>;
/* 
int main() {

    TupleOf3<int> a(1, 2, 3);
    TupleOf3<int> b(3, 4, 7);

    TupleOf3<int> *c = vector_multiplication(a, b);

    std::cout << *c;

    delete c;
    return 0;
} */
#endif