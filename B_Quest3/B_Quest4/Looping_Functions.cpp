// Student ID: 20586501
// Looping_Functions.cpp
// 2B-BlueLab-04

#include <iostream>
#include <sstream>

using namespace std;

// Give the user 6 chances to guess the secret number n (0-10). If they get it,
// say so and return true. Else say so and return false.
bool play_game(int n) {
    string user_input;
    int user_num;

    cout << "Welcome to my number guessing game\n\n\n";

    for (int i = 1; i < 7; i++) {
        cout << "Enter your guess: ";
        getline(cin, user_input);
        istringstream(user_input) >> user_num;
        cout << "You entered: " << user_num << endl;

        if (user_num == n) {
            cout << "You found it in " << i << " guess(es).\n";
            return true;
        }
    }

    cout << "\n";
    cout << "I'm sorry. You didn't find my number.\n";
    cout << "It was " << n;
    return false;
}

// Calculate e^x using the series summation up to exactly the first
// n terms including the 0th term.
double etox(double x, size_t n) {
    double sum = 1.0;
    double power = 1.0;
    double factorial = 1.0;
    
    //calculate exponent, then factorial, then divide them and add it to the sum to accumulate for next iteratoion
    for (size_t i = 1; i < n; i++) {
        power *= x;
        factorial *=  i;
        sum += (power / factorial);
    }

    return sum;
}

// Return the number of occurrences of char c in string s
size_t count_chars(string s, char c) {
    size_t num = 0;

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            num++;
        }
    }
    return num;
}

// Use Euclid's algorithm to calculate the GCD of the given numbers
size_t gcd(size_t a, size_t b) {
    while (b != 0) {
        size_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Return a string of the form n1,n2,n3,... for the given AP.
string get_ap_terms(int a, int d, size_t n) {
    int accumulator = a;
    string result = to_string(a) + ",";
    for (size_t i = 0; i < n - 2; i++) {
        accumulator += d;
        result += to_string(accumulator) + ",";
    }
    result += to_string(accumulator + d);
    return result;
}

// Return a string of the form n1,n2,n3,... for the given GP.
string get_gp_terms(double a, double r, size_t n) {
    double accumulator = a;
    string result = to_string(a) + ",";
    for (size_t i = 0; i < n - 2; i++) {
        accumulator *= r;
        result += to_string(accumulator) + ",";
    }
    result += to_string(accumulator * r);
    return result;
}

double get_nth_fibonacci_number(size_t n) {
    double sum = 0.0;
    double num1 = 1.0;
    double num2 = 1.0;

    if (n == 0) {
        return 0;
    }

    if (n == 1 || n == 2) {
        return 1;
    }

    for (int i = 3; i <= n; i++) {
        sum = num1 + num2;
        num1 = num2;
        num2 = sum; 
    }
    return sum;
}