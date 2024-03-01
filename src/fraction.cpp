#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// void Fraction::display() {
//     std::cout << numerator << "/" << denominator;
// }
std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator ;
}



// Fraction add(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }
Fraction operator+ (Fraction const& f1, Fraction const& f2){
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }


// Fraction sub(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }
Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

// Fraction mul(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }
Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

// Fraction div(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }
Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}


bool operator==(Fraction const& f1, Fraction const& f2) {
    if(f1.numerator*f2.denominator == f1.denominator*f2.numerator){
        return true;
    }
    else{
        return false;
    };
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1==f2);
}

bool operator<(Fraction const& f1, Fraction const& f2) {
    Fraction const& f1bis = {
        f1.numerator*f2.denominator,
        f1.denominator*f2.denominator
    };
    Fraction const& f2bis = {
        f2.numerator*f1.denominator,
        f2.denominator*f1.denominator
    };

    if (f1bis.numerator < f2bis.numerator){
        return true;
    }
    else{
        return false;
    }
}


bool operator<=(Fraction const& f1, Fraction const& f2) {
    if (f1<f2 || f1==f2){
        return true;
    }
    else{
        return false;
    }
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    if (!(f1<=f2)){
        return true;
    }
    else{
        return false;
    }
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    if (!(f1<=f2) || f1==f2){
        return true;
    }
    else{
        return false;
    }
}




