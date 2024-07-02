// Student ID: 20586501
// Etox.cpp
// 2B-GreenLab-02

#include <iostream>
#include <sstream>
#include <cmath> // needed for sqrt
#include <cstdlib> // for exit()

using namespace std;

double etox_5_terms(double x) {
    
    double result = 1 + x + pow(x, 2)/2 + pow(x, 3)/6 + pow(x, 4)/24;
    return result;

}

int main(int argc, char **argv) {
    string user_input;
    double x;

    cout << "Enter a value for x: ";
    getline(cin, user_input);
    istringstream(user_input) >> x;

    cout << etox_5_terms(x) << endl;


    return 0;
}