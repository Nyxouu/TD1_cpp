#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;
};

std::ostream& operator<<(std::ostream& os, Fraction const& f);

//Fraction add(Fraction const& f1, Fraction const& f2);
Fraction operator+ (Fraction const& f1, Fraction const& f2);
//Fraction sub(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
// Fraction mul(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
// Fraction div(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);
bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);
Fraction operator+= (Fraction & f1, Fraction const& f2);
Fraction operator-= (Fraction & f1, Fraction const& f2);
Fraction operator*= (Fraction & f1, Fraction const& f2);
Fraction operator/= (Fraction & f1, Fraction const& f2);
float to_float (Fraction const& f);