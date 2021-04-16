//#define CATCH_CONFIG // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"

#include <iostream>
#include "LList.hpp"

TEST_CASE("testing push") {

    LList<int> l;

    CHECK(l.size() == 0);

    l.push(3);
    l.push(5);
    l.push(7);
    CHECK(l.size() == 3);
}

TEST_CASE("testing insertAt") {
    LList<int> test;
    
    test.push(3);
    test.push(5);
    test.push(7);

    test.insertAt(2, 11); // 3, 11, 5, 7
    test.insertAt(5, 19);
    CHECK(test.size() == 5);
    
}

TEST_CASE("testing getAt") {
    LList<int> test;

    test.push(3);
    test.push(5);
    test.push(7);

    test.insertAt(2, 11); // 3, 11, 5, 7
    test.insertAt(5, 19); //3 11 5 7 19
    CHECK(test.size() == 5);

    CHECK(test.getAt(5) == 19);
    CHECK(test.getAt(2) == 11);


}

TEST_CASE("testig removeAt") {
    LList<int> test;

    test.push(3);
    test.push(5);
    test.push(7);

    test.insertAt(2, 11); // 3, 11, 5, 7
    test.insertAt(5, 19); //3 11 5 7 19
    CHECK(test.size() == 5);

    CHECK(test.getAt(5) == 19);
    CHECK(test.getAt(2) == 11);

    test.removeAt(2); // 3 5 7 19
    CHECK(test.getAt(2) == 5);
}
/* int main() {
    LList<int> l;

    

    l.push(3);
    l.push(5);
    l.push(7);

    std::cout << (l.size() == 3);

    return 0;
} */