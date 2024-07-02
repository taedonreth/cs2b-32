// Student ID: 20586501
// Limerick.cpp
// 2B-BlueLab-02

#include <iostream>
#include <sstream> // Need this for istringstream below
#include <cmath> // needed for sqrt
#include <cstdlib> // for exit()

using namespace std;

double eval_limerick(int dozen, int gross, int score) {

    double lhs = ((dozen + gross + score) + (3 * sqrt(4))) / 7 + (5 * 11);
    return lhs;

}


int main(int argc, char **argv) {

    int dozen, gross, score;

    if (argc < 4) {
        cerr << "Usage: limerick dozen-val gross-val score-val\n";
        exit(1);
    }

    istringstream(argv[1]) >>dozen;
    istringstream(argv[2]) >>gross;
    istringstream(argv[3]) >>score;

    // Invoke the eval_limerick function correctly and print the result
    // with a single newline at the end of the line.
    // TODO - Your code here (just invoke your function with the above
    // values for its params. Don't worry about argc, etc. for now)

    cout << eval_limerick(dozen, gross, score) << endl;

    return 0;
}