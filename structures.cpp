#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};
double dist(const Point &A, const Point &B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
void inputPoint(Point &pt) {
    std::cout << "X-axis: ";
    std::cin >> pt.x;
    std::cout << "Y-axis: ";
    std::cout << pt.y;
}
void inputArr(Point *arr,const int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "\nEnter data about point " << i + 1 << ": \n";
        inputPoint(arr[i]);
    }
    std::cout << "\nPoints data saved!";
}
double longestDist(const Point *arr, const int n) {

    double longestDist_ = 0;
    for (int i = 0; i < n - 1; ++i) {

        for (int j = i + 1; j < n; ++j) {

            double curr = dist(arr[i], arr[j]);
            if (curr > longestDist_) {
                longestDist_ = curr;
            }
        }
    }
    return longestDist_;
}

int main() {
    Point a = {4, 2};
    Point b = {8, 2};
    std::cout << dist(a, b);
    return 0;
}