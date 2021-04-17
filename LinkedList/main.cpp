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
    test.insertAt(1, 23); //23 3 11 5 7 19
    CHECK(test.size() == 6);
    
}

TEST_CASE("testing getAt") {
    LList<int> test;

    test.push(3);
    test.push(5);
    test.push(7);// 7 5 3

    test.insertAt(2, 11); // 7 11 5 3
    test.insertAt(5, 19); //7 11 5 3 19
    //test.insertAt(1, 23); // 23 7 11 5 3 19
    CHECK(test.size() == 5);

    CHECK(test.getAt(5) == 19);
    CHECK(test.getAt(4) == 3);
    CHECK(test.getAt(3) == 5);
    CHECK(test.getAt(2) == 11);
    CHECK(test.getAt(1) == 7);


}

TEST_CASE("testig removeAt") {
    LList<int> test;

    test.push(3);
    test.push(5);
    test.push(7);

    test.insertAt(2, 11); // 7 11 5 3
    test.insertAt(5, 19); // 7 11 5 3 19
    CHECK(test.size() == 5);

    CHECK(test.getAt(5) == 19);
    CHECK(test.getAt(2) == 11);

    test.removeAt(2); // 3 5 7 19
    CHECK(test.getAt(2) == 5);
    test.removeAt(1);
    CHECK(test.getAt(1) == 5);
    //CHECK(test.first->next->next->data == 19);
}

TEST_CASE("testing copy ctr") {
    LList<int> test;

    test.push(3);
    test.push(5);
    test.push(7); // 7 5 3

    test.insertAt(2, 11); // 7 11 5 3
    test.insertAt(5, 19); // 7 11 5 3 19
    CHECK(test.size() == 5);

    CHECK(test.getAt(5) == 19);
    CHECK(test.getAt(2) == 11);

    test.removeAt(2); // 7 5 3 19
    CHECK(test.getAt(2) == 5);
    test.removeAt(1);
    CHECK(test.getAt(1) == 5); // 5 3 19

    LList<int> t2 = test;
    CHECK(t2.getAt(1) == 5);
    CHECK(t2.getAt(2) == 3);
    CHECK(t2.getAt(3) == 19);

    CHECK(test.getAt(1) == 5);
    CHECK(test.getAt(2) == 3);
    CHECK(test.getAt(3) == 19);
}

TEST_CASE("testing assignment operator") {

    LList<int> test;

    test.push(3);
    test.push(5);
    test.push(7); // 7 5 3

    test.insertAt(2, 11); // 7 11 5 3
    test.insertAt(5, 19); // 7 11 5 3 19
    CHECK(test.size() == 5);

    CHECK(test.getAt(5) == 19);
    CHECK(test.getAt(2) == 11);

    test.removeAt(2); // 7 5 3 19
    CHECK(test.getAt(2) == 5);
    test.removeAt(1);
    CHECK(test.getAt(1) == 5); // 5 3 19
    
    LList<int> t3;
    t3.push(22);
    t3.push(16);
    t3.push(8);

    CHECK(t3.getAt(1) == 8);
    CHECK(t3.getAt(2) == 16);
    CHECK(t3.getAt(3) == 22);

    t3 = test;

    CHECK(t3.getAt(1) == 5);
    CHECK(t3.getAt(2) == 3);
    CHECK(t3.getAt(3) == 19);

    CHECK(t3.size() == 3);

}

TEST_CASE("testing param ctr") {
    int arr[] = {6, 8, 10};
    LList<int> linkedList(arr, 3);

    CHECK(linkedList.getAt(1) == 6);
    CHECK(linkedList.getAt(2) == 8);
    CHECK(linkedList.getAt(3) == 10);

    linkedList.insertAt(1, 4);
    linkedList.insertAt(4, 9); //4 6 8 9 10

    CHECK(linkedList.size() == 5);
    CHECK(linkedList.getAt(4) == 9);
}
/* 
int main() {
    LList<int> l;

    l.push(3);
    l.push(5);
    l.push(7); // 7 5 3

    std::cout << (l.size() == 3);

    l.insertAt(3, 17); // 7 5 17 3
    std::cout << (l.getAt(3) == 17);
    std::cout << (l.size() == 4);

    l.removeAt(1);
    std::cout << (l.getAt(1) == 5);
    std::cout << (l.getAt(2) == 17);
    std::cout << (l.getAt(3) == 3);
    return 0;
} */