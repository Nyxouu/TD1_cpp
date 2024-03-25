#include <iostream>
#include <vector>
#include <string>
#include "structure-de-donnee.hpp"



int main () {
std::string s {SaisieUtilisateur()};  
std::vector<std::string> tab = {split_string(s)}; //fais un tableau avec chaque caractere separer par un espace 
for(std::string str : tab){
    std::cout<< str << ", "; //affiche le tableau
}

for(std::string str : tab){
    std::cout << std::endl << is_floating(str);
}

std::cout << std::endl << npi_evaluate(tab);


}