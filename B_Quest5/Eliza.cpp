// Student ID: 20586501
// Eliza.cpp
// 2B-BlueLab-05

#include <iostream>
#include <sstream>

using namespace std;

// Return a new string in which the letters (lowercase) a, e, i, o, and u
// have been replaced by the next vowel in the sequence aeiou. Replace u by a.
// Note that the string is passed in by reference. So the caller may not
// rely on the result being returned.
string rotate_vowels(string& s) {
    char arr[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    for (size_t i = 0; i < s.length(); i++) {
        for (int j = 0; j < 10; j++) {
            if (s[i] == arr[j]) {
                if (j % 2 == 0) {
                    s[i] = arr[(j + 2) % 10];
                } else {
                    s[i] = arr[(j + 2) % 10];
                }
                break;
            }
        }
    }
    return s;
}


// Return a string in which all occurrences of s have been replaced by th

string lispify(string s) {
    ostringstream result;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == 's') {
            result << "th";
        } else if (s[i] == 'S') {
            result << "Th";
        } else {
            result << s[i];
        }
    }
    return result.str();
}

// Enter the user-interaction loop as described earlier
void enter() {

    std::cout << "What?" << endl;
    while (true) {

        bool restartloop = false;
        string user_input;
        getline(cin, user_input);
        if (user_input.empty()) {
            std::cout << "What?";
            continue;
        }
        std::cout << "    " << user_input << "\n\n";

        if (user_input.find("bye") != string::npos || user_input.find("Bye") != string::npos || user_input.find("Bye") != string::npos || user_input.find("Quit") != string::npos) {
            std::cout << "Ok Bye. Nice being a force of change in your life." << endl;
            break;
        }
        
        for (size_t i = 0; i < user_input.length(); i++) {
            if (user_input[i] == '!') {
                std::cout << "OMG! You don't say!! " << user_input << "!!!!!" << endl;
                restartloop = true;
                break;
            }
        }

        if (restartloop) {
            continue;
        }

        if (user_input.find("why") != string::npos || user_input.find("what") != string::npos) {
            std::cout <<  "I'm sorry, I don't like questions that contain what or why." << endl;
            continue;
        }

        for (size_t i = 0; i < user_input.length(); i++) {
            if (user_input[i] == 's' || user_input[i] == 'S') {
                std::cout << "Interethting. When did you thtop thtopping your thibilanth?" << endl;
                std::cout << lispify(user_input) << "! Sheesh! Now what?" << endl;
                restartloop = true;
                break;
            }
        }

        if (restartloop) {
            continue;
        }

        int num = rand() % 10;
        if (num == 8 || num == 9) {
            std::cout << "Huh? Why do you say: " << user_input << "?" << endl;
        } else {
            std::cout << rotate_vowels(user_input) << "?" << endl;
        }
        continue;
    }
}