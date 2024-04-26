#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

//EXERCICE 1:
size_t folding_string_hash(std::string const& s, size_t max){
    int hash {};
    for (int i{}; i<s.size(); i++){
        hash+=s[i];
    }
    return (hash%max);
};
size_t folding_string_ordered_hash(std::string const& s, size_t max){
    int hash {};
    for (int i{}; i<s.size(); i++){
        hash+=s[i]*(i+1);
    }
    return (hash%max);
};
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    int hash {};
    int power {1};
    for (int i{}; i<s.size(); i++){
        hash+=s[i]*power;
        power*=p;
    }
    return (hash%m);
};


int main () {
//EXERCIE 1
std::cout << std::endl << folding_string_hash("bonjourrr", 100);
std::cout << std::endl << folding_string_ordered_hash("bonjourrr", 100);
std::cout << std::endl << polynomial_rolling_hash("bonjourrr", 3, 100);
}