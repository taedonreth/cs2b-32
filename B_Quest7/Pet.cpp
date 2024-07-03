// Student ID: 20586501
// Pet.cpp
// 2B-BlueLab-06

#include <iostream>
#include <sstream>
#include <vector>
#include "Pet.h"

using namespace std;

// This is a way to properly initialize (out-of-line) a static variable.
size_t Pet::_population = 0;

Pet::Pet(string name, long id, int num_limbs) {
    _name = name;
    _id = id;
    _num_limbs = num_limbs;
    _population++;
}

Pet::~Pet() {
    _population--;
}

string Pet::get_name() const {
    return _name; 
}

long Pet::get_id() const {
    return _id;
}

int Pet::get_num_limbs() const {
    return _num_limbs;
}

bool Pet::set_name(string name) {
    if (name.empty()) {
        return false;
    }

    _name = name;
    return true;
}

bool Pet::set_id(long id) {
    if (id < 0) {
        return false;
    }

    _id = id;
    return true;
}

bool Pet::set_num_limbs(int num_limbs) {
    if (num_limbs < 0) {
        return false;
    }

    _num_limbs = num_limbs;
    return true;
}
//"(Name: [NAME], ID: [ID], Limb Count: [NUMBER OF LIMBS])"
string Pet::to_string() const {
    ostringstream result;

    result << "(Name: " << get_name() << ", ID: " << get_id() << ", Limb Count: " << get_num_limbs() << ")";
    return result.str();
}

// Fill in the supplied pets vector with n pets whose
// properties are chosen randomly.
// Don't mess with this method more than necessary.
void Pet::get_n_pets(size_t n, std::vector<Pet>& pets, int name_len) {

    pets.resize(n);
    long prev_id = 0;
    for (size_t i = 0; i < n; i++) {
        long id = prev_id + 1 + rand() % 10;
        pets[i].set_id(id);
        pets[i].set_num_limbs(rand() % 9); // up to arachnids
        pets[i].set_name(make_a_name(name_len));
        prev_id = id;
    }
}

// ---------------------------------------------------------------------

string Pet::make_a_name(int len) {

    string vowels =  "aeiou";
    string consonants = "bcdfghjklmnpqrstvwxyz";
    string name = "";
    if (len > 0) {
        if (rand() % 2 == 0) {
            name +=  consonants[rand() % consonants.length()];

            for (int i = 1; i < len; i++) {
                if (i % 2 == 1) {
                    name += vowels[rand() % vowels.length()];
                } else {
                    name += consonants[rand() % consonants.length()];
                }
            }
        } else {
            name += vowels[rand() % vowels.length()];

            for (int i = 1; i < len; i++) {
                if (i % 2 == 1) {
                    name +=  consonants[rand() % consonants.length()];
                } else {
                    name += vowels[rand() % vowels.length()];
                }
            }
        }
    }
    return name;
}

// Global helpers
/*return true if and only if an object's
components are each equal to the corresponding components of the object to which it is being
compared. */

bool operator==(const Pet& pet1, const Pet& pet2) {
    if (pet1.get_name() == pet2.get_name() && pet1.get_id() == pet2.get_id() && pet1.get_num_limbs() == pet2.get_num_limbs()) {
        return true;
    }
    return false;
}

bool operator!=(const Pet& pet1, const Pet& pet2) {
    if (pet1 == pet2) {
        return false;
    }
    return true;
}

ostream& operator<<(ostream& os, const Pet& pet) {
    os << pet.to_string();
    return os;
}