#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = "<< f1;
    //f1.display();
    std::cout << " f2 = "<< f2;
    //f2.display();
    std::cout << std::endl;

    //Fraction f3 { add(f1, f2) };
    Fraction addf1f2 {f1 + f2};
    Fraction subf1f2 {f1 - f2};
    Fraction mulf1f2 {f1 * f2};
    Fraction divf1f2 {f1 / f2};
    
    //std::cout << "add(f1, f2) = ";
    //f3.display();

    // std::cout << std::endl << "sub(f1, f2) = ";
    // (sub(f1, f2)).display();
    std::cout << std::endl << "f1-f2 = "<< f1 - f2;
    //subf1f2.display();

    // std::cout << std::endl << "mul(f1, f2) = ";
    // (mul(f1, f2)).display();
    std::cout << std::endl << "f1*f2 = "<< f1 * f2;
    //mulf1f2.display();

    // std::cout << std::endl << "div(f1, f2) = ";
    // (div(f1, f2)).display();
    std::cout << std::endl << "f1/f2 = "<< f1 / f2;
    //divf1f2.display();

    //std::cout << std::endl << "add(1/6, 2/6) = ";
    //(add({1, 6}, {2, 6})).display();
    std::cout << std::endl << "f1+f2 = "<< f1 + f2 ;
    //addf1f2.display();

    if (f1==f2){
        std::cout << std::endl << f1 << " et "<< f2 << " sont egales.";
    }
    if (f1!=f2){
        std::cout << std::endl << f1 << " et "<< f2 << " sont differentes.";
    }
    if (f1<f2){
        std::cout << std::endl << f1 << " est inferieur a "<< f2 ;
    }
    if (f1<=f2){
        std::cout << std::endl << f1 << " est inferieur ou egale a "<< f2 ;
    }
    if (f1>f2){
        std::cout << std::endl << f1 << " est superieur a "<< f2 ;
    }
    if (f1>=f2){
        std::cout << std::endl << f1 << " est superieur ou egale a "<< f2 ;
    }

    std::cout << std::endl << "f1+=f2 : "<< (f1+=f2) ;
    std::cout << std::endl << "f1-=f2 : "<< (f1-=f2) ;
    std::cout << std::endl << "f1*=f2 : "<< (f1*=f2) ;
    std::cout << std::endl << "f1/=f2 : "<< (f1/=f2) ;
    std::cout << std::endl << f1 << " = " << to_float(f1);


    return 0;
}