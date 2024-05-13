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

    Node1.display_infixe();
    std::cout<<std::endl;
    Node1.prefixe();
    std::cout<<std::endl;
    Node1.postfixe();
    
return 0;
}