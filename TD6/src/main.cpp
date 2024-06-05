#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include "node.hpp"

int main () {
    Node Node1 {5, nullptr, nullptr};
    Node1.insert(3);
    Node1.insert(7);
    Node1.insert(2);
    Node1.insert(4);
    Node1.insert(6);
    Node1.insert(8);
    Node1.insert(1);
    Node1.insert(9);
    Node1.insert(0);

    std::cout << "La hauteur de l'arbre est de " << Node1.height() << std::endl ;

    std::cout << "ordre infixe : ";
    Node1.display_infixe();
    std::cout << std::endl ;
    
    std::cout << "ordre prefixe : ";
    std::vector<const Node*> tab_nodes {Node1.prefixe()};
    for (auto &&node : tab_nodes)
    {
        std::cout << node->value << ", ";
    }
    std::cout<<std::endl;

    std::cout << "La valeur la plus petite est ";
    most_left(Node1.left);

    std::cout << "La somme des elements de l'arbre est egale a ";
    int sum {};
    for (auto &&node : tab_nodes)
    {
        sum += node->value ;
    }
    std::cout << sum << std::endl;
    
return 0;
}