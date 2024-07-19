// Student ID: 20586501
// Complex.cpp
// 2B-GreenLab-05

#include "Complex.h"
#include <cstdio>
#include <stdexcept>

std::string Complex::to_string() const {
    char buf[64];
    std::sprintf(buf, "(%.11g,%.11g)", _real, _imag);
    return std::string(buf);
}

Complex Complex::reciprocal() const {
    double denom = norm_squared();
    if (denom < Complex::FLOOR) {
        throw Div_By_Zero_Exception();
    }
    return Complex(_real / denom, -_imag / denom);
}

Complex& Complex::operator=(const Complex& rhs) {
    if (this != &rhs) {
        _real = rhs._real;
        _imag = rhs._imag;
    }
    return *this;
}

Complex Complex::operator+(const Complex& rhs) const {
    return Complex(_real + rhs._real, _imag + rhs._imag);
}

Complex Complex::operator-(const Complex& rhs) const {
    return Complex(_real - rhs._real, _imag - rhs._imag);
}

Complex Complex::operator*(const Complex& rhs) const {
    return Complex(_real * rhs._real - _imag * rhs._imag,
                   _real * rhs._imag + _imag * rhs._real);
}

Complex Complex::operator/(const Complex& rhs) const {
    return *this * rhs.reciprocal();
}

bool Complex::operator==(const Complex& rhs) const {
    return (_real == rhs._real) && (_imag == rhs._imag);
}

bool Complex::operator<(const Complex& rhs) const {
    return norm() < rhs.norm();
}

std::ostream& operator<<(std::ostream& os, const Complex& x) {
    os << x.to_string();
    return os;
}
