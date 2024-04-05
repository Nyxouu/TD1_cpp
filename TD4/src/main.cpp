#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


int main () {

//EXERCICE 1
int saisie_utilisateur {};
std::cout << std::endl << "entrez un nombre :";
std::cin >> saisie_utilisateur ; 

std::vector<int> tab_random_num {};
int rand {std::rand()%100 +1};
for (int i{}; i<rand; i++){
    int rand_i {std::rand()%100 +1};
    tab_random_num.push_back(rand_i);
}

for (auto it { tab_random_num.begin() }; it !=tab_random_num.end(); ++it) {
    std::cout << *it << std::endl;
}


//on cherche si le nb entre par l'utilisateur est dans le tableau
auto it { std::find(tab_random_num.begin(), tab_random_num.end(), saisie_utilisateur) };

if (it >= tab_random_num.end())
{
   std::cout << "L'element est introuvable" << std::endl;
}
else {
    std::cout << "L'element est dans le tableau" << std::endl;
    //fonction count pour faire le compte du nb
    std::cout << "On trouve " << count(tab_random_num.begin(), tab_random_num.end(), saisie_utilisateur) << " fois le nombre "<< saisie_utilisateur<<std::endl;
}

//Tri du vecteur tab_random_num
std::sort(tab_random_num.begin(), tab_random_num.end());
std::cout << "le tableau trie est :"<< std::endl ;
for (int k{}; k<tab_random_num.size() ;k++ ) {
    std::cout << tab_random_num[k] << std::endl;
}

//somme des elements
int sum { std::accumulate(tab_random_num.begin(), tab_random_num.end(), 0, [](int acc, int current_element) { return acc + current_element; }) };
std::cout << "somme des elements : " << sum << std::endl;
    
}


