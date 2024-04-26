#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <unordered_map>
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

//EXERCICE 2
std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}
std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes){
    std::unordered_map<std::string, std::vector<float>> final_list_cost {};
    for (int i{}; i<robots_fixes.size(); i++){
        if ( final_list_cost.find(robots_fixes[i].first) != final_list_cost.end() ){ //le nom du robot est deja dans la map
            final_list_cost[robots_fixes[i].first].push_back(robots_fixes[i].second); //rajoute simplement la nvlle valeur du cout dans le vector de float
        }
        else {
            final_list_cost[robots_fixes[i].first] = {robots_fixes[i].second};
        }
    }
    return (final_list_cost);
}

int cost_sum (std::vector<float> vec){
    int sum {};
    for (int i{}; i<vec.size();i++){
        sum+vec[i];
    }
    return (sum);
}

int main () {
//EXERCIE 1
std::cout << std::endl << folding_string_hash("bonjourrr", 100);
std::cout << std::endl << folding_string_ordered_hash("bonjourrr", 100);
std::cout << std::endl << polynomial_rolling_hash("bonjourrr", 3, 100);

//EXERCICE 2
std::vector<std::pair<std::string, float>> const& robots_fixes = {get_robots_fix(100)};
std::vector<float> vec {1.,3.,4.};
std::cout << std::endl << "la somme des valeurs du vecteurs est egale a " << cost_sum(vec);
}