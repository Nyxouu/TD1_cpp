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
    Fraction const& f1bis = {              //pour mettre f1 sur le même dénominateur que f2
        f1.numerator*f2.denominator,
        f1.denominator*f2.denominator
    };
    Fraction const& f2bis = {              //pour mettre f2 sur le même dénominateur que f1
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


// Fraction operator+= (Fraction & f1, Fraction const& f2){
//     Fraction const& f1bis = {              //pour mettre f1 sur le même dénominateur que f2
//         f1.numerator*f2.denominator,
//         f1.denominator*f2.denominator
//     };
//     Fraction const& f2bis = {              //pour mettre f2 sur le même dénominateur que f1
//         f2.numerator*f1.denominator,
//         f2.denominator*f1.denominator
//     };
//     f1.numerator = f1bis.numerator + f2bis.numerator;
//     f1.denominator = f1bis.denominator;
//     return (f1);
// }

// Fraction Fraction:operator+= (Fraction const& f1){  //il daut mettre sur le meme denominateur
//     numerator += f1.numerator;
//     denominator += f1.denominator;
//     return *this;
// }


float to_float (Fraction const& f){
    float numeratorteurToFloat {static_cast<float>(f.numerator)};
    float denominatorToFloat {static_cast<float>(f.denominator)};
    float fractionToFloat {static_cast<float>(numeratorteurToFloat/denominatorToFloat)};
    return (fractionToFloat);
}

//Fraction::operator float() const 






