#include "Vectors.hpp"
#include "CD.hpp"

int main() {

    TupleOf3<int> v1(3, -2, 7);
    TupleOf3<int> v2(5, 1, -4);

    TupleOf3<int> *v3 = vector_multiplication(v1, v2);
    std::cout << *v3;
    
    CD d1("HP", 12, 1, 7);
    d1 += 3600;
    d1 -= 800;
    d1.print();

    return 0;
}