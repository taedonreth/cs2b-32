// Student ID: 20586501
// Branching-Functions.cpp
// 2B-BlueLab-03

#include <iostream>

double mean_of_3(int n1, int n2, int n3);
int max_of_5(int n1, int n2, int n3, int n4, int n5);
int min_of_5(int n1, int n2, int n3, int n4, int n5);
bool sides_make_triangle(int a, int b, int c);
bool angles_make_triangle(int A, int B, int C);
bool is_a_leap_year(int year);


// This function returns the mean the three numbers passed
// in as parameters. Note that the mean may not be a round
// number. So you must use the double datatype for it.
double mean_of_3(int n1, int n2, int n3) {

    double avg = (n1 + n2 + n3) / 3.0;
    return avg;
}

// This function returns the maximum of the 5 given numbers
int max_of_5(int n1, int n2, int n3, int n4, int n5) {

    int arr[5] = {n1, n2, n3, n4, n5};
    int largest = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

// This function returns the minimum of the 5 given numbers
int min_of_5(int n1, int n2, int n3, int n4, int n5) {

    int arr[5] = {n1, n2, n3, n4, n5};
    int smallest = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    return smallest;
}

// Given three lengths, this function should return whether they can be the
// sides of some triangle. The heuristic you code should check if the
// sum of the two smallest sides is greater than or equal to the third side.
// Treat extreme cases as valid triangles. E.g. a+b == c means valid triangle.
// The challenge is to do it without using arrays
bool sides_make_triangle(int a, int b, int c) {

    int max = a;

    if (b >= a && b >= c) {
        max = b;
    }

    if (c >= a && c >= b) {
        max = c;
    }

    if (max == a && (b + c >= max)) {
        return true;
    } else if (max == b && (a + c >= max)) {
        return true;
    } else if (max == c && (a + b >= max)) {
        return true;
    }

    return false;

}

// Given three angles as integer degrees, this function should return whether
// they can be internal angles of some triangle. Treat extreme cases as
// valid triangles. E.g. (0, 0, 180) is a valid triangle
bool angles_make_triangle(int A, int B, int C) {

    if (A + B + C == 180) {
        return true;
    }

    return false;
}

// Return true if the year yyyy is a leap year and false if not.
bool is_a_leap_year(int yyyy) {

    if ((yyyy % 4 == 0) && (yyyy % 100 != 0)) {
        return true;
    }

    if (yyyy % 100 == 0) {
        if ((yyyy % 4 == 0) && (yyyy % 400 == 0)) {
            return true;
        }
    }

    return false;
}