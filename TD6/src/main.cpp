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
    Node Node1 {50, nullptr, nullptr};
    Node1.insert(30);
    Node1.insert(80);
    //Node1.insert(20);


    Node1.display_infixe();
    std::cout<<std::endl;
    std::vector<const Node*> tab_nodes {Node1.prefixe()};
    for (auto &&node : tab_nodes)
    {
        std::cout << node->value << ", ";
    }
    std::cout<<std::endl;
    most_left(Node1.left);

    
return 0;
}